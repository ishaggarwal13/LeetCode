class Solution {
public:
    static long long maxKelements(vector<int>& nums, int k) {
        //initalize priority queue with greatest element first
        //decalre long long value of maximum sum of values after k operations
        //proceed the loop from i=0 to k-1
        //let decalre top as x and add to score
        //if x==1 add k-1-i to score and break with early stop
        //pop the pq
        //psh the ceil value which ceil(nums[i] / 3) or (nums[i] + 2)/3
        //score is teh answer
        make_heap(nums.begin(), nums.end());
        long long score=0;
        for(int i=0; i<k; i++){
            pop_heap(nums.begin(), nums.end());
            int x=nums.back();
            score+=x;
            if (x==1){
                score+=(k-1-i);
                break;
            }
            nums.back()=(x+2)/3;
            push_heap(nums.begin(), nums.end());
        }
        return score;
    }
};