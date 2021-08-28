// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long min = 0;
    long max = n;
    int mid;
    while(min <= max){
        mid = (min + max) / 2;
        if(isBadVersion(mid)) max = mid - 1;
        else min = mid + 1;
    } 
    return min;
}
