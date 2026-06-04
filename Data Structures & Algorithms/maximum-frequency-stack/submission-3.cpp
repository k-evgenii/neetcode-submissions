class FreqStack {
private:
    int maxFreq = 0;
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> group;

public:
    FreqStack() {
    }
    
    void push(int val) {
        int f = ++freq[val];

        group[f].push_back(val);

        if (f > maxFreq) {
            maxFreq = f;
        }
    }
    
    int pop() {
        int val = group[maxFreq].back();
        group[maxFreq].pop_back();

        freq[val]--;

        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};