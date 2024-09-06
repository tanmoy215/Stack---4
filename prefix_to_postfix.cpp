 #include<bits/stdc++.h>
 using namespace std;
string solve(string val1, string val2,char ch){
    string s = "";
    s+=val1;
    s+=val2;
    s.push_back(ch);
    return s;
}
 int main(){
    string str = "-/*+79483";  //prefix expresion
    stack<string> val;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9'){
            val.push(to_string(str[i]-48));
        }
        else{
            string val1 = val.top();
            val.pop();
            string val2 = val.top();
            val.pop();
            string ans = solve(val1,val2,str[i]);
            val.push(ans);
        }
    }
    cout<<val.top()<<endl;
    return 0;
 }