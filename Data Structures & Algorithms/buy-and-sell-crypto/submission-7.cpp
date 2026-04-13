class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices.front();
        int maxprofit = 0;

        for (int p : prices) {
            maxprofit = max(maxprofit, p-buy);
            buy = min(buy, p);
        }

        return maxprofit;
    }
};
