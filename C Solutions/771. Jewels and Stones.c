int numJewelsInStones(char * jewels, char * stones){
    int i = 0, j = 0, c = 0;
    while(1){
        j = 0;
        while(1){
            if(!stones[j]) break;
            if(jewels[i] == stones[j]) c++;
            j++;
        }
        if(!jewels[i]) break;
        i++;
    }
    return c;
}
