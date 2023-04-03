int comparator(const void * p1, const void * p2){
  return(*(int*)p1 - *(int*)p2);
}

int numRescueBoats(int* people, int peopleSize, int limit){
    qsort(people, peopleSize, sizeof(int), comparator);
    int min = 0; int max = peopleSize-1; int ans = 0;
    while(min <= max){
        ans++;
        if(people[min] + people[max] <= limit){
            min++;
            max--;
        } else { max--; }
    }
    return(ans);
}
