class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i{0};
        int j{n - 1};
        vector<int> ans;

        while(i < j){
            int value = numbers[i] + numbers[j];
            
            if(value == target){
                ans = {i + 1, j + 1};
                return ans;
            }

            else if( value < target){
                i++;
            } 
            
            else if( value > target){
                j--;
            } 
        }
    }
};
