//brute force
class StockSpanner {
public:
    vector<int> p;

    StockSpanner() {
    }

    int next(int price) {
        p.push_back(price);

        int span = 0;

        for (int i = p.size() - 1; i >= 0; i--) {
            if (p[i] <= price) {
                span++;
            } else {
                break;
            }
        }

        return span;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */