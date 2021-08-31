char * reverseWords(char * s){
    int i = 0;
    int wordStart = -1;
    
    goto loop;
    reverse:;
        char temp;
        int max = i-1;
        int y = 0;
        for(int j=wordStart; j<((i - wordStart) / 2) + wordStart; j++){
            char temp = s[j];
            s[j] = s[max-y];
            s[max-y] = temp;
            y++;
        }
    
        wordStart = -1;
        goto loopEnd;
    
    loop:;
    while(i < strlen(s) + 1){
        if(s[i] != '\0' && s[i] != ' '){
            if(wordStart == -1)
                wordStart = i;
        }else{
            goto reverse;
        }
        loopEnd:;
        i++;
    }
    
    return s;
}
