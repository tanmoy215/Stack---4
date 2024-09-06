#include<bits/stdc++.h>
using namespace std;
int prio(char ch){
    if(ch=='*' || ch=='/') return 2;
    else return 1;
}
int solve(int val1, int val2,char ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}
int main(){
    string str = "2+3*6/3-3";
    stack<int> val;
    stack<char> op;
    for(int i=0;i<str.size();i++){
        //check if str[i] is a digit (0-9)
        if(str[i]>=48 && str[i]<=57){
            val.push(str[i]-48);
        }
        else{    //str[i] is not a digit (+,-,*,/, etc.)
                if(op.size()==0 || prio(str[i])>prio(op.top())){
                    op.push(str[i]);
                }
                else {
                    while(op.size()>0 && prio(str[i])<=prio(op.top())){
                        char ch = op.top();
                         op.pop();
                         int val2 = val.top();
                         val.pop();
                         int val1 = val.top();
                         val.pop();
                         int ans = solve(val1,val2,ch);
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
        int ans = solve(val1,val2,ch);
        val.push(ans);
    }
    cout<<val.top()<<endl;
    cout<<2+3*6/3-3<<endl;
    return 0;
}