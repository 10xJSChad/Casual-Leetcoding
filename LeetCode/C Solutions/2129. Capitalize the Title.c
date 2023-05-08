char toLower(char titleChar){
    if(titleChar >= 65 && titleChar <= 90)
        return(titleChar + 32);
    return(titleChar);
}

bool isUpper(char titleChar){
    if(titleChar >= 65 && titleChar <= 90)
        return(true);
    return(false);
}

char * capitalizeTitle(char * title){
    int count = 0;
    int i = 0;
    int curr = 0;
    while(true){
        count++;
        
        if(title[i] == ' ' || title[i] == '\0'){
            for(int j=curr; j<i; j++){
                title[j] = toLower(title[j]);
            }
            
            if(count > 3 && !isUpper(title[curr]))
                title[curr] -= 32;
            count = 0;
        }
        
        if(count == 1)
            curr = i;
        
        if(title[i] == '\0')
            break;
        i++;
    }
    
    return(title);
}
