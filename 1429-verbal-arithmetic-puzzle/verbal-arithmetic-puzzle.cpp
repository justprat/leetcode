class Solution {
public:

    bool solve(int idx ,vector<int> &taken, vector<pair<char,int>> &uniqueChars,
            vector<long long> &weights , bool cannotBeZero[], long long currentSum){

        // Base case: all characters assigned
        if(idx == uniqueChars.size()){
            return (currentSum == 0);
        }

        //try to take an unused value 
        for(int val = 0 ; val <= 9 ; val++){

            if(taken[val]) continue;
            if(val == 0 && cannotBeZero[uniqueChars[idx].first - 'A']) continue;

            taken[val] = 1;
            long long nextSum = currentSum + (weights[idx] * val);
            
            if(solve(idx+1, taken, uniqueChars, weights, cannotBeZero, nextSum)) return true;
            taken[val] = 0;  
        }

        return false;
    }

    bool isSolvable(vector<string>& words, string result){

        unordered_map<char,long long> charToWeight;
        vector<pair<char,int>> uniqueChars;
        bool cannotBeZero[26] = {false};

        //1. map chars
        for(int i = 0 ; i < words.size() ; i++){
            if(words[i].size() > 1) cannotBeZero[words[i][0] - 'A'] = true;
            for(int j = 0 ; j < words[i].size() ; j++){
                if(charToWeight.count(words[i][j])) continue;
                charToWeight[words[i][j]] = 0;
                uniqueChars.push_back({words[i][j],-1});
            }
        }

        if(result.size() > 1) cannotBeZero[result[0] - 'A'] = true;
        for(int i = 0 ; i < result.size() ; i++){
            if(charToWeight.count(result[i])) continue;
            charToWeight[result[i]] = 0;
            uniqueChars.push_back({result[i],-1});
        }

        //2. add weights
        for(int i = 0 ; i < words.size() ; i++){
            int right = words[i].size();
            for(int left = 0; left < right ; left++){
                charToWeight[words[i][left]] += (long long) pow(10,right - left - 1);
            }
        }

        //3.subtract result weights
        for(int left = 0 ; left < result.size() ; left++){
            charToWeight[result[left]] -= (long long) pow(10,result.size() - left - 1);
        }
        
        //4. map -> array 
        vector<long long> weights(uniqueChars.size());
        for(int i = 0; i < uniqueChars.size(); i++){
            weights[i] = charToWeight[uniqueChars[i].first];
        }

        vector<int> taken(10,0);
        return solve(0, taken, uniqueChars, weights, cannotBeZero, 0);
    }
};