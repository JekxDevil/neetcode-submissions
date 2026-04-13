class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = -1;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = i + 1; j < heights.size(); j++) {
                int base = j - i;
                int minheight = min(heights[i], heights[j]);
                maxarea = max(maxarea, base * minheight);
            }
        }
        
        return maxarea;
    }
};
