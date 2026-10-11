class Solution {
public:
    unordered_map<char,string> f;

    void solve(string digits,int n,int idx,string &diary,vector<string>& result){
          if(idx==n){
            result.push_back(diary);
            return;
          }

          string choice=f[digits[idx]];

          for(int j=0;j<choice.size();j++){
            diary.push_back(choice[j]);
            solve(digits,n,idx+1,diary,result);
            diary.pop_back();
          }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        f['2']="abc";f['3']="def";f['4']="ghi";f['5']="jkl";f['6']="mno";f['7']="pqrs";f['8']="tuv";f['9']="wxyz";

        int n=digits.size();
        string diary="";
        vector<string> result;
        solve(digits,n,0,diary,result);
        return result;
    }
};