/*
Given the arrival and departure times of all trains that reach a railway station, 
the task is to find the minimum number of platforms required for the railway station so that no train waits. 
We are given two arrays that represent the arrival and departure times of trains that stop.

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: Minimum 3 platforms are required to safely arrive and depart all trains.
*/

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);
        
        int ptr1 = 0;
        int ptr2 = 0;
        int res = 1;
        int count = 0;
        
        while(ptr1 < n && ptr2 < n) {
            if (arr[ptr1] <= dep[ptr2]) {
                count++;
                ptr1++;
            }
            else {
                count--;
                ptr2++;
            }
            res = max(res, count);
        }
        
        return res;
    }
};
