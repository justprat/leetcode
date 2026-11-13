class Solution {
public:
    int getFact(int n){

        if(n == 0 || n == 1) return 1;

        return n * getFact(n-1);

    }

    string getPermutation(int n, int k) {

        k--;

        vector<int> vals = {1,2,3,4,5,6,7,8,9};

        string res;

        while(k){

            int pos = getFact(n - 1);
            int idx = k /pos;

            res += to_string(vals[idx]);
            vals.erase(vals.begin() + idx);

            k = k % pos;
            n--;

        }

        while(n){
            res += to_string(vals[0]);
            vals.erase(vals.begin());
            n--;
        }
        

        return res;
        
    }
};