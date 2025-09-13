class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int,int>> stones; 

        for (int i = 0; i < n; i++) {
            stones.push_back({aliceValues[i] + bobValues[i], i});
        }
        sort(stones.rbegin(), stones.rend());

        int aliceScore = 0, bobScore = 0;

        for (int turn = 0; turn < n; turn++) {
            int idx = stones[turn].second;
            if (turn % 2 == 0) { // Alice's turn
                aliceScore += aliceValues[idx];
            } else { // Bob's turn
                bobScore += bobValues[idx];
            }
        }

        if (aliceScore > bobScore) return 1;
        else if (aliceScore < bobScore) return -1;
        else return 0;
    }
};