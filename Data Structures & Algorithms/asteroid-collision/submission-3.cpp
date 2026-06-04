class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int k = 0; // size of our simulated stack inside asteroids

        for (int current : asteroids) {
            bool alive = true;

            while (
                alive &&
                k > 0 &&
                asteroids[k - 1] > 0 &&
                current < 0
            ) {
                if (asteroids[k - 1] < -current) {
                    k--; // top asteroid dies
                }
                else if (asteroids[k - 1] == -current) {
                    k--; // both die
                    alive = false;
                }
                else {
                    alive = false; // current dies
                }
            }

            if (alive) {
                asteroids[k] = current;
                k++;
            }
        }

        asteroids.resize(k);
        return asteroids;
    }
};