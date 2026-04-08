#include <bits/stdc++.h>
using namespace std;

//   find the kth smallest, largest   number from array

// leetcode Q->215  Return Kth largest number


int kthSmallest(vector<int>& arr, int k) {
    
    // max heap
    priority_queue<int> pq;

    for(int i = 0; i < arr.size(); i++) {
        
        pq.push(arr[i]);   // insert element

        // keep only k elements in heap
        if(pq.size() > k)       pq.pop();      // remove largest
         
    }

    // top is kth smallest
    return pq.top();
}



int kthLargest(vector<int>& arr, int k) {
    
    // min heap
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 0; i < arr.size(); i++) {
        
        pq.push(arr[i]);   // insert element

        // keep only k elements in heap
        if(pq.size() > k)       pq.pop();      // remove largest
        
    }

    // top is kth largsest
    return pq.top();
}



int main() {
    
    // vector<int> arr = {42, -7, 19, -88, 3, -56, 21, 90, -14, 67};
    vector<int> arr = {1,5,9,10,11,13,12,13,15};
    int k = 8;

    cout <<k << "th smallest element: " << kthSmallest(arr, k);
    cout<<endl;
    cout <<k << "th largest  element: " << kthLargest (arr, k);

    return 0;
}



/*
-------------------- KTH SMALLEST ELEMENT --------------------

👉 METHOD 1: Sorting (Built-in)

- Sort the array in ascending order
- Return arr[k-1]

Code Idea:
sort(arr.begin(), arr.end());
return arr[k-1];

Time Complexity  → O(n log n)
Space Complexity → O(1)

--------------------------------------------------------------

👉 METHOD 2: Selection Sort (Partial)

- Run selection sort only for first k elements
- After k iterations, kth smallest will be at index k-1

Time Complexity  → O(n * k)
Space Complexity → O(1)

Note: Better than full sort when k is small

--------------------------------------------------------------

👉 METHOD 3: Quick Select (Best Average)

- Based on QuickSort partition
- Only recurse into one side

Steps:
1. Pick pivot
2. Partition array
3. Check pivot index:
   - if index == k-1 → answer
   - if index > k-1 → go left
   - else → go right

Time Complexity  →
- Average: O(n)
- Worst:   O(n²)

Space Complexity →
- Average: O(log n) (recursion stack)
- Worst:   O(n)

--------------------------------------------------------------

👉 METHOD 4: Min Heap

- Insert all elements into min heap
- Pop k-1 elements
- Top = kth smallest

Time Complexity  →
- Build heap: O(n)
- Remove k elements: O(k log n)
→ Total: O(n + k log n)

Space Complexity → O(n)

--------------------------------------------------------------

👉 METHOD 5: Max Heap (BEST FOR LARGE n, SMALL k)

- Maintain max heap of size k
- Traverse array:
    • push element
    • if size > k → pop max

- At end → top = kth smallest

Time Complexity →
- Each insert: O(log k)
- Total: O(n log k)

Space Complexity → O(k)

👉 BEST when k << n

--------------------------------------------------------------

👉 SUMMARY:

| Method            | Time Complexity   | Space    |
|------------------|--------------------|-------   |
| Sorting          | O(n log n)         | O(1)     |
| Selection Sort   | O(n * k)           | O(1)     |
| Quick Select     | O(n) avg / O(n²)   | O(log n) |
| Min Heap         | O(n + k log n)     | O(n)     |
| Max Heap         | O(n log k)         | O(k)     |

--------------------------------------------------------------

👉 INTERVIEW TIP:

- Small k → use Max Heap
- Large n → avoid full sorting
- Best practical → Quick Select or Max Heap

--------------------------------------------------------------
*/