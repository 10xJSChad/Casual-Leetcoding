int lengthOfLastWord(char * s){
    int max = strlen(s) - 1;
    int length = 0;
    for(max; max>=0; max--){
        if(s[max] != ' ') length++;
        else{
            if(length > 0) return length;
        }
    }
    return length;
}
