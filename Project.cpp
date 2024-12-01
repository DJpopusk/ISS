#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

const int MAX_RESULT_DOCUMENT_COUNT = 5;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {    
    int result = 0;
    cin >> result;
    
    ReadLine();
    return result;
}

vector<string> SplitIntoWords(const string& text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

struct Document {
    int id;
    double relevance; // Изменяем тип релевантности на double
};

struct Query {
    set <string> plus_words;
    set <string> min_words;
};

class SearchServer {
public:
    int document_count_ = 0;
    
    void SetStopWords(const string& text) {
        for (const string& word : SplitIntoWords(text)) {//
            stop_words_.insert(word);
        }
    }

    void AddDocument(int document_id, const string& document) {
        const vector<string> words = SplitIntoWordsNoStop(document);
        const int size = words.size();
        double TF_counter = 1. / size;
        
        for (const auto& word : words) {        
            word_to_document_freqs_ [word][document_id] += TF_counter;
        }
    }

    vector<Document> FindTopDocuments(const string& raw_query) const {
        Query query_words = ParseQuery(raw_query);
        auto matched_documents = FindAllDocuments(query_words);

        sort(matched_documents.begin(), matched_documents.end(),
             [](const Document& lhs, const Document& rhs) {
                 return lhs.relevance > rhs.relevance;
             });
        if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
            matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
        }
        return matched_documents;
    }

private:
    map<string, map<int, double>> word_to_document_freqs_; // Структура для хранения TF каждого слова в каждом документе
    set<string> stop_words_;

    bool IsStopWord(const string& word) const {
        return stop_words_.count(word) > 0;
    }

    vector<string> SplitIntoWordsNoStop(const string& text) const {
        vector<string> words;
        
        for (const string& word : SplitIntoWords(text)) {//
            if (!IsStopWord(word)) {
                words.push_back(word);
            }
        }
        return words;
    }

    Query ParseQuery(const string& text) const {
        Query query_words;

        for (const string& word : SplitIntoWordsNoStop(text)) {
            if (word[0] == '-' && !IsStopWord(word)) {
                query_words.min_words.insert(word.substr(1));
            }
            else if (!IsStopWord(word)) {
                query_words.plus_words.insert(word);
            }
        }

        return query_words;
    }

    double IDFCount (const string& word) const {
        return log(static_cast<double>(document_count_) / word_to_document_freqs_.at(word).size());
    }

    vector<Document> FindAllDocuments(const Query query_words) const {
        map<int, double> document_to_relevance;
        vector<Document> matched_documents;
        double line_IDF;
        
        for (const auto& word : query_words.plus_words) {
            if (word_to_document_freqs_.count(word) > 0) {
                line_IDF = IDFCount (word);
                for (const auto& [docs_id, tf] : word_to_document_freqs_.at(word)) {
                     document_to_relevance[docs_id] += word_to_document_freqs_.at(word).at(docs_id) * line_IDF;
                }
            }
        }

        for (const auto& word : query_words.min_words) {
            if (word_to_document_freqs_.count(word) > 0) {
                for (const auto& [docs_id, tf] : word_to_document_freqs_.at(word)) {
                    document_to_relevance.erase(docs_id);
                }
            }
        }
        

        // Преобразуем результат в вектор для сортировки и возврата топ N документов
        for (const auto& [doc_id, relevance] : document_to_relevance) {
            //нелевую релевантность, 
                matched_documents.push_back({doc_id, relevance});
            
        }
        return matched_documents;
    }
};

SearchServer CreateSearchServer() {
    SearchServer search_server;
    search_server.SetStopWords(ReadLine());

    const int document_count = ReadLineWithNumber();    
    search_server.document_count_ = document_count;
    
    for (int document_id = 0; document_id < document_count; ++document_id) {
        search_server.AddDocument(document_id, ReadLine());
    }

    return search_server;
}

int main() {
    const SearchServer search_server = CreateSearchServer();

    const string query = ReadLine();
    for (const auto& [document_id, relevance] : search_server.FindTopDocuments(query)) {
        cout << "{ document_id = "s << document_id << ", "
             << "relevance = "s << relevance << " }"s << endl;
    }
    return 0;
}
