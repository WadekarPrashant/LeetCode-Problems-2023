class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> result;

        // Initialize the first element of the row to 1.
        result.push_back(1);

        // Calculate each element in the row using the binomial coefficient formula.
        for (int i = 1; i <= rowIndex; i++) {
            long prevElement = result[i - 1];
            // Use the formula C(r, i) = C(r, i-1) * (r - i + 1) / i
            long currentElement = prevElement * (rowIndex - i + 1) / i;
            result.push_back(static_cast<int>(currentElement));
        }

        return result;
    }
};
