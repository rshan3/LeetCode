class Solution {
public:

    bool helper(string & s,int p1,string & p,int p2, vector<int> & star){
        if(p1==s.size()&&p2==p.size()) return true;
        if(p2==p.size()) return false;
        
        while(p1<s.size() && p2<p.size()){
            if(!star[p2]){
                if(s[p1]==p[p2]||p[p2]=='.'){
                    p1++;
                    p2++;
                }
                else return false;
            }
            else{
                bool ret = helper(s,p1,p,p2+1,star);
                if(ret) return true;
                
                while(p1<s.size()&&(s[p1]==p[p2]||p[p2]=='.')){
                    ret = helper(s,p1+1,p,p2+1,star);
                    if(ret) return true;
                    
                    p1++;
                }
                return false;
            }
        }
        
        while(p2<p.size() && star[p2]) p2++;
        
        return p1==s.size() && p2==p.size();
    }
    
    bool isMatch(string s, string p) {
        string pp("");
        vector<int> star;
        int k=0;
        for(int i=0;i<p.size();i++){
            if(p[i]!='*') {
                pp.push_back(p[i]);
                star.push_back(0);
                ++k;
            }
            else star[k-1]=1;
        }

        return helper(s,0,pp,0,star);
    }

};
