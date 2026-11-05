class Solution {
public:
    int countTriplets(vector<int>& arr) {

        //prefixXor count+= i - j (len 3 -> 2 triplet)(len 4 -> 3 triplets)
        //total count for all indices j .... i
        //count = (i - j0) + (i - j1) + (i - j2) + ...
        //count = (j * ctimes ) - Sum of indices j

        unordered_map<int,pair<int,int>>mp;
        mp[0] = {1,-1}; //mp -> preXor -> {timesSeen,sumofindices}

        int preXor = 0;
        int count = 0;

        for(int i = 0 ; i < arr.size() ; i++){

            preXor ^= arr[i];

            if(mp.count(preXor)){
                pair<int,int> temp = mp[preXor];
                count = count + (temp.first * (i - 1)) - temp.second;
                mp[preXor] = {temp.first+1,temp.second+i};
            }
            else{
                mp[preXor] = {1,i};
            }

        }

        return count;
        
    }
};