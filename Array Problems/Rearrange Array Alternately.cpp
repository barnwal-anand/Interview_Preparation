/*
Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively 
i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.

Input:
N = 6
arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3
*/

class Solution{
public:
    void rearrange(long long *arr, int n) 
    { 
    	int low = 0;
    	int high = n - 1;
    	int max_ele = arr[high] + 1;
    	
    	for (int it = 0; it < n; it++) {
    	    if (it % 2 == 0) {
    	        arr[it] += (arr[high] % max_ele) * max_ele;
    	        high--;
    	    }
    	    else {
    	        arr[it] += (arr[low] % max_ele) * max_ele;
    	        low++;
    	    }
    	}
    	
    	for (int it = 0; it < n; it++) {
    	    arr[it] = arr[it] / max_ele;
    	}
    }
};
