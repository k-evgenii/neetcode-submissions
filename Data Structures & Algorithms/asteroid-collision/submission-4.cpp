class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int k = 0;

        for (int x : asteroids) {
            if (x > 0) {
                asteroids[k++] = x;
            } 
            else {
                while (
                    k > 0 &&
                    asteroids[k - 1] > 0 &&
                    asteroids[k - 1] < -x
                ) {
                    k--;
                }

                if (k == 0 || asteroids[k - 1] < 0) {
                    asteroids[k++] = x;
                }
                else if (asteroids[k - 1] == -x) {
                    k--;
                }
                // else: asteroids[k - 1] > -x, so x dies
            }
        }

        asteroids.resize(k);
        return asteroids;
    }
};