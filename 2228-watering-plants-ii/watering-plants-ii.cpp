class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {

        int n = plants.size();

        int refills = 0;
        int left = 0;
        int right = n - 1;

        int remainA = capacityA;
        int remainB = capacityB;

        while(left < right){

            if(plants[left] > remainA){
                refills++;
                remainA = capacityA;
            }

            remainA -= plants[left];
            left++;

            if(plants[right] > remainB){
                refills++;
                remainB = capacityB;
            }

            remainB -= plants[right];
            right--;
        }

        if(left == right){
            if(max(remainA,remainB) < plants[left]){
                refills++;
            }
        }

        return refills;
        
    }
};