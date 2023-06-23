#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    int id;
    int deadline;
    int duration;
};

bool compareTasks(const Task& task1, const Task& task2) {
    return task1.deadline < task2.deadline;
}

std::vector<int> scheduleTasks(std::vector<Task>& tasks) {
    std::sort(tasks.begin(), tasks.end(), compareTasks);

    int n = tasks.size();
    std::vector<int> schedule(n, -1);  // Vector para almacenar el orden de ejecución de las tareas
    std::vector<bool> slot(n, false);  // Vector para controlar los slots de tiempo ocupados

    for (int i = 0; i < n; i++) {
        for (int j = std::min(n, tasks[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                schedule[j] = tasks[i].id;
                slot[j] = true;
                break;
            }
        }
    }

    return schedule;
}

void printSchedule(const std::vector<int>& schedule) {
    std::cout << "Orden de ejecución de las tareas: ";
    for (int task : schedule) {
        std::cout << task << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Task> tasks = { {1, 5, 2}, {2, 2, 1}, {3, 4, 3}, {4, 3, 2}, {5, 7, 1} };

    std::vector<int> schedule = scheduleTasks(tasks);
    printSchedule(schedule);

    return 0;
}
