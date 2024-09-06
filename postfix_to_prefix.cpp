#include<bits/stdc++.h>
using namespace std;
string solve(string val1,string val2, char ch){
    string s = "";
    s.push_back(ch);
    s+=val1;
    s+=val2;
    return s;                            
}
int main(){
    string str = "79+4*8/3-";
    stack<string> val;
   for(int i=0;i<str.size();i++){
     if(str[i]>='0' && str[i]<='9'){
            val.push(to_string(str[i]-48));
       }
       else{
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = solve(val1,val2,str[i]);
        val.push(ans);
       }
   }
   cout<<val.top()<<endl;
     return 0;
}