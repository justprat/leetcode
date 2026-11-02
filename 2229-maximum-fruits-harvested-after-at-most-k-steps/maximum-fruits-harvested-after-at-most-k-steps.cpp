class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

        int n = fruits.size();

        int left = 0;
        int currFruits = 0;
        int maxFruits = 0;
        
        for(int right = 0 ; right < n ; right++){

            currFruits += fruits[right][1];

            int posL = fruits[left][0];
            int posR = fruits[right][0];

            while (left <= right) {
                
                int posL = fruits[left][0];
                int posR = fruits[right][0];
                int steps = (posR - posL) + min(abs(startPos - posL), abs(startPos - posR));
                
                if (steps <= k) break;
                
                currFruits -= fruits[left][1];
                left++;
            }

            maxFruits = max(maxFruits,currFruits);

        }

        return maxFruits;
    }
};