#include <bits/stdc++.h>
using namespace std;

struct ClassInfo {
    int pass, total;
    // calculate gain of adding one extra student
    double gain() const {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }
};

// custom comparator for min-priority queue based on negative gain
struct Compare {
    bool operator()(const ClassInfo& a, const ClassInfo& b) {
        return a.gain() < b.gain(); // max gain comes first
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<ClassInfo, vector<ClassInfo>, Compare> pq;

        // push all classes
        for (auto& c : classes) {
            pq.push({c[0], c[1]});
        }

        // assign extra students
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            top.pass++;
            top.total++;
            pq.push(top);
        }

        // compute final average
        double sum = 0.0;
        while (!pq.empty()) {
            auto c = pq.top(); pq.pop();
            sum += (double)c.pass / c.total;
        }
        return sum / classes.size();
    }
};

int main() {
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    int extraStudents = 2;
    
    Solution sol;
    cout << fixed << setprecision(5) 
         << sol.maxAverageRatio(classes, extraStudents) << endl;
    
    return 0;
}
