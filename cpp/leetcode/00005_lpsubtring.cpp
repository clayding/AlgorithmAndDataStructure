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
        std::vector<std::vector<int>> dp(n, std::vector<int>(n)); //dp 就是dynamic planning
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

                if (s[i] != s[j]) { // 根据状态转移方程: P(i,j)=P(i+1,j−1)∧(Si​ ==Sj​ ), 只要 (Si​ !=Sj​ ) 则P(i,j) 不相等
                    dp[i][j] = false;
                } else { //如果 s[i] == s[j]
                    if (j - i < 3) { // j -i < 3 也就是 j -i + 1 < 3 + 1,字串最大长度为3 ( < 4)，除去Si 和Sj 最多还有1个. 比如bab 因此肯定是回文子串
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];// 根据状态转移方程 P(i,j)=P(i+1,j−1)∧(Si​ ==Sj​ )
                        std::cout << "(" << i << " " << j << ") = [" << i+1 << " " << j-1 << "]" << std::endl;
                    }
                }
                std::cout << "(" << i << " " << j << ") = " <<  dp[i][j] << std::endl;

                // 只要 dp[i][j] == true 成立，就表示子串 s[i..j] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) { //这里也可以写成 if (dp[i][j] && L > maxLen) {
                    maxLen = j - i + 1;               // 同样，这里也可以写成 maxLen = L;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};


//中心扩散
class Solution {
public:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int start = 0, end = 0;
        for(int i = 0; i < size ; i++) {
            auto [left1, right1] = count(s, i, i);
            auto [left2, right2] = count(s, i, i + 1);

            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }

        return s.substr(start, end - start + 1);
    }

    pair<int, int> count(const string& s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right] ) {
            --left;
            ++right;
        }

        return {left+1, right-1};
    }
};

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
