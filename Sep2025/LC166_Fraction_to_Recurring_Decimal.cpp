class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        // Convert to long long to avoid overflow
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // Integer part
        result += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return result; // No fractional part

        result += ".";

        // Fractional part
        unordered_map<long long, int> seen; // remainder -> index in result
        while (rem != 0) {
            if (seen.find(rem) != seen.end()) {
                // Insert '(' at the first occurrence
                result.insert(seen[rem], "(");
                result += ")";
                break;
            }
            seen[rem] = result.size();

            rem *= 10;
            result += to_string(rem / den);
            rem %= den;
        }

        return result;
    }
};