#ifdef LSWRC_DEF
//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

//自求解方案
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int size = s.size();
        int max_size = 0;
        std::unordered_map<char, int> hashtable;

        for (int i = 0; i <size; i++) {
            for (int j = i+1; j <= size; j++) {
                std::string subs = s.substr(i, j-i);
                const char *p = subs.data();
                for (; *p != '\0'; p++) {
                    auto it = hashtable.find(*p);
                    if (it != hashtable.end()) {
                        break;
                    }
                    hashtable[*p]=i+j;
                }
                if (*p == '\0') {
                    int size = subs.size();
                    max_size = size > max_size?size:max_size;
                }
                hashtable.clear();
            }
        }
        return max_size;
    }
};

//滑动窗口 方案1
//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/
class Solution2 {
public:
    int lengthOfLongestSubstring(std::string s) {
        int size = s.size();
        int left = 0; //作为index 起始位置为s得开头字符
        int max_size = 0;
        std::unordered_set<char> charset;
        for (int i = 0; i < size; i++) {
            //遍历 charset， 查找是否包含s[i]
            auto it = charset.find(s[i]);

            while (it != charset.end()) {
                //找到 s[i]，那么把 s[i] 和其之后得全部滑动删除
                charset.erase(s[left]);
                left++;
                it = charset.find(s[i]); //继续查找 s[i]， 直到找不到则跳出while
            }

            max_size = std::max(max_size, i-left+1);
            charset.insert(s[i]);
        }
        return max_size;
    }
};

//滑动窗口 方案 2
//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/
class Solution3 {
public:
    int lengthOfLongestSubstring(std::string s) {
        int size = s.size();
        int right = 0; //作为index 末尾位置为s得开头字符
        int max_size = 0;
        std::unordered_set<char> charset;
        for (int i = 0; i < size; i++) {
           //第一个字符肯定不是重复的
           if ( i != 0) {
               charset.erase(s[i-1]);
           }

           while (right + 1< size && charset.count(s[right + 1]) == 0) {
               //说明charset中不包含 s[i]
               //不断移动右指针
               charset.insert(s[right + 1]);
               right ++;
           }

           //否则right + 1 > n 或者 charset中包含了s[right + 1]
           //那么最大值为
           max_size = std::max(max_size, right-i+1);

           //再次for循环  直到在charset.erase(s[i]); 中删除了找到的s[right + 1]
           //如果right + 1< size 依然成立，才有可能再进入while中
        }
        return max_size;
    }
};

int main(void)
{
    // std::string s1 {"abcabcbb"};
    // std::string s2 {"bbbbb"};
    // std::string s3 {"pwwkew"};
    // std::string s4 {""};
    std::string s5 {" "};
    std::string s6 {"xqgatvlevdqugapmlgymhkdgjthnqflpvtpqodujingqnvcyeamlmruvndkfivufokvcpqoxfunsrptvshhgzbcogotpknuyz"};
    Solution sol;
    Solution2 sol2;
    Solution3 sol3;
    // cout << sol.lengthOfLongestSubstring(s1) << endl;
    // cout << sol.lengthOfLongestSubstring(s2) << endl;
    // cout << sol.lengthOfLongestSubstring(s3) << endl;
    // cout << sol.lengthOfLongestSubstring(s4) << endl;
    // std::cout << sol.lengthOfLongestSubstring(s5) << std::endl;
    // std::cout << sol.lengthOfLongestSubstring(s6) << std::endl;

    std::cout << sol2.lengthOfLongestSubstring(s5) << std::endl;
    std::cout << sol2.lengthOfLongestSubstring(s6) << std::endl;

    std::cout << sol3.lengthOfLongestSubstring(s5) << std::endl;
    std::cout << sol3.lengthOfLongestSubstring(s6) << std::endl;
    getchar();
    return 0;
}
#endif //LSWRC_DEF

