    #include <iostream>
    #include <vector>
    #include <cmath>
    using namespace std;

    int fcfs_disk_scheduling(const vector<int>& requests, int initial_position) {
        int total_seek_time = 0;
        int current_position = initial_position;

        for (int request : requests) {
            total_seek_time += abs(request - current_position);
            current_position = request;
        }
        return total_seek_time;
    }

    int main() {

        int n;
        cout << "Enter the number of request positions for a process: ";
        cin >> n;

        vector<int> requests(n);
        for(int i = 0; i < n; i++){
            int ele;
            cin >> ele;
            requests[i] = ele;
        }
        int initial_position = 53;
        cout << "Enter initial position of head: ";
        cin >> initial_position;
        
        int seek_time = fcfs_disk_scheduling(requests, initial_position);
        cout << "Total seek time using FCFS: " << seek_time << endl;

        return 0;
    }
