class Solution {
public:
    int reverse(int x) {
        if (x == 0 || x == INT_MIN || x == INT_MAX) return 0;
        bool is_negative = x < 0;
        if (is_negative) x = -x;
        queue<int> p;
        while (x) {
            p.push(x%10);
            x /= 10;
        }
        if (p.size() >= 10 && p.front() > 2) return 0;
        int r = 0;
        while (!p.empty()) {
            r = p.front() + r * 10;
            p.pop();
        }
        if (is_negative) r = -r;
        if (!is_negative && r < 0) return 0;
        if (is_negative && r > 0) return 0;
        return r;
    }
};