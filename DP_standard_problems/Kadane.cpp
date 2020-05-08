// Largest Sum Contiguous Subarray

#include <iostream>
#include <climits>
using namespace std;

class Kadane {
private:
      int *arr;
      int size;

public:
      Kadane(int size);
      void getLargestSum(int &res, int &start, int &end);
};

Kadane::Kadane(int size) {
      this->size = size;
      arr = new int[size]{-2, -3, 4, -1, -2, 1, 5, -3};
}

void Kadane::getLargestSum(int &res, int &start, int &end) {
      int cur_max = 0;
      int max_res = INT_MIN;
      start = 0, end = 0;
      int tmp_start = 0;

      for(int it = 0; it < size; it++) {
            cur_max += arr[it];
            if(cur_max < 0) {
                  cur_max = 0;
                  tmp_start = it + 1;
            }
            else if(cur_max > max_res){
                  max_res = cur_max;
                  start = tmp_start;
                  end = it;
            }
      }
      res = max_res;
}

int main() {
      Kadane kadaneObj(8);
      int start, end, res;
      kadaneObj.getLargestSum(res, start, end);
      cout << res << endl;
}
