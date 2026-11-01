class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size() < t.size()){
            return "";
        }

        //1. map out need
        unordered_map<char,int> need;
        for(char c : t){
            need[c]++;
        }

        int minLen = INT_MAX;
        int minStart = -1;
        int l = 0;
        int missing = t.size();

        for(int r = 0 ; r < s.size() ; r++){
            
            //consume in window
            if(need.find(s[r]) != need.end()){
                
                need[s[r]]--; //pick it 

                if(need[s[r]] >= 0){ //if freq less than 0 , no need to count it as missing
                    missing--;
                }
            }

            //what if window satisfied?
            while(missing == 0){
                
                if(r - l + 1 < minLen){//store ans
                    minLen = r - l + 1;
                    minStart = l;
                }

                if(need.find(s[l]) != need.end()){//update if needed
                
                    need[s[l]]++;

                    if(need[s[l]] > 0){//we lost a needful character
                        missing++;
                    }
                }

                l++;
            }

        }

        if(minStart == -1){
            return "";
        }

        return s.substr(minStart,minLen);
        
    }
};