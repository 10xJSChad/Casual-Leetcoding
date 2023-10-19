char* parse(char* buf, char* s) {
    int i = 0;
    while (*s) {
        if (*s == '#') {
            if (i > 0) {
                buf[--i] = '\0';
            }
        } else {
            buf[i++] = *s;
        }

        ++s;
    }

    return buf;
}


bool backspaceCompare(char* s, char* t){
    char buf_s[256] = {0};
    char buf_t[256] = {0};
    return strcmp(parse(buf_s, s), parse(buf_t, t)) == 0;
}
