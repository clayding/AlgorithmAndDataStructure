// 使用dequeu
class Solution {
    deque<char> dq;
public:
    string reverseWords(string s) {
        int size = s.size();
        int left = 0, right = size - 1;
        while(left <= right && s[left] == ' ') left++;
        while(left <= right && s[right] == ' ') right--;

        bool space = false;
        while(left <= right) {
            if (s[left] == ' ') {
                if (space) {
                    left++;
                    continue;
                }
                space = true;
            }
            dq.push_front(s[left++]);
            space = false;
        }

        string rs;
        while(!dq.empty()) {
            rs += dq.front();
            dq.pop_front();
        }

        return rs;
    }
};

//使用stack
class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        stack<string> myst;
        string result;
        for(char &c:s) {
            if (isspace(c)) {
                if (result.size()) {
                    myst.push(result);
                    result = "";
                }
                continue;
            }
            result += c;
        }

        if (result.size()) {
           myst.push(result);
           result = "";
        }

        while (!myst.empty()) {
            result += myst.top();
            myst.pop();
            
            if (!myst.empty())
                result += " ";
        }

        return result;
    }
};