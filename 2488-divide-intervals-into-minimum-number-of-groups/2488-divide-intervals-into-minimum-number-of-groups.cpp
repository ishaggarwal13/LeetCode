class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // creating vectors for start and end time
        // pushing teh elements of intervals speratly into start and end vectors
        // sorting both the vectors ascending
        // declare group count and end pointer and then traverse over start time
        // will check that start > end time so that it is not overlapping and 
        // will inc the count of end time
        // else ->it is overlapping inc the gorup count
        // return group count

        vector<int> start, end;

        for(auto interval : intervals){
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int groupcount=0, end_pt=0;
        for(auto s : start){
            if(s > end[end_pt]){
                end_pt++;
            } else {
                groupcount++;
            }
        }

        return groupcount;
    }
};