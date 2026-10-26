class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<pair<int,int>> paired;
        for(int i = 0 ; i < difficulty.size() ; i++){
            paired.push_back({difficulty[i],profit[i]});
        }

        sort(paired.begin(),paired.end());
        sort(worker.begin(),worker.end());

        int i = 0;
        int j = 0;
        int maxProfit = 0;
        int res = 0;

        while(i < paired.size() && j < worker.size()){

            if(paired[i].first > worker[j]){//if job is harder
                res += maxProfit; //take the best prev profit
                j++; //move on to the next worker
            }

            else{//job is easy
                maxProfit = max(maxProfit,paired[i].second);
                i++;
            }
        }

        while(j < worker.size()){//take remaining jobs 
            res += maxProfit;
            j++;
        }

        return res;
    }
};