class FreqStack {
private:
    int maxFreq = 0;
    unordered_map<int, int> freq;
    vector<vector<int>> group;

public:
    FreqStack() {
        freq.reserve(20000);
        group.resize(20001);
    }
    
    void push(int val) {
        int f = ++freq[val];

        if (f > maxFreq) {
            maxFreq = f;
        }

        group[f].push_back(val);
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