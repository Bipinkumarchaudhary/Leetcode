class Solution {
public:
    string solve(int n){
        if(n==1){
            return "1";
        }
        string s= solve(n-1);
        int count=1,i=1,num=s[0]-'0';
        string ans="";
        while(i<s.length()){
            if((s[i]-'0')==num){
                count++;
            }
            else{
                ans+=to_string(count);
                count=1;
                ans+=to_string(num);
                num=s[i]-'0';
            }
            i++;
        }
        ans+=to_string(count);
        ans+=to_string(num);
        return ans;
    }
    string countAndSay(int n) {
        string res= solve(n);
        return res;
    }
};