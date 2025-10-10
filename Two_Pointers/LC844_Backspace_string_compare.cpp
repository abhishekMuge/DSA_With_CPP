class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1; // Pointer for string S, starting from the end
        int j = T.length() - 1; // Pointer for string T, starting from the end

        int skipS = 0; // Counter for backspaces in S
        int skipT = 0; // Counter for backspaces in T

        while (i >= 0 || j >= 0) { // Continue as long as there are characters in either string
            // Find next valid character for S
            while (i >= 0) {
                if (S[i] == '#') {
                    skipS++; // Increment backspace counter
                    i--;     // Move to previous character
                } else if (skipS > 0) {
                    skipS--; // Consume a backspace
                    i--;     // Move to previous character
                } else {
                    break;   // Found a valid character
                }
            }

            // Find next valid character for T
            while (j >= 0) {
                if (T[j] == '#') {
                    skipT++; // Increment backspace counter
                    j--;     // Move to previous character
                } else if (skipT > 0) {
                    skipT--; // Consume a backspace
                    j--;     // Move to previous character
                } else {
                    break;   // Found a valid character
                }
            }

            // Compare characters
            if (i >= 0 && j >= 0) {
                if (S[i] != T[j]) {
                    return false; // Mismatch found
                }
            } else if (i >= 0 || j >= 0) {
                return false; // One string has remaining characters while the other doesn't
            }

            i--; // Move to the previous character in S
            j--; // Move to the previous character in T
        }

        return true; // Both strings are identical after backspace processing
    }
};