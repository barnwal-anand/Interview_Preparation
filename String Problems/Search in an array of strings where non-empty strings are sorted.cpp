/*
Given an array of strings. The array has both empty and non-empty strings. All non-empty strings are in sorted order.
Empty strings can be present anywhere between non-empty strings.

Input :  arr[] =  {"for", "", "", "", "geeks",
                   "ide", "", "practice", "" ,
                   "", "quiz", "", ""};
          str = "quiz"
Output :   10
The string "quiz" is present at index 10 in
given array.
*/

#include <iostream>
using namespace std;

int searchStr(string arr[], int n, string key) {
	int l = 0;
	int h = n-1;

	while (l <= h) {
        int mid = (l + h) / 2;

		if (arr[mid] == "") {
			int left = mid - 1;
			int right = mid + 1;
			while (left >= l && arr[left] == "" &&
				   right <= h && arr[right] == "") {
				left--;
				right++;
			}

			if (arr[left] != "") {
				mid = left;
			}
			else if (arr[right] != "") {
				mid = right;
			}
		}

		if (key == arr[mid]) {
			return mid;
		}
		else if (key < arr[mid]){
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	return -1;
}

int main()
{
    string arr[] = {"ai", "", "", "bat", "", "", "car", "cat", "" , "", "dog", "e"};
	int n = 12;
    string key = "cat";
    cout << searchStr(arr, n, key);

    return 0;
}
