class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> toReturn;
        int highest = 0;
        for (auto x:candies){
            if (x > highest) {highest = x;}
        }
        for (auto x:candies){
            if ((x + extraCandies) >= highest){
                toReturn.push_back(true);
            } else {toReturn.push_back(false);}
        }
        return toReturn;
    }
};
