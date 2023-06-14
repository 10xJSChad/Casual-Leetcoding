public class Solution 
{
    public int[] ReplaceElements(int[] arr) 
    {
        int max = arr[arr.Length - 1];
        arr[arr.Length - 1] = -1;

        for (int i = arr.Length - 2; i > -1; --i)
        {
          if (arr[i] > max)
          {
            int temp = arr[i];
            arr[i] = max;
            max = temp;
          }
          else
          {
            arr[i] = max;
          }
        }
        
        return arr;
    }
}
