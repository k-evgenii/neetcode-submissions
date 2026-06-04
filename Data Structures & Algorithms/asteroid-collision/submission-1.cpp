class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        st.reserve(asteroids.size());

        for (int current : asteroids) {
            bool alive = true;

            while (
                alive &&
                !st.empty() &&
                st.back() > 0 &&
                current < 0
            ) {
                if (st.back() < -current) {
                    st.pop_back();
                }
                else if (st.back() == -current) {
                    st.pop_back();
                    alive = false;
                }
                else {
                    alive = false;
                }
            }

            if (alive) {
                st.push_back(current);
            }
        }

        return st;
    }
};