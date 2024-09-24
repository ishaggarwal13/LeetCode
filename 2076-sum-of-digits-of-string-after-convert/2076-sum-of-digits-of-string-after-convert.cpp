class Solution {
public:
    int getLucky(string s, int k) {
        int len = s.length();
      string numstr;
      for(char c : s)
      {
        numstr += to_string(c - 'a' + 1);
      }
      int num;
      while(k > 0)
      {
        num = 0;
      for( char c : numstr)
      {
        num += c - '0';
      }
      numstr = to_string(num);
      k--;
      }
      return num;
    }
};