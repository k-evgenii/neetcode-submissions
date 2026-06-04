class StockSpanner {
private:
    vector<pair<int, int>> st; //survives between next() calls
public:
    StockSpanner() {
        st.reserve(10000);
    }
    
    int next(int price) {
        int span{1};
        while(!st.empty() &&
            st.back().first <= price
        ){
            span += st.back().second;
            st.pop_back();
        }
        st.push_back({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */