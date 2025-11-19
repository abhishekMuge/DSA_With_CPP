class TrieNode {
public:
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a number into the Trie
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) {
                node->child[bit] = new TrieNode();
            }
            node = node->child[bit];
        }
    }

    // Find max XOR for this number
    int getMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int desired = 1 - bit;  // opposite bit to maximize XOR

            if (node->child[desired]) {
                // we found opposite → contributes 1 to result at this bit
                maxXor |= (1 << i);
                node = node->child[desired];
            } 
            else {
                // cannot choose desired, must take same bit
                node = node->child[bit];
            }
        }

        return maxXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxVal = 0;

        trie.insert(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int cur = nums[i];
            int best = trie.getMaxXor(cur);
            maxVal = max(maxVal, best);
            trie.insert(cur);
        }

        return maxVal;
    }
};
