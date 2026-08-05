#include <bits/stdc++.h>
using namespace std;

int main()
{
   // -------------------------------------------------------------------
   cout << "Now for Max Heap ----->" << endl;

   priority_queue<int> pq1;   // default = max heap

   pq1.push(10);
   pq1.push(4);
   pq1.push(2);
   pq1.push(-6);
   pq1.push(85);
   pq1.push(-15);

   cout << "Top element: " << pq1.top() << endl;  // 85

   pq1.pop();  // removes 85
   cout << "Top after one pop: " << pq1.top() << endl; // 10


   // -------------------------------------------------------------------
   cout << "\nNow for Min Heap ----->" << endl;

   priority_queue<int, vector<int>, greater<int>> pq2; // min heap

   pq2.push(10);
   pq2.push(4);
   pq2.push(2);
   pq2.push(-6);
   pq2.push(85);
   pq2.push(-15);
   pq2.push(-5);

   cout << "Top element: " << pq2.top() << endl; // -15

   pq2.pop(); // -15
   pq2.pop(); // -6
   pq2.pop(); // -5
   pq2.pop(); // 2

   cout << "Top after pops: " << pq2.top() << endl; // 4

   return 0;
}

/*
-------------------- PRIORITY QUEUE (HEAP) --------------------

👉 It is implemented using a Complete Binary Tree (CBT)
Definition:
A binary tree in which:
1. All levels are completely filled except possibly the last level
2. The last level is filled from left to right (no gaps)

--------------------------------------------------------------
👉 By default:
- C++  : Max Heap (largest element at top)
- Java : Min Heap (smallest element at top)

--------------------------------------------------------------
👉 Types of Heaps:

1. Max Heap:
   priority_queue<int> pq;
   - Top element is always the maximum

2. Min Heap:
   priority_queue<int, vector<int>, greater<int>> pq;
   - Top element is always the minimum

--------------------------------------------------------------
👉 Why use Priority Queue?

- To always access the largest or smallest element efficiently
- Common use cases:
  • Dijkstra’s Algorithm
  • Kth largest / smallest element
  • Heapsort
  • Sliding window problems

--------------------------------------------------------------
👉 Time Complexities:

Let n = number of elements in the heap

- top()  → O(1)
- push() → O(log n)   // insertion + heapify up
- pop()  → O(log n)   // deletion + heapify down
--------------------------------------------------------------
👉 Extra Points:

- Internally uses a dynamic array (vector in C++)
- Does NOT store elements in sorted order
- Only guarantees:
• top() = max (in max heap)
• top() = min (in min heap)

--------------------------------------------------------------
👉 tricks-->

- to find the kth smallest generally used max heap
- to find the kth largest  generally used min heap


*/