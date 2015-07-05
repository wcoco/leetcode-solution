class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> numbers;
        int k = 10;
        while(1){
            int tmp = 0;
            while(n){
                int digit = n % k;
                tmp += digit * digit;
                n /= k;
            }
            if(tmp == 1)
                return true;
            if(numbers.find(tmp) != numbers.end())
                return false;
            numbers[tmp] = true;
            n = tmp;
        }
    }
};