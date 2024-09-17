class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, k=m+n-1;
        while(i>=0 && j>=0){
            if(nums2[j] > nums1[i]){ //check is last element of nums2 is greater than nums1 last element
                nums1[k] = nums2[j]; //set nums2 last element at m+n last place
                k--; //dec both k and j
                j--; 
            } else{
                nums1[k] = nums1[i]; //set nums1 element at i place to k place
                i--;
                k--;
            }
        }
        while(i >= 0){
            nums1[k--] = nums1[i--];
        }
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};