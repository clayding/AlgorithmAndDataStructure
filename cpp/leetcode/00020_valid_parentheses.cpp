//超出时间限制
class Solution {
public:
    bool isValid(string s) {
        int size = s.size();

        for (int i = 0; i < size - 1;) {
            if (s[i] == '(') {
                if (s[++i] != ')') {
                    if (s[size - i] != ')') {
                        return false;
                    }
                }
                continue;
            }

            if (s[i] == '[') {
                if (s[++i] != ']') {
                    if (s[size - i] != ']') {
                        return false;
                    }
                }
                continue;
            }

            if (s[i] == '{') {
                if (s[++i] != '}') {
                    if (s[size - i] != '}') {
                        return false;
                    }
                }
                continue;
            }
        }
        return true;
    }
};

//使用栈
class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> st;
        for (size_t i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
                continue;
            }

            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (st.empty()) {
                    return false;
                }
                char c = st.top();

                if ((s[i] == ')' && c == '(') ||
                    (s[i] == ']' && c == '[') ||
                    (s[i] == '}' && c == '{')) {
                        st.pop();
                        continue;
                } else {
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        }

        return false;
    }
};

// 更规范一点的栈
class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> st;
        for (size_t i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
                continue;
            }

            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (st.empty()) {
                    return false;
                }
                char c = st.top();

                if ((s[i] == ')' && c == '(') ||
                    (s[i] == ']' && c == '[') ||
                    (s[i] == '}' && c == '{')) {
                        st.pop();
                        continue;
                } else {
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        }

        return false;
    }
};