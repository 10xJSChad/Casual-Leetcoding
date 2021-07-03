public class Solution {
    public bool CheckIfPangram(string sentence) {
        Dictionary<char, bool> map = new Dictionary<char, bool>();
        foreach(char x in sentence){
            map[x] = true;
        }
        return map.Count == 26;  
    }
}