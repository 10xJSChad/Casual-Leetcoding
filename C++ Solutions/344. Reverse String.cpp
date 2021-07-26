class Solution {
public:
    void reverseString(vector<char>& v) {
        int a = 0;
        a = v.size() - 1;
        for (int i = 0; i < v.size() / 2; i++) {
            int temp = v[a]; v[a] = v[i]; v[i] = temp; a--;
        }
    }
};
