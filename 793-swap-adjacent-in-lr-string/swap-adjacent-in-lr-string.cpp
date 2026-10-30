class Solution {
public:
    bool canTransform(string start, string result) {


        int p1 = 0;
        int p2 = 0;
        int n = start.size();

        while (p1 < n || p2 < n) {

            // 1. Skip x in start
            while (p1 < n && start[p1] == 'X') {
                p1++;
            }
            // 2. Skip x in res
            while (p2 < n && result[p2] == 'X') {
                p2++;
            }

            // If one string ran out of characters but the other didn't
            if ((p1 == n) != (p2 == n)) {
                return false;
            }

            // both reached end -> return true
            if (p1 == n && p2 == n) {
                break;
            }

            //if mismatch
            if (start[p1] != result[p2]) {
                return false;
            }

            //below no mismatch , only rules:


            //  L can move left , if its right -> false
            if (start[p1] == 'L' && p1 < p2) {
                return false;
            }
            //  R can move right , if its left -> false
            if (start[p1] == 'R' && p1 > p2) {
                return false;
            }

            // next scan
            p1++;
            p2++;
        }

        return true;
    }
};
