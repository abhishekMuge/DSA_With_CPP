class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int aliceCount = 0, bobCount = 0;
        int l = 0, r = piles.size() - 1;
        while(l < r) {
            if(piles[l] < piles[r]){
                aliceCount += piles[r];
                bobCount += piles[l];
            } else {
                aliceCount += piles[l];
                bobCount += piles[r];
            }
            l++;
            r--;
        }
        return aliceCount > bobCount;

    }
};