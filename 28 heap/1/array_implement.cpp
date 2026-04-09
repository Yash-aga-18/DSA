#include <bits/stdc++.h>
using namespace std;

// Implement the min-heap using array

// here we used 1-based indeexing for ease

class MinHeap {
public:
    vector<int> arr;

    MinHeap() {
        arr.push_back(-1); // dummy
    }

    int top() {
        if(arr.size() <= 1)     return -1;
        return arr[1];
    }
    
    int size() {
        if(arr.size() <= 1)     return 0;
        return arr.size() -1;
    }


    void push(int ele) {
        arr.push_back(ele);

        int i = arr.size() - 1;

        // heapify up
        while(i > 1) {
            int parent = i / 2;

            if(arr[parent] > arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } 

            else    break;
            
        }

    }

    void pop() {
        if(arr.size() <= 1) return;

        arr[1] = arr.back();
        arr.pop_back();

        int i = 1;                          // start from root
        int n = arr.size() - 1;             // total valid elements (ignore dummy at index 0)

        while (2 * i <= n) {                // loop while at least left child exists
            
            int left  = (2 * i) ;               // left child index
            int right = (2 * i) + 1;          // right child index
            int smallest = left;            // assume left child is smaller


            // check if right child exists and is smaller than left
            if (right <= n && arr[right] < arr[left]) {
                smallest = right;           // update smallest to right child
            }

            // if current node is greater than smallest child → swap
            if (arr[i] > arr[smallest]) {
                swap(arr[i], arr[smallest]);
                i = smallest;               // move down to that child
            } 
            
            else    break;                      // heap property satisfied → stop
            

        }


    }

};




int main() {
    
    MinHeap pq;

    // push elements
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(1);
    pq.push(6);

    cout << "Heap elements (level order): ";
    for(int i = 1; i < pq.arr.size(); i++) {
        cout << pq.arr[i] << " ";
    }
    cout << endl;

    cout << "Top element: " << pq.top() << endl;
    cout << "Size: " << pq.size() << endl;

    // pop elements one by one
    cout << "\nPopping elements:\n";
    while(pq.size() > 0) {
        cout << "Top: " << pq.top() << endl;
        pq.pop();
    }

    // final size check
    cout << "Final size: " << pq.size() << endl;

    return 0;
}