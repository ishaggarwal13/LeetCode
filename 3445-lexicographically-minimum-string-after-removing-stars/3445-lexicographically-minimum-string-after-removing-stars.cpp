class Solution {
public:
    string clearStars(string s) {
        //using priority queue as to remove the smallest char to the left of * need to 
        //make a prioroty queue asenceding order to remove top char
        priority_queue<char, vector<char>, greater<char>> pq;
        //vector of vector to store the index of each char in s
        vector<vector<int>> pos(26);

        for(int i=0; i<s.size(); i++){
            if(s[i] == '*'){
                //storing the top smallest left to the star char and 
                //store * to that smallest char and pop the index from pos
                //if pos is empty of that char tehn pop it from queue also
                char ch = pq.top();
                s[pos[ch - 'a'].back()] = '*';
                pos[ch-'a'].pop_back();
                if(pos[ch - 'a'].empty()) pq.pop();
            } else {
                //if char is not already added to pos then we can push to queue
                //checking to avoid duplicates in queue
                //then adding teh index to that char to pos vector of vectors
                if(pos[s[i] - 'a'].empty()) pq.push(s[i]);
                pos[s[i] - 'a'].push_back(i);
            }
        }

        string res;
        for(char ch: s){
            if(ch >= 'a') res += ch;
        }
        return res;
    }
};