class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int waterCount = 0;

        int left = 0;
        int right = n - 1;

        int leftMax = height[0];
        int rightMax = height[n-1];

        while(left < right){

            if(leftMax < rightMax){

                left++;

                if(height[left] < leftMax){
                    waterCount += leftMax - height[left];
                }

                else{
                    leftMax = height[left];
                }
            }

            else{

                right--;

                if(height[right] < rightMax){
                    waterCount += rightMax - height[right];
                }

                else{
                    rightMax = height[right];
                }

            }
        }

        return waterCount;
        
    }
};