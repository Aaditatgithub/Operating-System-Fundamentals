#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>> &max, vector<vector<int>> &alloc, vector<int> &avail, int res_types, int process){
    vector<int> need(res_types);

    for(int i = 0; i < res_types; i++){
        need[i] = max[process][i] - alloc[process][i];
    }
    
    for(int i = 0; i < res_types; i++){
        if(need[i] > avail[i])
            return false;
    }
    return true;
}

int main(){
    int num_proc;
    cout << "Enter number of processes: ";
    cin >> num_proc;

    int res_types;
    cout << "Enter resource types: ";
    cin >> res_types;

    vector<vector<int>> alloc(num_proc,vector<int>(res_types,0));
    vector<vector<int>> max(num_proc,vector<int>(res_types,0));
    vector<int> avail(res_types);

    for(int i = 0; i < num_proc; i++){
        cout << "Enter resources allocated to process " << i << ": ";
        for(int j = 0; j < res_types; j++){
            cin >> alloc[i][j];
        }
    }

    for(int i = 0; i < num_proc; i++){
        cout << "Enter max resource usage of process " << i << ": ";
        for(int j = 0; j < res_types; j++){
            cin >> max[i][j];
        }
    }

    cout << "Enter number of resources: ";
    for(int i = 0; i < res_types; i++){
        cin >> avail[i];
    }

    int completed_processes {0};
    vector<int> safesequence;
    vector<bool> completed(num_proc,false);

    while(completed_processes < num_proc){
        bool found = false;
        for(int i = 0; i < num_proc; i++){
            if(!completed[i] && isSafe(max,alloc,avail,res_types,i)){
                
                for(int j = 0; j < res_types; j++){
                    avail[j] += alloc[i][j];
                }

                found = true;
                completed_processes++;
                completed[i] = true;
                safesequence.push_back(i);
            }
        }
        if(!found){
            cout << "Deadlock detected...";
            break;
        }
    }
    if(completed_processes == num_proc){
        cout << "Safe sequence: ";
        for(int &proc : safesequence)
            cout << proc << " ";
    }
}