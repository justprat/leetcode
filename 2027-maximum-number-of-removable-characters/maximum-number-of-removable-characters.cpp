class Solution {
public:
    int maximumRemovals(string r, string p, vector<int>& removable) {

        int n = removable.size();

        //store orignal order
        vector<pair<int,int>> sorted_indices;
        for(int i = 0 ; i < n ; i++){
            sorted_indices.push_back({removable[i],i});
        }

        sort(sorted_indices.begin(),sorted_indices.end());

        int s = 0;
        int e = n ;
        int ans = 0;

        while(e >= s){
            
            int mid = s + (e - s) / 2;

            //1. remove mid indices
            int i = 0;
            int j = 0;
            int k = 0;
            int remove = 0;

            //2. two pointers to check subseq in o(n)
            while(i < r.size() && j < p.size()){
                
                if(remove < mid && sorted_indices[k].first == i){

                    if(sorted_indices[k].second < mid){
                        i++;
                        k++;
                        remove++;
                    }
                    else{
                        k++;
                    }

                }

                else{

                    if(r[i] == p[j]){
                        i++;
                        j++;
                    }

                    else{
                        i++;
                    }

                }

            }

            if(j == p.size()){//reached end -> valid , find a larger k
                ans = mid;
                s = mid + 1;
            }
            else{ // too many removals -> reduce 
                e = mid - 1;
            }
        }

        return ans;
        
    }
};