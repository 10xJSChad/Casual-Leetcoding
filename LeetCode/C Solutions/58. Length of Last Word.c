int 
lengthOfLastWord(char* s)
{
    int curr = 0;
    int last = 0;

    do {
        if (*s == ' ') {
            if (curr > 0) {
                last = curr;
                curr = 0;
            }
        } else {
            ++curr;
        }
    } while (*(++s));

    return curr == 0 ? last : curr;
}
