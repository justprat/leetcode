class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int n = nums.size();

        int maxSize = 0;
        int left = 0;

        deque<int> minDQ;
        deque<int> maxDQ;

        for(int i = 0 ; i < n ; i++){
            
            //1.remove expired
            while(!minDQ.empty() && !maxDQ.empty() && nums[maxDQ.front()] - nums[minDQ.front()] > limit){

                if(minDQ.front() == left){
                    minDQ.pop_front();
                }
                if(maxDQ.front() == left){
                    maxDQ.pop_front();
                }

                left++;
            }

            //2.remove dominated
            while(!minDQ.empty() && nums[minDQ.back()] >= nums[i]){
                minDQ.pop_back();
            }

            while(!maxDQ.empty() && nums[maxDQ.back()] <= nums[i]){
                maxDQ.pop_back();
            }

            //3. store
            minDQ.push_back(i);
            maxDQ.push_back(i);

            //4.record ans
            if(nums[maxDQ.front()] - nums[minDQ.front()] <= limit){
                maxSize = max(maxSize, i - left + 1);
            }
        }

        return maxSize;
   
    }
};