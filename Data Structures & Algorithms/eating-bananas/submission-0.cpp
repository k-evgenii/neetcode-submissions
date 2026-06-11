class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxK = piles[0];
        long long maxH = 0;

        for (int pile : piles) {
            if (pile > maxK) {
                maxK = pile;
            }
            maxH += pile;
        }

        int minK = (maxH + h - 1) / h; // lower bound

        int leftK = minK;
        int rightK = maxK;
        int ans = maxK;

        while (leftK <= rightK) {
            int avK = leftK + (rightK - leftK) / 2;

            long long curH = 0;

            for (int pile : piles) {
                curH += (pile + avK - 1) / avK;
            }

            if (curH <= h) {
                ans = avK;
                rightK = avK - 1;
            } else {
                leftK = avK + 1;
            }
        }

        return ans;
    }
};