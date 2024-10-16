class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // making max heap as priroity queue storing the count and char for a, b, c
        // declare empty string for res and 
        // start while condition which check is pq is empty
        // now extracting top which is hightest count with its char and
        // checking the conditions if res size is greater than two and check for both char is same in res
        // then check pq empty , no char left
        // get the second highest count from its top
        // now add that count to res and count--
        // check second highest count is not 0 then again push into queue
        // same for highestes count push that to queue
        // now else condition where we are pushing teh highest count char into res string 
        // make the highest count-- and push is it back to queue if count is not 0
        // return string res

        priority_queue<pair<int, char>> pq;
        if(a>0) pq.push({a, 'a'});
        if(b>0) pq.push({b, 'b'});
        if(c>0) pq.push({c, 'c'});

        string res = "";

        while(!pq.empty()){
            auto [count1, char1] = pq.top();
            pq.pop();

            if(res.size() >= 2 && res.back() == char1 && res[res.size()-2] == char1){
                if(pq.empty()) break;

                auto [count2, char2] = pq.top();
                pq.pop();

                res += char2;
                count2--;

                if(count2 > 0) pq.push({count2, char2});

                pq.push({count1, char1});
            } else {
                res += char1;
                count1--;

                if(count1 > 0) pq.push({count1, char1});
            }
        }
        return res;
    }
};