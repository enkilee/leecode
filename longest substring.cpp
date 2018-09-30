static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
	int lengthOfLongestSubstring(const string& s) {
		if (s.empty())
			return 0;
		int l = 0, max = 1;
		for (int r = 1; r < s.size(); ++r) {
			for (int j = l; j < r; ++j) {
				if (s[r] == s[j]) {
					l = j + 1;
					break;
				}
			}
			max = (max > r - l + 1) ? max : r - l + 1;
		}
		return max;
	}
};