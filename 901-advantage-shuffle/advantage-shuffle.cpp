class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        
        //step 1: record old index
        vector<pair<int,int>> sortedNums2;
        for(int j = 0 ; j < n ; j++){
            sortedNums2.push_back({nums2[j],j});
        }

        sort(nums1.begin(),nums1.end());
        sort(sortedNums2.begin(),sortedNums2.end());

        //step 2 : run 2 pointers ( algo : just allocate slightly better , so most room for future)
        //if u lose , allocate the weakest
        //2 pointers does this naturally

        int i = 0;
        int j = 0;

        vector<int> ans(n,-1);
        vector<int> skipped;

        while(i < n && j < n){

            if(nums1[i] > sortedNums2[j].first){ //we win , allocate this cheapest
                ans[sortedNums2[j].second] = nums1[i];
                i++;
                j++;
            }

            else{//we lose , skip -> we allocate later randomly
                skipped.push_back(nums1[i]);
                i++;
            }
        }

        //step 3: allocate remaining anywhere
        i = 0;
        j = 0;

        while(i < n && j < skipped.size()){

            if(ans[i] == -1){
                ans[i] = skipped[j];
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return ans;
        
    }
};