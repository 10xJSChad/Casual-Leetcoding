public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        string prefix = ""; string longestPrefix = ""; int mostCommonPrefixLength = 0;
        if(strs.Length == 1){return strs[0];}
        Dictionary<string, int> map = new Dictionary<string, int>();        
        foreach(string word in strs){
            prefix = "";
            foreach(char letter in word){
                prefix += letter;
                try{
                    map[prefix] += 1;
                }catch{
                    map[prefix] = 0; 
                }
            }
        }            
        try{
            mostCommonPrefixLength = map.Values.Max();
        } catch{
            
        }
        if(mostCommonPrefixLength == 0){return "";}
        foreach(KeyValuePair<string, int> kvp in map)
        {
            if(kvp.Value == mostCommonPrefixLength){
                if(kvp.Key.Length > longestPrefix.Length){longestPrefix = kvp.Key;}
            }
        }
        foreach(string word in strs){
            if(!word.StartsWith(longestPrefix)){return "";}
        }     
        return(longestPrefix);
        }
}