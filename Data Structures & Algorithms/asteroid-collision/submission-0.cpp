class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; 
        vector<int> result;

        for(int current : asteroids){
            bool alive{true};

            while(
                alive &&
                !st.empty() &&
                st.top() > 0 &&
                current < 0
            ){
                if(abs(st.top()) < abs(current)){
                    st.pop();
                }
                else if (abs(st.top()) == abs(current)){
                    st.pop();
                    alive = false;
                }
                else if(abs(st.top()) > abs(current)){
                    alive = false;
                }
            }
            if (alive == true){
                st.push(current);
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }       
        reverse(result.begin(), result.end());
         
        return result;
    }
};