int lengthOfLongestSubstring(char* s) {
    bool seen[256] = {0};
    char* left  = s;
    char* right = s;
    int max     = 0;
    int len     = 0;

    while (*right) {
        if (seen[*right]) {
            do {
                seen[*left] = false;
                --len;
            } while (*(left++) != *right);
        }
        
        seen[*(right++)] = true;
        ++len;

        if (len > max)
            max = len;
    }

    return max;
}
