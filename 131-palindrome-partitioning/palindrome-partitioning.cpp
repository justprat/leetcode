class Solution {
public:
    bool isPal(string &s){

        int i = 0;
        int j = s.size() - 1;

        while(j > i){

            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;

    }

    void solve(vector<string> &temp , vector<vector<string>> &ans , string &s , int i){

        int n = s.size();

        if(i == n){
            ans.push_back(temp);
            return;
        }

        for(int j = i ; j < n ; j++){

            string curr = s.substr(i, j - i + 1);

            if(isPal(curr)){
                temp.push_back(curr);
                solve(temp,ans,s,j+1);
                temp.pop_back();
            }
        
        }

    }

    vector<vector<string>> partition(string s){
        vector<string> temp;
        vector<vector<string>> ans;
        solve(temp,ans,s,0);
        return ans;
    }
};