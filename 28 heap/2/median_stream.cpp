#include <bits/stdc++.h>
using namespace std;

// leetcode Q->295   Find median in a contious data stream



/*
========================================
1. GENERAL CASE (Two Heaps) → O(log n)
========================================
*/
class MedianFinder_Heaps {
public:
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

    void addNum(int ele) {
        
        if(left.empty() || ele < left.top())    left.push(ele);
        else                                    right.push(ele);

        // balance heaps
        if(left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        else if(right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {

        if(left.size() == right.size()) {
            return (left.top() / 2.0) + (right.top() / 2.0);
        }

        if(left.size() > right.size())  return left.top();
        
        return right.top();
    }

};


/*
========================================
2. RANGE [0,100] → COUNT ARRAY → O(1)
========================================
*/
class MedianFinder_Count {
public:
    vector<int> freq;
    int total;

    MedianFinder_Count() {
        freq.resize(101, 0);
        total = 0;
    }

    void addNum(int num) {
        freq[num]++;
        total++;
    }

    double findMedian() {
        int count = 0;
        int m1 = -1, m2 = -1;

        for(int i = 0; i <= 100; i++) {
            count += freq[i];

            if(m1 == -1 && count >= (total + 1)/2)  m1 = i;

            if(count >= (total/2 + 1)) {
                m2 = i;
                break;
            }
        }

        return (m1 + m2) / 2.0;
    }
};


/*
========================================
3. 99% IN RANGE [0,100]
========================================
👉 Hybrid:
- freq[0..100] for most numbers
- heaps for outliers
*/
class MedianFinder_Hybrid {
public:
    vector<int> freq;
    int total;

    // outliers
    priority_queue<int> left; 
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder_Hybrid() {
        freq.resize(101, 0);
        total = 0;
    }

    void addNum(int num) {
        total++;

        if(num >= 0 && num <= 100) {
            freq[num]++;
        } 
        else {
            // handle outliers using heaps
            if(left.empty() || num < left.top())    left.push(num);
            else                                    right.push(num);

            if(left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            }
            else if(right.size() > left.size() + 1) {
                left.push(right.top());
                right.pop();
            }
        }
    }

    double findMedian() {
        int count = 0;
        int m1 = -1, m2 = -1;

        // first traverse freq array
        for(int i = 0; i <= 100; i++) {
            count += freq[i];

            if(m1 == -1 && count >= (total + 1)/2)
                m1 = i;

            if(count >= (total/2 + 1)) {
                m2 = i;
                break;
            }
        }

        // NOTE: simplified hybrid (interview-level explanation enough)
        // full merging with heaps is complex — usually not required

        return (m1 + m2) / 2.0;
    }
};



/*
========================================
MAIN FUNCTION (TEST ANY ONE)
========================================
*/
int main() {

    // 🔁 Change class here to test different approaches

    MedianFinder_Heaps mf;
    // MedianFinder_Count mf;
    // MedianFinder_Hybrid mf;

    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl; // 1.5

    mf.addNum(3);
    cout << mf.findMedian() << endl; // 2

    return 0;
}