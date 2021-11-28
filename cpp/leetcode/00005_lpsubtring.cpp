#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

#ifdef LPSUBTRING

//比较啰嗦的方法
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int size = s.size();
        char *pbegin = s.data();
        int max_size = 0;
        int x = 0;
        int y = 0;

        for (int i = x; i < size;i++) {
            for (int j = size-1; j > i;j--) {
                if (pbegin[i] != pbegin[j]) {
                    continue;
                }

                // 找到 pbegin[i] == pbegin[j]
                int dsize = j - i;
                std::cout << i << j << dsize << std::endl;
                int m = 0;
                for (; m < (dsize + 1) /2; m++) {
                    if (pbegin[i+m] != pbegin[j-m]) {
                        //但凡有不相等的  直接break
                        break;
                    }
                }

                if (m == (dsize + 1)/ 2) {
                    if (max_size < dsize ) {
                        x = i;
                        y = j;
                        max_size = dsize;
                    }
                }
            }
        }
        return s.substr(x, y -x + 1);
    }
};

//改良版
class Solution2 {
public:
    std::string longestPalindrome(std::string s) {
        int size = s.size();
        char *p = s.data();
        int max_size = 0;
        int x = 0;
        int y = 0;

        for (int i = x; i < size;i++) {
            for (int j = size-1; j > i;j--) {
                if (p[i] != p[j]) {
                    continue;
                }

                // 找到 p[i] == p[j]
                int dsize = j - i;
                //for ()
            }
        }
        return s.substr(x, y -x + 1);
    }
};


//动态规划
class Solution3 {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                        std::cout << "(" << i << " " << j << ") = [" << i+1 << " " << j-1 << "]" << std::endl;
                    }
                }
                std::cout << "(" << i << " " << j << ") = " <<  dp[i][j] << std::endl;

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};


class Solution4 {
public:
    std::string longestPalindrome(std::string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            count += count(s, i, i);//回文子串长度为奇数的情况
            count += count(s, i, i + 1);//回文子串长度为偶数的情况
        }
        return count;
    }
    
    int count(std::string s, int start, int end) {
        int count = 0;
        //start往左边跑，end往右边跑，注意边界
        while (start >= 0 && end < s.length() && s.charAt(start--) == s.charAt(end++)) {
            count++;
        }
        return count;
    }

int main(void)
{
    std::string s1 {"ac"};
    std::string s2 {"a"};
    std::string s3 {"cbbd"};
    std::string s4 {"babad"};
    std::string s5 {"aacabdkacaa"};
    // std::string s2 {"bbbbb"};
    // std::string s3 {"pwwkew"};
    // std::string s4 {""};
    Solution4 sol;
    /* std::cout << sol.longestPalindrome(s1) << std::endl;
    std::cout << sol.longestPalindrome(s2) << std::endl;
    std::cout << sol.longestPalindrome(s3) << std::endl;
    std::cout << sol.longestPalindrome(s4) << std::endl; */
    std::cout << sol.longestPalindrome(s5) << std::endl;
    getchar();
    return 0;
}

#endif /* LPSUBTRING */
