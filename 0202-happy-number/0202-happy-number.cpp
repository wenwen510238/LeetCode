class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> exist;
        while(n!=1){
            int add = 0;
            while(n){
                int squre = pow(n % 10, 2);
                add += squre;
                n /= 10;
            }
            if(exist.count(add)) return false;
            else exist.insert(add);
            n = add;
        }
        return true;
    }
};