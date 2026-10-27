class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        int n = arr.size();

        // Step 1: Find suffix .... n -1
        int suffix = n - 1;
        while (suffix > 0 && arr[suffix - 1] <= arr[suffix]) {
            suffix--;
        }

        //no dip
        if (suffix == 0) return 0;

        // Step 2: find 0....prefix
        int prefix = 0;
        while (prefix < n - 1 && arr[prefix] <= arr[prefix + 1]) {
            prefix++;
        }

        //take any one 
        int result = min(suffix, n - 1 - prefix);

        // Step 3:
        int i = 0, j = suffix;
        while (i <= prefix && j < n) {
            if (arr[i] <= arr[j]) { //bridge is possible -> record , find a better
                result = min(result, j - i - 1);
                i++;
            } else {
                j++; //bridge fails , try to fix it
            }
        }

        return result;
    }
};