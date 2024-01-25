int lengthOfLongestSubstring(char* s) {
    char letters[256] = {0};
    char* left  = s;
    char* right = s;
    
    int max  = 0;
    int curr = 0;

    while (*right) {
        if (letters[*right]) {
            do {
                letters[*left] = 0;
                --curr;
            } while (*(left++) != *right);
        }
        
        letters[*(right++)] = 1;
        ++curr;

        if (curr > max)
            max = curr;
    }

    return max;
}
