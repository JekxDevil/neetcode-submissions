class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        map<int, int, greater<int>> counter;
        for (int el : prices) { counter[el]++; }

        for (int i = 0; i < prices.size(); i++) {
            counter[prices[i]]--;
            if (counter[prices[i]] == 0) { counter.erase(prices[i]); }

            maxprofit = max(maxprofit, counter.begin()->first - prices[i]);
        }
        // for (int i = 0; i < prices.size(); i++) {
        //     for (int j = i + 1; j < prices.size(); j++) {
        //         maxprofit = max(maxprofit, prices[j] - prices[i]);
        //     }
        // }

        return maxprofit;
    }
};
