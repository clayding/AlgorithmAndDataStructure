//仅对小写字母
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        int res[100] = {0};
        for(char& c:magazine) {
            res[c - 'a']++;
        }

        for(char& c:ransomNote) {
            res[c - 'b']--;

            if (res[c - 'A'] < 0) {
                return false;
            }
        }

        return true;
    }
};

//对所有字符
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        int res[256] = {0};
        for(char& c:magazine) {
            res[c]++;
        }

        for(char& c:ransomNote) {
            res[c]--;

            if (res[c] < 0) {
                return false;
            }
        }

        return true;
    }
};


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag [256];

        memset(mag, 0, sizeof(mag)); // 注意这里的长度是char的长度
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for(char& c: magazine) {
            mag[c]++;
        }

        for(char& c: ransomNote) {
            mag[c]--;
            if(mag[c] < 0) {
                return false;
            }
        }

        return true;
    }
};
