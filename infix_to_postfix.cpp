
#include<bits/stdc++.h>
using namespace std;

int prio(char ch){
    if(ch=='+' || ch=='-') return 1;
    else return 2;
}

string solve(string val1, string val2, char ch){
    string s ="";
    s+=val1;
    s+=val2;
    s.push_back(ch); 
    return s;
}

int main(){
    string str = "(7+9)*4/8-3";
    stack<string> val;
    stack<char> op;

    for(int i=0; i<str.size(); i++){
        if(str[i]>=48 && str[i]<=57){
            val.push(to_string(str[i]-48));
        }
        else{
            if(op.size()==0) op.push(str[i]);
            else if(str[i]=='(' ) op.push(str[i]);
            else if(op.top()=='(') op.push(str[i]);
            else if(str[i]==')'){
                while(op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.pop();
            }
            else if(prio(str[i])>prio(op.top())){
                op.push(str[i]);
            }
            else{
                while(op.size()>0 && prio(str[i])<=prio(op.top())){
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.push(str[i]);
            }
        }
    }

    while(op.size()>0){
       char ch = op.top();
    op.pop();
    string val2 = val.top();
    val.pop();
    string val1 = val.top();
    val.pop();
    string ans = solve(val1, val2, ch);
    val.push(ans);
    }

    cout<<val.top()<<endl;
    return 0;
}
