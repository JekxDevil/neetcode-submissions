class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // a cheaper buying price is always better
        int maxprofit = 0;
        int l = 0;
        int r = 1;
        while (r < prices.size()) {
            int buy = prices[l];
            int sell = prices[r];
            int profit = sell - buy;

            if (sell >= buy) {
                maxprofit = max(maxprofit, profit);
                r++;
            } else if (sell < buy) {
                l = r;  // can buy at lower price!
                r = l + 1;
            }
        }

        return maxprofit;
    }
};
