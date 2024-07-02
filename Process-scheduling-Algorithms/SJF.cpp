#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct process{
    int id;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
    bool completed;

    //constructor for process
    process(int _id, int _arrival, int _burst) : id(_id) ,arrival(_arrival), burst(_burst)
    , completed(false) {}
};


int sjf(vector<process> &processes){
    int currenttime = 0;
    process* currentproc = NULL;
    int min_burst;
    for(int i = 0; i < processes.size(); i++){
        min_burst = INT32_MAX;
        for(int j = 0; j < processes.size(); j++){
            if(processes[j].arrival <= currenttime && min_burst > processes[j].burst && !processes[j].completed){
                min_burst = processes[j].burst;
                currentproc = &processes[j];
            }
        }

        if(currenttime < currentproc->arrival)
            currenttime = currentproc->arrival;
        
        currenttime += currentproc->burst;
        currentproc->completion = currenttime;
        currentproc->turnaround = currenttime - currentproc->arrival;
        currentproc->waiting = currentproc->turnaround - currentproc->burst;
        currentproc->completed = true;
    }

    cout << "Id\tAT\tBT\tCT\tTAT\tWT\n";
    for(process &p : processes){
        cout << p.id << "\t" << p.arrival << "\t" << p.burst << "\t" << p.completion << "\t"
        << p.turnaround << "\t" << p.waiting << "\n";
    }
}

int main(){

    int n;
    cout << "Enter num of processes: ";
    cin >> n;

    vector<process> processes;
    processes.reserve(n);

    int arr, burst;
    for(int i = 0; i < n; i++){
        cout << "Enter process " << i << " arrival and burst time: ";
        cin >> arr >> burst;
        processes.emplace_back(i,arr,burst);
    }
    sjf(processes);
}