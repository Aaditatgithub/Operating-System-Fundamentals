#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

void lruPageReplacement(vector<int>& ref_string, int& capacity){
    int pageFaults {0};                                  // Counter for page faults
    list<int> pageList;                                 // learn about the lru page loaded in frames
    unordered_map<int, list<int>::iterator> pageTable;  // reps pages laoded

    for(int page : ref_string){
        if(pageTable.count(page) > 0){
            pageList.splice(pageList.begin(), pageList, pageTable[page]);
        }
        else{
            if(pageList.size() >= capacity){
                int lrupage = pageList.back();
                pageList.pop_back();
                pageTable.erase(lrupage);
                cout << "page " << lrupage << " was removed from memory." << endl;
            }
            pageList.push_front(page);
            pageTable[page] = pageList.begin();
            cout << "page " << page << " was added to memory" << endl;
            pageFaults++;
        }
    }
    cout << "Total number of page faults are: " << pageFaults << endl;
}

int main(){
    int num_frames, page_refs;
    cout << "Enter number of frames: ";
    cin >> num_frames;
    cout << "Enter number of references: ";
    cin >> page_refs;
    cout << "Enter reference string: ";

    vector<int> ref_string(page_refs);

    for(int i = 0; i < page_refs; i++){
        cin >> ref_string[i];
    }
    
    lruPageReplacement(ref_string, num_frames);
    return 0;
}