public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        List<int> numsList = new List<int>();
        foreach (int i in nums1){
            numsList.Add(i);
        }  
        foreach (int i in nums2){
            numsList.Add(i);
        }     
        numsList.Sort();
        if(numsList.Count%2 == 0){
          float toReturn;
          int medianIndex = (numsList.Count / 2) - 1;
          return ((double)numsList[medianIndex] + (double)numsList[medianIndex + 1]) / 2;
        }else{
          int medianIndex = (numsList.Count / 2);
          return numsList[medianIndex];
        }                
    }
}