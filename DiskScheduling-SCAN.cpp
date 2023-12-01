#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int scan_disk_scheduling(const vector<int>& requests, int initial_position, int max_track) {
    vector<int> left_requests, right_requests;
    int total_seek_time = 0;

    for (int request : requests) {
        if (request < initial_position) {
            left_requests.push_back(request);
        } else {
            right_requests.push_back(request);
        }
    }

    sort(left_requests.begin(), left_requests.end(), greater<int>());
    sort(right_requests.begin(), right_requests.end());

    for (const auto& request : {right_requests, left_requests}) {
        for (int r : request) {
            total_seek_time += abs(initial_position - r);
            initial_position = r;
        }
    }

    return total_seek_time;
}

int main() {
    
    int n {0};
    int max_track {199};
    int initial_position {53};

    cout << "Enter the number of request positions for a process: ";
    cin >> n;

     vector<int> requests(n);
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        requests[i] = ele;
    }

    cout << "Enter initial position of head: ";
    cin >> initial_position;
    
    cout << "Enter the max track: ";
    cin >> max_track;

    int seek_time = scan_disk_scheduling(requests, initial_position, max_track);
    cout << "Total seek time using SCAN (Elevator): " << seek_time << endl;
    return 0;
}
