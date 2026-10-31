class Solution {
public:
    int getNext(int slow ,vector<int> &nums){

        int n = nums.size();

        int nextIdx = (slow + nums[slow] % n + n) % n;

        if(nums[slow] == 0 || nextIdx == slow) return -1e7;

        return nextIdx;
        
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0 ; i <  n ; i++){

            if(nums[i] != 0){

                int slow = i;
                int fast = i;

                bool isForward = (nums[i] > 0);
                bool valid = true;

                do{
                    slow = getNext(slow,nums);
                    if(slow == - 1e7 || (nums[slow] > 0) != isForward){
                        valid = false;
                        break;
                    }

                    fast = getNext(fast, nums);
                    if (fast == -1e7 || (nums[fast] > 0) != isForward) { valid = false; break; }

                    fast = getNext(fast, nums);
                    if (fast == -1e7 || (nums[fast] > 0) != isForward) { valid = false; break; }

                } while(slow != fast);

                if(valid){
                    return true;
                }

                slow = i;
                while (nums[slow] != 0 && (nums[slow] > 0) == isForward) {
                    int nextIndex = getNext(slow, nums); // 1. Grab the next index while the current value is still valid
                    nums[slow] = 0;                     // 2. Safely mark the current index as visited
                    if (nextIndex == -1e7) break;       // 3. Stop if it hits a dead end (like a 1-element loop)
                    slow = nextIndex;                   // 4. Move to the next index
                }

            }
        }

        return false;
        
    }
};