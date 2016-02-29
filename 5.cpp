class Solution {
public:
    bool isP(int a,int b,set<pair<int,int> > & M){
        if(a>=b) return true;
        return M.count(pair<int,int>(a,b))>0;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int ans = -1,idx=-1;
        int H[n][n];
        memset(H,0,sizeof(H));
        for(int i=0;i<n;i++)
            H[i][i]=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(s[i]==s[j] && (i<=(j+1) || H[j+1][i-1])){
                    if(i-j+1>=ans){
                        ans = i-j+1;
                        idx = j;
                    }
                    H[j][i]=1;
                }
                else {
                }
            }
        }
        return s.substr(idx,ans);
        
    }
};
