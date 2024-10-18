class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        val_and_index = sorted([(num, i) for i, num in enumerate(nums)])
        return [num for num, i in sorted(val_and_index[-k :], key=lambda x: x[1])]