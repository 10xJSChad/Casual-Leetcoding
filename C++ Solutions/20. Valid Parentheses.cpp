class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;
        bracketStack.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (bracketStack.size() == 0) bracketStack.push(s[i]);
            else if (bracketStack.top() == '(' && s[i] == ')') bracketStack.pop();
            else if (bracketStack.top() == '{' && s[i] == '}') bracketStack.pop();
            else if (bracketStack.top() == '[' && s[i] == ']') bracketStack.pop();
            else (bracketStack.push(s[i]));
        }

        if (bracketStack.size() == 0) return true;
        else return false;
    }
};