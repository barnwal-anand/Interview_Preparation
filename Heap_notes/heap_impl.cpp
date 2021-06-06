#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
      void createMaxHeap(vector<int> &arr);
      void insertMaxHeap(vector<int> &arr, int ele);
      void deleteMaxHeap(vector<int> &arr);
      void maxHeapify(vector<int> &arr, int index);

      void printArray(vector<int> arr) {
            for (int it = 0; it < arr.size(); it++)
                  cout << arr[it] << " ";
            cout << endl;
      }
};

void Heap::createMaxHeap(vector<int> &arr)
{
      int it = (arr.size() - 1) / 2; // last non leaf node
      for (; it >= 0; it--) {
            maxHeapify(arr, it);
      }
}

void Heap::maxHeapify(vector<int> &arr, int index)
{
      int lIndex = 2*index + 1;
      int rIndex = 2*index + 2;
      int largestIndex = index;

	if (lIndex < arr.size() && arr[lIndex] > arr[largestIndex])
	     largestIndex = lIndex;
      if (rIndex < arr.size() && arr[rIndex] > arr[largestIndex])
            largestIndex = rIndex;

      if (largestIndex != index) {
            swap(arr[largestIndex], arr[index]);
            maxHeapify(arr, largestIndex);
      }
}

void shiftUp(vector<int> &arr, int index)
{
      if (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (arr[index] > arr[parentIndex]) {
                  swap(arr[index], arr[parentIndex]);
                  shiftUp(arr, parentIndex);
            }
      }
}
void Heap::insertMaxHeap(vector<int> &arr, int ele)
{
      int newIndex = arr.size();

      arr.resize(newIndex + 1);
      arr[newIndex] = ele;
      shiftUp(arr, newIndex);
}

void Heap::deleteMaxHeap(vector<int> &arr)
{
      int size = arr.size();

      arr[0] = arr[size - 1];
      arr.resize(size - 1);
      maxHeapify(arr, 0);
}

int main(void) {
      vector<int> arr{1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
      Heap obj;

      obj.printArray(arr);
      obj.createMaxHeap(arr);
      obj.printArray(arr);

	obj.insertMaxHeap(arr, 16);
	obj.printArray(arr);

	obj.deleteMaxHeap(arr);
	obj.printArray(arr);

      return 0;
}
