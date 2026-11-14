class Solution {
public:
    bool solve(vector<double> &pool){

        if(pool.size() == 1){
            if(abs(pool[0]  - 24) < 1e-5) return true;
            else return false;
        }

        //pick any 2 numbers
        for(int i = 0 ; i < pool.size() ; i++){

            for(int j = 0 ; j < pool.size() ; j++){

                if(i == j) continue;

                vector<double> newPool;
                for(int k = 0 ; k < pool.size() ; k++){

                    if(k == i || k == j) continue;

                    newPool.push_back(pool[k]);
                }

                vector<double> results = {
                    pool[i] + pool[j],
                    pool[i] - pool[j],
                    pool[j] - pool[i],
                    pool[i] * pool[j]
                };

                if(abs(pool[j]) > 1e-5) results.push_back(pool[i] / pool[j]);
                if(abs(pool[i]) > 1e-5) results.push_back(pool[j] / pool[i]);

                for(auto res : results){
                    newPool.push_back(res);
                    if(solve(newPool)) return true;
                    newPool.pop_back();  
                }
            }
        }

        return false;

    }

    bool judgePoint24(vector<int>& cards) {
        
        vector<double>pool(4);
        for(int i = 0 ; i < 4 ; i++){
            pool[i] = cards[i];
        }

        return solve(pool);
    }
};