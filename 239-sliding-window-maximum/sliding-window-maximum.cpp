class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> ans;

        for(int i = 0 ; i < nums.size() ; i++){

            //1. remove left
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }

            //2. remove dominated
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            //3. add
            dq.push_back(i);

            //4. store
            if(i + 1 >= k){
                ans.push_back(nums[dq.front()]);
            }

        }

        return ans;
        
    }
};