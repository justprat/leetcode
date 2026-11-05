class Solution {
public:

    bool isVowel(char &c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }

    long long beautifulSubstrings(string s, int k) {

        int n = s.size();
        
        map<pair<int,int>,long long> mp;
        mp[{0,0}] = 1;

        //smallest pos integer m such that m2 % k = 0
        int m = 1;
        while ((m * m) % k != 0) {
            m++;
        }

        long long count = 0;
        int vowels = 0;
        int consonants = 0;

        for(int i = 0 ; i < n ; i++){
            
            if(isVowel(s[i])){
                vowels++;
            } 
            else{
                consonants++;
            }

            int t1 = vowels - consonants;
            int t2 = vowels % m;
            pair<int,int> target = {t1,t2};
            count += mp[target];

            mp[{t1,t2}]++;
        }

        return count;
        
    }
};