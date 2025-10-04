class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool dup_found = false;
        int next_spot = 1;
        int n_size = nums.size();
        for(int i = 1; i < n_size; i++){
            if(nums[i] != nums[i - 1]){
                nums[next_spot] = nums[i];
                next_spot++;
                dup_found = false;
            }
            // Numbers are equal, but is first time
            else if (!dup_found){
                nums[next_spot] = nums[i];
                next_spot++;
                dup_found = true;
            }
            else{
                continue;
            }
        }
        return next_spot;
    }
};


//===============================================
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for(auto n: nums) {
            if(idx == 0 || idx == 1 || nums[idx-2] != n) {
                nums[idx] = n;
                idx++;
            }
        }
        return idx;
    }
};