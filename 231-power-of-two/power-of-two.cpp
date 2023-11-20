class Solution {
public:
    bool isPowerOfTwo(int n) {
        ios_base::sync_with_stdio(0);
    	
        if (n <= 0) return false;
        if (!(n & (n-1))) return true;
        return false;
    }
};