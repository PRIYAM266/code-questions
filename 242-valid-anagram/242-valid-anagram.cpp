class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq1[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            freq1[s[i] - 'a']++;
        }
        int freq2[26] = {0};
        for (int i = 0; i < t.size(); i++) {
            freq2[t[i] - 'a']++; 
        }
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                return false;
        }
        return true;
        
    }
};