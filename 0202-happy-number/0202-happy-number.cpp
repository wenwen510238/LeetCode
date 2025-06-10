class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while(fast != 1 && slow != fast){
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
    int getNext(int n){
        int sum = 0;
        while(n){
            sum += pow((n % 10), 2);
            n /= 10;
        }
        return sum;
    }
};