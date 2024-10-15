class Solution {
    public long minimumSteps(String s) {
        int black = 0;
        long swap = 0;
        // convert string into char of array
        for(char c : s.toCharArray()){
            if(c == '1'){
                black++;
            } else {
                swap += black;
            }
        }
        return swap;
    }
}