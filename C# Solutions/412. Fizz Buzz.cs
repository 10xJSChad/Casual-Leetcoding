public class Solution {
    public IList<string> FizzBuzz(int n) {
        int i = 0; int fizz = 0; int buzz = 0;
        List<string> result = new List<string>();
        while(i != n){
            i++; fizz++; buzz++;
            if(fizz != 3 && buzz != 5){result.Add("" + i);}
            if(fizz == 3 && buzz == 5){result.Add("FizzBuzz"); fizz = 0; buzz = 0;}
            if(fizz == 3){result.Add("Fizz"); fizz = 0;}
            if(buzz == 5){result.Add("Buzz"); buzz = 0;}
        }
        return result;
    }
}
