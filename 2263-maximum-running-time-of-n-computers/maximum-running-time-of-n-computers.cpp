class Solution {
public:
    bool verify(int n , long long mid , vector<int>& batteries){

        long long need = 1LL * mid * n;
        long long present = 0;

        for(int b : batteries){
            present += min(1LL * b,mid);
        }

        return present >= need;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        
        if(batteries.size() == n){
            return *min_element(batteries.begin(),batteries.end());
        }

        long long s = 0;
        long long e = 0;

        long long ans = -1;

        for(int i = 0 ; i < batteries.size() ; i++){
            e = e + batteries[i];
        }

        while(e >= s){

            long long mid = s + (e-s)/2;

            if(verify(n,mid,batteries)){
                ans = mid;
                s = mid + 1;
            }

            else{
                e = mid - 1;
            }

        }

        return ans;
    }
};