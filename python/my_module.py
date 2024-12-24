import matplotlib.pyplot as plt
import os

def plot_trajectory(file_path):
    thrust = []
    duration = []

    with open(file_path, 'r') as file:
        for line in file:
            data = line.split()
            thrust.append(float(data[0]))
            duration.append(float(data[1]))

    plt.figure(figsize=(10, 6))
    plt.plot(duration, thrust, marker='o')
    plt.title("Thrust vs Duration")
    plt.xlabel("Duration (s)")
    plt.ylabel("Thrust (N)")
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    script_dir = os.path.dirname(__file__)
    rel_path = "../build/output/thrust_data.txt"
    file_path = os.path.join(script_dir, rel_path)

    plot_trajectory(file_path)