/*
LeetCode: 295 Find Median from Data Stream
The median is the middle value in an ordered integer list.
If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far.

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]
*/

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
        }
        else {
            if (num < maxHeap.top()) {
                maxHeap.push(num);

                if (maxHeap.size() > minHeap.size() + 1) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }
            else {
                minHeap.push(num);
                if (minHeap.size() > maxHeap.size() + 1) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else if (maxHeap.size() > minHeap.size()) {
            return double(maxHeap.top());
        }
        else {
            return double(minHeap.top());
        }
    }
};
