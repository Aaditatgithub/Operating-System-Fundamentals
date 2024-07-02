#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

void FIFO(vector<int> &references, int frames){
    queue<int> fifoQ;
    unordered_set<int> Frames(frames);
    int pageFaults {0};

    for(int page: references){
        if(Frames.find(page) == Frames.end()){
            if(Frames.size() == frames){
                int oldestpage = fifoQ.front();
                fifoQ.pop();
                Frames.erase(oldestpage);
                cout << "Page " << oldestpage << " was removed from memory.\n";
            }
            Frames.insert(page);
            fifoQ.push(page);
            pageFaults++;
            cout << "Page " << page << " was inserted in memory.\n";
        }
        else{
            cout << "Page " << page << " was already present in a frame." <<endl;
        }
    }
    cout << "Total page Faults: " << pageFaults << ".";
}

int main(){
    int frames;
    cout << "Enter number of page frames: ";
    cin >> frames;
    
    int n;
    cout << "Enter number of page references: ";
    cin >> n;

    vector<int> references(n);
    cout << "Enter references: ";
    for(int i = 0; i < n; i++){
        cin >> references[i];
    }
    FIFO(references, frames);
}