class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int> mp;

        int l = 0;
        int maxFreq = 0;
        int maxAns = 0;

        for(int r = 0 ; r < s.size() ; r++){
            
            mp[s[r]]++;

            maxFreq = max(mp[s[r]],maxFreq);

            while(r - l + 1 - maxFreq > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }

            maxAns = max(maxAns,r - l + 1);

        }

        return maxAns;
        
    }
};