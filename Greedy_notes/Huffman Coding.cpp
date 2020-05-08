#include <iostream>
#include <queue>
using namespace std;

class MinHeapNode
{
public:
	char data;
	int frequency;
	MinHeapNode *left, *right;

      MinHeapNode(char ch, int freq): data(ch), frequency(freq)
      {
            left = NULL;
            right = NULL;
      }
};

class Comparator {
	public:
	bool operator()(MinHeapNode *l, MinHeapNode *r)
	{
		return (l->frequency > r->frequency);
	}
};

void PrintCodes(MinHeapNode *minHeapRoot, string res)
{
	if(minHeapRoot == NULL)
		return;
	if(minHeapRoot->data != '$')
	{
		cout << minHeapRoot->data << " " << res << endl;
	}
	PrintCodes(minHeapRoot->left, res + "0");
	PrintCodes(minHeapRoot->right, res + "1");
}

void HuffmanCodes(char arr[], int freq[], int size)
{
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, Comparator> minHeap;

	for(int it = 0; it < size; it++) {
		minHeap.push(new MinHeapNode(arr[it], freq[it]));
	}

	while(minHeap.size() != 1) {
		MinHeapNode *left = minHeap.top();
		minHeap.pop();

		MinHeapNode *right = minHeap.top();
		minHeap.pop();

		MinHeapNode *top = new MinHeapNode('$', left->frequency + right->frequency);

		top->left = left;
		top->right = right;
		minHeap.push(top);
	}

	PrintCodes(minHeap.top(), "");
}

int main()
{

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	HuffmanCodes(arr, freq, size);

	return 0;
}
