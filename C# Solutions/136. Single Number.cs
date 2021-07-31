public class Solution {
    public int SingleNumber(int[] nums) {
        Dictionary<int, int> map = new Dictionary<int, int>();
        foreach(int num in nums) {
            try{
                map[num] += 1;
            }catch{
                map[num] = 1; 
            }
        }
        var min = map.Aggregate((l, r) => l.Value < r.Value ? l : r).Key;
        return(min);
    }
}
