int
lengthOfLastWord (
    char* s)
{
    int prev_space_index = 0;    
    int i = 0;

    while (s[++i]) {
        if (s[i] != ' ') {
            if (s[i-1] == ' ')
                prev_space_index = i;
        } else {
            ++prev_space_index;
        }
    }

    return i - prev_space_index;
}
