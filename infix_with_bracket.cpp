
#include<bits/stdc++.h>
using namespace std;

int prio(char ch){
    if(ch=='+' || ch=='-') return 1;
    else return 2;
}

int solve(int val1, int val2, char ch){
    if(ch=='+') return val1+val2;         //evaluation = numerical value
    else if(ch=='-') return val1-val2;    //expresion conversion = ---
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}

int main(){
    string str = "1+(2+6)*4/8-3";
    stack<int> val;
    stack<char> op;

    for(int i=0; i<str.size(); i++){
        if(str[i]>=48 && str[i]<=57){
            val.push(str[i]-48);
        }
        else{
            if(op.size()==0) op.push(str[i]);
            else if(str[i]=='(' ) op.push(str[i]);
            else if(op.top()=='(') op.push(str[i]);
            else if(str[i]==')'){
                while(op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, val2, ch);
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
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.push(str[i]);
            }
        }
    }

    while(op.size()>0){
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1, val2, ch);
        val.push(ans);
    }

    cout<<val.top()<<endl;
    cout<<1+(2+6)*4/8-3<<endl;
    return 0;
}
