class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int count = 0;
        int greatest = 0;
        for (auto x:accounts){
            for (auto y:x){
                count += y;
            }
            if (count > greatest){greatest = count;}
            count = 0;
        }
        return greatest;
    }
};
