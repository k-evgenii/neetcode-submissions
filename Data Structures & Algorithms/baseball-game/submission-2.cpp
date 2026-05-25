class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        scores.reserve(operations.size());

        int sum = 0;

        for (const string& op : operations) {
            char c = op[0];

            if (c == '+') {
                int n = scores.size();
                int newScore = scores[n - 1] + scores[n - 2];

                scores.push_back(newScore);
                sum += newScore;
            }
            else if (c == 'C') {
                sum -= scores.back();
                scores.pop_back();
            }
            else if (c == 'D') {
                int newScore = scores.back() * 2;

                scores.push_back(newScore);
                sum += newScore;
            }
            else {
                int sign = 1;
                int i = 0;

                if (op[0] == '-') {
                    sign = -1;
                    i = 1;
                }

                int num = 0;

                while (i < op.size()) {
                    num = num * 10 + (op[i] - '0');
                    i++;
                }

                num *= sign;

                scores.push_back(num);
                sum += num;
            }
        }

        return sum;
    }
};