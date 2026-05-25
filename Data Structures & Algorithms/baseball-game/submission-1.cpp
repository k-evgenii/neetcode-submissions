class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        int sum = 0;

        for (const string& op : operations) {

            if (op == "+") {
                int n = scores.size();
                int newScore = scores[n - 1] + scores[n - 2];

                scores.push_back(newScore);
                sum += newScore;
            }
            else if (op == "C") {
                sum -= scores.back();
                scores.pop_back();
            }
            else if (op == "D") {
                int newScore = scores.back() * 2;

                scores.push_back(newScore);
                sum += newScore;
            }
            else {
                int newScore = stoi(op);

                scores.push_back(newScore);
                sum += newScore;
            }
        }

        return sum;
    }
};