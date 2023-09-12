class Solution {
public:
    int minDeletions(string s) {
        // Create a vector to store the frequency of each lowercase English letter (fixed size of 26).
        vector<int> freq(26, 0);

        // Iterate through the characters of the input string s to count their frequencies.
        for (char c : s) {
            freq[c - 'a']++; // Increment the corresponding frequency counter.
        }

        // Sort the frequency vector in non-decreasing order.
        sort(freq.begin(), freq.end());

        // Initialize a variable to keep track of the minimum number of deletions needed.
        int del = 0;

        // Iterate through the sorted frequency vector in reverse order.
        for (int i = 24; i >= 0; i--) {
            // If the current frequency is 0, break the loop (no more characters with this frequency).
            if (freq[i] == 0) {
                break;
            }

            // Check if the current frequency is greater than or equal to the next frequency.
            if (freq[i] >= freq[i + 1]) {
                int prev = freq[i];
                // Reduce the current frequency to make it one less than the next frequency.
                freq[i] = max(0, freq[i + 1] - 1);
                // Update the deletion count by the difference between previous and current frequency.
                del += prev - freq[i];
            }
        }

        // Return the minimum number of deletions required to make the string "good."
        return del;
    }
};
