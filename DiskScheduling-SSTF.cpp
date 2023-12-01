#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

int find_closest_request(const vector<int>& requests, int current_position) {
    int min_distance = numeric_limits<int>::max();
    int closest_request = -1;

    for (int request : requests) {
        int seek_distance = abs(request - current_position);
        if (seek_distance < min_distance) {
            min_distance = seek_distance;
            closest_request = request;
        }
    }

    return closest_request;
}

int sstf_disk_scheduling(vector<int>& requests, int initial_position) {
    int total_seek_time = 0;
    int current_position = initial_position;

    while (!requests.empty()) {
        int closest_request = find_closest_request(requests, current_position);
        total_seek_time = abs(closest_request - current_position);
        current_position = closest_request;

        // Remove the serviced request from the list
        vector<int>::iterator it = find(requests.begin(), requests.end(), closest_request);
        if (it != requests.end()) {
            requests.erase(it);
        }
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

    int seek_time = sstf_disk_scheduling(requests, initial_position);
    cout << "Total seek time using SSTF: " << seek_time << endl;

    return 0;
}
