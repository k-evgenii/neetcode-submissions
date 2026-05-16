class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        string ans;
        int m = min(n1, n2);

        for(int i{0}; i < m; i++){
            ans += word1[i];
            ans += word2[i];
        }
        if(n1 > n2){
            ans += word1.substr(m, n1 - m);
            }
        if(n1 < n2){
            ans += word2.substr(m, n2 - m); 
        }
        return ans;
    }
};