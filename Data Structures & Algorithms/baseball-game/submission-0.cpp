class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        int sum{0};

        for(string op : operations){

            if(op == "+"){
                int last = scores.back();
                int sLast = scores[scores.size() - 2];

                scores.push_back(last + sLast);
            }
            else if(op == "C"){
                scores.pop_back();
            }
            else if(op == "D"){
                int last = scores.back();
                scores.push_back(last * 2);
            }
            else {
                scores.push_back(stoi(op));
            }
        }   

        for (int score : scores){
            sum += score;
        }
        return sum;
    }
};