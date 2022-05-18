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

// 自己写的检查是字母和数字
class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();

        if (size == 0) {
            return true;
        }
        int left = 0, right = size - 1;
        while(left <= right) {

            if(!isNumberAlpha(s[left])) {
                left++;
                continue;
            }

            if (!isNumberAlpha(s[right])) {
                right--;
                continue;
            }
            char lchar = s[left];
            char rchar = s[right];

            //alphal
            if (lchar >= 'a' && lchar <= 'z') {
                lchar = lchar - ('a' - 'A');
            }

            if (rchar >= 'a' && rchar <= 'z') {
                rchar = rchar - ('a' - 'A');
            }
            if (lchar != rchar) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool isNumberAlpha(char in) {
        if (in >= '0' && in <= '9' || 
            in >= 'A' && in <= 'Z' ||
            in >= 'a' && in <= 'z') {
                return true;
        }

        return false;
    }
};
