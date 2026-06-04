class StockSpanner {
private:
    int prices[10000];
    int spans[10000];
    int idx;

public:
    StockSpanner() {
        idx = -1;
    }
    
    int next(int price) {
        int span = 1;

        while (idx >= 0 && prices[idx] <= price) {
            span += spans[idx];
            idx--;
        }

        idx++;
        prices[idx] = price;
        spans[idx] = span;

        return span;
    }
};