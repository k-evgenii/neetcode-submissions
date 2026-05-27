class MyQueue {
private:
    stack<int> ans;
public:
    MyQueue() {
    }
    
    void push(int x) {
        stack<int> help;
        
        while(!ans.empty()){
            help.push(ans.top());
            ans.pop();
        }
        
        ans.push(x);

        while(!help.empty()){
            ans.push(help.top());
            help.pop();
        }
    }
    
    int pop() {
        int val = ans.top();
        ans.pop();
        return val;
    }
    
    int peek() {
        return ans.top();
    }
    
    bool empty() {
       return ans.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */