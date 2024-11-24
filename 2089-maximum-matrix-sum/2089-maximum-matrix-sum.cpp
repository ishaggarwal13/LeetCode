class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int ct=0;
        long long sum=0,minm=1e9;

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]<0)
                ct++;

                sum+=abs(matrix[i][j]);

                minm=min(minm ,(long long) abs(matrix[i][j]));
            }
        }

        if(ct%2==0)
        return sum;

        return sum-2*minm;
    }
};