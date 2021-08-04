char * mergeAlternately(char * word1, char * word2){
    int size = 0; int next = 0;
    char*str=calloc(strlen(word1) + strlen(word2) + 1, sizeof(char));   
    size = strlen(word1) + strlen(word2);
    
    for(int i = 0; i<size; i++){
        if(i < strlen(word1)){
            str[next] = word1[i];
            next++;
        }
        if(i < strlen(word2)){
            str[next] = word2[i];
            next++;
        }
    }  
    
    return str;
}
