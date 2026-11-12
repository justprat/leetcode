class Solution {
public:
    void solve(int i , string &s , string &temp , vector<string>& ans , int dots){

        int n = s.size();

        if(i == n){
            if(dots == 3){
                ans.push_back(temp);
            }
            return;
        }

        for(int j = i ; j < n ; j++){

            if(j - i + 1 > 3) break;
            if(j > i && s[i] == '0') break;

            string curr = s.substr(i,j-i+1);
            int num = stoi(curr);

            if(i == 0){// very first string (no dot)
                if(num <= 255){
                    string prev = temp;
                    temp += curr;
                    solve(j+1,s,temp,ans,dots);
                    temp = prev;
                }
            }

            else{
                if(num <= 255){
                    string prev = temp;
                    temp += "." + curr;
                    solve(j+1,s,temp,ans,dots+1);
                    temp = prev;
                }
            }
        }

    }


    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp;
        solve(0,s,temp,ans,0);

        return ans;
        
    }
};