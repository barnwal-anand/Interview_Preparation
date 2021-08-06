/*
Leetcode: 901 Online Stock Span
Write a class StockSpanner which collects daily price quotes for some stock,
and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (
starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
Explanation:
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.
*/

class StockSpanner {
private:
    stack<int> s;
    vector<int> stockPrice;
    int index;
public:
    StockSpanner() {
        index = 0;
    }

    int next(int price) {
        stockPrice.push_back(price);
        index++;
        int res = 0;

        if (s.empty()) {
            s.push(index);
            res = index;
        }
        else {
            while (!s.empty() && stockPrice[s.top()-1] <= price) {
                s.pop();
            }

            res = index - (s.empty() ? 0 : s.top());
            s.push(index);
        }

        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
