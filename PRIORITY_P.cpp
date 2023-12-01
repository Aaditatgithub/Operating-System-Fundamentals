#include<iostream>
#include<vector>
using namespace std;

struct process {
    int id;
    int priority;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
    int response;
    int remaining;
    bool completed;


    process(int _id, int _priority, int _arrival, int _burst) : id(_id), priority(_priority), arrival(_arrival),
        burst(_burst), waiting(0), turnaround(0), response(-1), remaining(_burst), completed(false) {}
};

void priority_p(vector<process>& processes) {
    int currenttime = INT32_MAX;

    for (int i = 0; i < processes.size(); i++) {
        if (processes[i].arrival < currenttime)
            currenttime = processes[i].arrival;
    }

    int completedprocesses = 0;
    process* currentproc;
    int maxpriority = INT32_MAX;

    while (completedprocesses < processes.size()) {
        currentproc = NULL;
        maxpriority = INT32_MAX;

        for (int i = 0; i < processes.size(); i++) {
            if (!processes[i].completed && processes[i].arrival <= currenttime && maxpriority > processes[i].priority) {
                maxpriority = processes[i].priority;
                currentproc = &processes[i];
            }
        }
        if (currentproc == NULL) {
            currenttime++;
        }
        else {
            if (currentproc->response == -1)
                currentproc->response = currenttime - currentproc->arrival;

            currenttime++; // Increment current time for each unit of time

            if (currentproc->remaining > 0) {
                currentproc->remaining--;

                if (currentproc->remaining == 0) {
                    currentproc->completion = currenttime;
                    currentproc->turnaround = currenttime - currentproc->arrival;
                    currentproc->waiting = currentproc->turnaround - currentproc->burst;
                    currentproc->completed = true;
                    completedprocesses++;
                }
            }
        }
    }

    cout << "Id\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (process& p : processes) {
        cout << p.id << "\t" << p.arrival << "\t" << p.burst << "\t" << p.completion << "\t"
            << p.turnaround << "\t" << p.waiting << "\t" << p.response << "\n";
    }
}


int main() {
    int n;
    cout << "Number of processes: ";
    cin >> n;

    vector<process> processes;
    processes.reserve(n);

    int arr, burst, priority;
    for (int i = 0; i < n; i++) {
        cout << "Enter priority, arrival, burst for process " << i << " : ";
        cin >> priority >> arr >> burst;
        processes.emplace_back(i, priority, arr, burst);
    }

    priority_p(processes);
}