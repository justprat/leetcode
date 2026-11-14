class Solution {
public:
    int res = INT_MAX;

    void solve(int i ,vector<int> &jobs , vector<int> &workers ,int highestJob){

        int n = jobs.size();

        if(i == n){
            res = min(res,highestJob);
            return;
        }

        for(int k = 0 ; k < workers.size() ; k++){
            workers[k] += jobs[i];
            solve(i + 1,jobs,workers,max(highestJob,workers[k]));
            workers[k] -= jobs[i];
            if(workers[k] == 0) break;
        }

    }

    int minimumTimeRequired(vector<int>& jobs, int k) {

        sort(jobs.rbegin(),jobs.rend());

        vector<int> workers(k,0);

        solve(0,jobs,workers,0);

        return res;
        
    }
};