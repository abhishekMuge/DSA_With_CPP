class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dir, red;
        int n = senate.length();
        for(int i = 0; i < n; i++){
            if(senate[i] == 'R') red.push(i);
            else dir.push(i);
        }

        while(!red.empty() && !dir.empty()){
            if(red.front() < dir.front()) {
                red.push(n++);
            }
            else {
                dir.push(n++);
            }
            red.pop(); dir.pop();
        }
        return (red.empty()) ? ("Dire") : ("Radiant");
    }
};