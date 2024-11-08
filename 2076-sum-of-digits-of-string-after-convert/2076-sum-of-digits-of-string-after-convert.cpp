class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
        for(auto x:s)
        {
            int digit=x-'a'+1;
            sum+=(digit/10)+(digit%10);

        }
        while(k>1)
        {
            sum=digitsum(sum);
            k--;
        }
        return sum;
    }

        int digitsum(int num)
        {
            int sum = 0;
            while (num > 0)
             {
                sum += num % 10;
                num /= 10;
        }
            return sum;
        }
};