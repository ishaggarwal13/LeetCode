class Solution {
    public int minGroups(int[][] intervals) {
        List<Integer> start = new ArrayList<>();
        List<Integer> end = new ArrayList<>();

        for(int[] interval : intervals){
            start.add(interval[0]);
            end.add(interval[1]);
        }

        Collections.sort(start);
        Collections.sort(end);

        int groupCount = 0;
        int endPtr = 0;

        for(int s : start){
            if(s > end.get(endPtr)){
                endPtr++;
            } else {
                groupCount++;
            }
        }
        return groupCount;
    }
}