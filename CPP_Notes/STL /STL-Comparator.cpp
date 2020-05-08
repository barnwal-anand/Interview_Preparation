// vector comparator

// Sort elements by frequency. If two elements have same count, then put the elements that appears first
//input: arr[] = { 5, 2, 5, 6, -1, 9999999, 2, 8, 8, 8 }
//output: 8 8 8 5 5 2 2 6 -1 9999999

// Map m2 keeps track of indexes of elements in array
unordered_map<int, int> m2;

// Used for sorting by frequency. And if frequency is same, then by appearance
bool sortByVal(const pair<int, int>& a, const pair<int, int>& b)
{
	// If frequency is same then sort by index
	if (a.second == b.second)
		return m2[a.first] < m2[b.first];

      // sort in descending order with frequenct count
	return a.second > b.second;
}

// main function to sort elements by frequency
void sortByFreq(int arr[], int n)
{
	unordered_map<int, int> m;
	vector<pair<int, int> > v;

	for (int i = 0; i < n; ++i) {

		// Map m is used to keep track of count of elements in array
		m[arr[i]]++;

		// Update the value of map m2 only once
		if (m2[arr[i]] == 0)
			m2[arr[i]] = i + 1;
	}

	// Copy map to vector
	copy(m.begin(), m.end(), back_inserter(v));

	// Sort the element of array by frequency
	sort(v.begin(), v.end(), sortByVal);

	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < v[i].second; ++j)
			cout << v[i].first << " ";
}

// Another example: sort in ascending order
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
struct Interval
{
    int start, end;
};

Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
int n = sizeof(arr)/sizeof(arr[0]);

// sort the intervals in increasing order of start time
sort(arr, arr+n, compareInterval);
// Intervals sorted by start time: [1,9] [2,4] [4,7] [6,8]

// priority_queue comparator
