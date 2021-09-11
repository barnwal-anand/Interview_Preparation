/*
Leetcode: 54 - Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/

class Solution {
public:
    enum direction {
        LtoR, RtoB, RtoL, BtoT 
    };
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> arr;
        int top = 0, bottom = r - 1, left = 0, right = c - 1;
        int index = 0;
        enum direction dir = LtoR;
        
        while(top <= bottom && left <= right) {
            if(dir == LtoR) {
                for(int it = left; it <= right; it++) {
                    arr.push_back(matrix[top][it]);
                }
                top++;
                dir = RtoB;
            }
            
            else if(dir == RtoB) {
                for(int it = top; it <= bottom; it++) {
                    arr.push_back(matrix[it][right]);
                }
                right--;
                dir = RtoL;;
            }
            
            else if(dir == RtoL) {
                for(int it = right; it >= left; it--) {
                    arr.push_back(matrix[bottom][it]);
                }
                bottom--;
                dir = BtoT;
            }
            
            else if(dir == BtoT) {
                for(int it = bottom; it >= top; it--) {
                    arr.push_back(matrix[it][left]);
                }
                left++;
                dir = LtoR;
            }
        }
    
        return arr;
    }
};
