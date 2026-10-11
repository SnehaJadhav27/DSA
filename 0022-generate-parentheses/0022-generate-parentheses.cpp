class Solution {
public:
    
       void solve(int open,int close,int n,string &tmp, vector<string> &result)
       {

        if(open==n && close==n){
            result.push_back(tmp);
            return;
        }

        if(open<n){
            tmp.push_back('(');
            solve(open+1,close,n,tmp,result);
            tmp.pop_back();
        }

        if(close<open){
            tmp.push_back(')');
            solve(open,close+1,n,tmp,result);
            tmp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string tmp;
        vector<string> result;
        solve(0,0,n,tmp,result);
        return result;
    }
    
};