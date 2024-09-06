 #include<bits/stdc++.h>
 using namespace std;
int solve(int val1, int val2, char ch){
    if(ch=='+') return val1+val2;        
    else if(ch=='-') return val1-val2; 
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}
 int main(){
    string str = "-/*+79483";
    stack<int> val;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9'){
            val.push(str[i]-48);
        }
        else{
            int val1 = val.top();
            val.pop();
            int val2 = val.top();
            val.pop();
            int ans = solve(val1,val2,str[i]);
            val.push(ans);
        }
    }
    cout<<val.top()<<endl;
    return 0;
 }