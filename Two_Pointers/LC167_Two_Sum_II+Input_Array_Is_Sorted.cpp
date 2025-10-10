class Solution {
public:
//Riya Malik
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n =  numbers.size();
        int i=0, j=n-1, sum=0;
        
        while(i<j){
            sum = numbers[i] + numbers[j];

            if(sum>target) j--;
            else if(sum<target) i++;
            else {
                return {i+1, j+1};
            }
        }
        return {-1, -1};
    }
};