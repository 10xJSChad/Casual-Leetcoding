public class Solution {
    public int StrStr(string haystack, string needle) {
        string compare = "";
        int range = needle.Length;
        if(needle == "") return 0;
        for(int i = 0; i<haystack.Length; i++){
            compare += haystack[i];
            if(compare.Length > range) compare = compare.Remove(0, 1);
            if(compare == needle) return(i - range + 1);
        }
        return -1;
    }
}
