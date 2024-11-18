class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(); // circular array
        vector<int> result(n, 0);

        if (k == 0) return result;

        if(k>0){
            int sum = accumulate(code.begin()+1, code.begin()+k+1, 0);
            result[0] = sum;
            for(int left=1, right=k+1; left<n; right++, left++){
                sum += -code[left] + code[right%n];
                result[left] = sum;
            }
            return result;
        }

        k = -k;
        int sum = accumulate(code.end()-k, code.end(), 0);
        result[0] = sum;
        for(int right=0, left=n-k; right<n-1; right++, left++){
            sum += -code[left%n] + code[right];
            result[right+1] = sum;
        }
        
        return result;
    }
};