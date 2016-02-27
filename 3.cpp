class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> M;
        int ans=0;
        int n=s.size();
        int ptr = -1;
        
        for(int i=0;i<n;i++){
            if(M.count(s[i])==0){
                ans = max(ans,i-ptr);
                M[s[i]] = i;
            }
            else{
                ptr=max(ptr,M[s[i]]);
                ans = max(ans,i-ptr);
                M[s[i]] = i;
            }
        }
        return ans;
        
    }
};
