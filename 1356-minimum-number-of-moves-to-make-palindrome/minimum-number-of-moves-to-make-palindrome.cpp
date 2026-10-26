class Solution {
public:
    int minMovesToMakePalindrome(string s) {

        int moves = 0;

        int left = 0;
        int right = s.size()-1;

        while(left < right){

            if(s[left] == s[right]){
                left++;
                right--;
            }

            else{// we move left side

                //1. find the character
                int temp = left;
                while(temp < right && s[temp] != s[right]){
                    temp++;
                }

                if(temp == right){//wrong char to match , we have to handle right side now

                    //1.
                    int temp = right;
                    while(temp > left && s[temp] != s[left]){
                        temp--;
                    }

                    //2
                    while(temp != right){
                        swap(s[temp],s[temp+1]);
                        temp++;
                        moves++;
                    }

                }

                else{
                    //2. bring the char back to left
                    while(temp != left){
                        swap(s[temp],s[temp-1]);
                        temp--;
                        moves++;
                    }
                }

                //3. done
                left++;
                right--;
                
            }
        }

        return moves;
        
    }
};