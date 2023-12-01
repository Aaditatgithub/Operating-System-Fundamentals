#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int findOptimal(vector<int> &references, map<int, int> &pageTable, int startIndex){
    int optimal = -1, farthest = -1;

    for(auto it = pageTable.end(); it != pageTable.begin(); it--){
        int page = it->first;
        int index = it->second;
        
        auto lastOccurence = find(references.rbegin(), references.rend() - startIndex, page);
        if(lastOccurence == references.rend() - startIndex){
            return page;
        }
        int farthestIndex = references.rend() - 1 - lastOccurence;
        if(farthestIndex > farthest){
            farthest = farthestIndex;
            optimal = page;
        }
    }
    return optimal;
}

void optimal(vector<int> &references, int num_frames){
    int pageFaults {0};
    map<int, int> pageTable;

    for(int i = 0; i < references.size(); i++){
        if(pageTable.find(references[i]) == pageTable.end()){
            if(pageTable.size() == num_frames){
                int optimal = findOptimal(references, pageTable, i);
                pageTable.erase(optimal);
                cout << "page " << optimal << " removed\n";
            }
            pageTable[references[i]] = i;
            pageFaults++;
            cout << "page " << references[i] << " added\n";
        }
    }
    cout << "Total page Faults: "<< pageFaults;
}

int main() {
    int n; 
    cout << "Number of page references: ";
    cin >> n;

    cout << "Enter page references: ";
    vector<int> references(n);
    for (int i = 0; i < n; i++) {
        cin >> references[i];
    }

    int frames;
    cout << "Enter number of frames: ";
    cin >> frames;
    optimal(references, frames);
}