class Solution {
    public long minimumSteps(String s) {
        int black = 0;
        long swap = 0;
        // convert string to char
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '1'){
                black++;
            } else {
                swap += black;
            }
        }
        return swap;
    }
}