class Solution {
public:
    bool isPowerOfThree(int n) {
        ios_base::sync_with_stdio(0);
    	cin.tie(nullptr);
    	cout.tie(nullptr);
        if (n <= 0) return false;
        if (n == 1) return true;
        return fmod((log10(n) / log10(3)), 1) == 0;
    }
};