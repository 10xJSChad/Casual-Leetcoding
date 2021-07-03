public class Solution {
    public int FindNumbers(int[] nums) {
        int evenNumbers = 0;
        foreach(int i in nums){
            if(i.ToString().Length%2 == 0) evenNumbers++;
        }
        return evenNumbers;
    }
}