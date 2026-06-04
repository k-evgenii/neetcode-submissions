class FreqStack {
private:
    int maxFreq{0};
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> group;
public:
    FreqStack() {
    }
    
    void push(int val) {
        freq[val]++;

        int f = freq[val];
        
        group[f].push(val);

        maxFreq = max(maxFreq, f);
    }
    
    int pop() {
        int value = group[maxFreq].top();
        group[maxFreq].pop();
        
        freq[value]--;
        if (group[maxFreq].empty()){
            maxFreq--;
        }   
        return value; 
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */