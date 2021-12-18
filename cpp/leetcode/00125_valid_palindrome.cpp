class Solution {
public:
    bool isPalindrome(string s) {

        string s1;
        for (char& c:s) {
            if (isalnum(c)) {
                s1 += tolower(c);
            }
        }

        int size = s1.size();
        int left = 0, right = size -1;
        while (left < right) {
            if (s1[left++] != s1[right--]) {
                return false;
            }
        }

        return true;
    }
};
