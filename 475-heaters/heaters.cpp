class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        int m = houses.size();
        int n = heaters.size();

        int heater_ptr = 0;
        int maxRad = 0;

        for(int i = 0 ; i < m ; i++){

            while(heater_ptr + 1 < n && abs(heaters[heater_ptr] - houses[i]) >= abs(heaters[heater_ptr+1] - houses[i])){ 
                heater_ptr++;
            }
            
            maxRad = max(abs(heaters[heater_ptr] - houses[i]),maxRad);

        }

        return maxRad;

    }
};