int lengthOfLongestSubstring(char* s) {
    char letters[256] = {0};
    char* left  = s;
    char* right = s;
    
    int max  = 0;
    int curr = 0;

    while (*right) {
        if (letters[*right]) {
            while (*left != *right) {
                letters[*left] = 0;
                ++left;
                --curr;
            }

            ++left;
            --curr;
        }
        
        letters[*right] = 1;
        ++curr;
        ++right;

        if (curr > max)
            max = curr;
    }

    return max;
}
