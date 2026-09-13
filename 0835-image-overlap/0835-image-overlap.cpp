class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> A,B;
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(img1[i][j]==1) A.emplace_back(i,j);
                if(img2[i][j]==1) B.emplace_back(i,j);
            }
        }
        vector<vector<int>> cnt (2*n,vector<int>(2*n));
        int maxCount = 0;
        for(pair<int,int>&a : A){
            for(pair<int,int>&b : B){
                int dx = b.first-a.first+n;
                int dy = b.second - a.second + n;
                cnt[dx][dy]++;
                maxCount = max(maxCount , cnt[dx][dy]);
            }
        }
        return maxCount;
    }
};