class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = -1;
        
        int l = 0;
        int r = heights.size() - 1;
        while (l < r) {
            int base = r - l;
            int minheight = min(heights[l], heights[r]);
            int area = base * minheight;
            
            maxarea = max(maxarea, area);

            if (heights[l] < heights[r]) {
                l++;
            } else { 
                r--;
            }
        }

        return maxarea;
    }
};
