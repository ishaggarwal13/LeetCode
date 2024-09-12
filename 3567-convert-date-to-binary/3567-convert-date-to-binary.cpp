class Solution {
public:
    string convert(bitset<32>& num){
        string s = num.to_string(); //convert bitset into binary string

        int index = s.find('1'); //finding first 1 index

        return s.substr(index);
    }
    string convertDateToBinary(string date) {
        bitset<32> year(stoi(date.substr(0, 4)));
        bitset<32> mon(stoi(date.substr(5, 2)));
        bitset<32> d(stoi(date.substr(8, 2)));

        string ans = convert(year);
        ans += "-" + convert(mon);
        ans += "-" + convert(d);

        return ans;
    }
};