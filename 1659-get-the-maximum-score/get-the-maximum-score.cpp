class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        int MOD = 1e9 + 7;

        int i = 0, j = 0;

        long long firstPath = 0;
        long long secondPath = 0;
        long long maxScore = 0;


        //1. find threshold -> equal values
        while(i < m && j < n) {

            if(nums1[i] < nums2[j]){
                firstPath += nums1[i];
                i++;
            } 

            else if(nums1[i] > nums2[j]){
                secondPath += nums2[j];
                j++;
            } 
            //new threshold -> record , find new 
            else{
                maxScore += max(firstPath, secondPath) + nums1[i];
                firstPath = 0;
                secondPath = 0;
                i++;
                j++;
            }
        }

        //one reached end case
        while(i < m){
            firstPath += nums1[i];
            i++;
        }

        while(j < n){
            secondPath += nums2[j];
            j++;
        }

        maxScore += max(firstPath, secondPath);

        return maxScore % MOD;
    }
};
