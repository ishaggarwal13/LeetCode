class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //preffix sum by using set
        unordered_set<int> s;
        for(auto i : nums){
            s.insert(i);
        }
        //sum of unique elemets and double it 
        int sum=0;
        for(auto i : s){
            sum += i;
        }
        sum = sum*2;
        //now sub the nums array sum from double unique elemets sum as other elemet appear two times
        int sumOriginal = accumulate(nums.begin(), nums.end(), 0);
        return sum - sumOriginal;
    }
};