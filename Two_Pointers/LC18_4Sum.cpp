class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& num, int target) {
        std::vector<std::vector<int>> res;
        if (num.empty())
            return res;
        std::sort(num.begin(), num.end());

    
        long long long_target = target; 

        for (int i = 0; i < num.size(); i++) {
            // Skip duplicates for the first number
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }

            long long target_3 = long_target - num[i]; 

            for (int j = i + 1; j < num.size(); j++) {
                // Skip duplicates for the second number
                if (j > i + 1 && num[j] == num[j - 1]) {
                    continue;
                }

                long long target_2 = target_3 - num[j]; 

                int front = j + 1;
                int back = num.size() - 1;

                while(front < back) {
                    long long two_sum = (long long)num[front] + num[back]; 

                    if (two_sum < target_2) {
                        front++;
                    } else if (two_sum > target_2) {
                        back--;
                    } else {
                        std::vector<int> quadruplet = {num[i], num[j], num[front], num[back]};
                        res.push_back(quadruplet);

                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) {
                            ++front;
                        }
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) {
                            --back;
                        }
                    }
                }
            }
        }
        return res;
    }
};