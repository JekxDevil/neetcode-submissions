class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // a cheaper buying price is always better
        int maxprofit = 0;
        vector<int> cheapest(prices.size());
        vector<int> expensive(prices.size());

        cheapest[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            cheapest[i] = min(cheapest[i-1], prices[i]);
        }

        expensive.back() = prices.back();
        for (int i = prices.size() - 2; i >= 0; i--) {
            expensive[i] = max(expensive[i+1], prices[i]);
        }

        // maxprofit = max(0, expensive[0] - cheapest[0]);
        for (int i = 0; i < prices.size(); i++) {
            maxprofit = max(maxprofit, expensive[i] - cheapest[i]);
        }

        return maxprofit;
    }
};
