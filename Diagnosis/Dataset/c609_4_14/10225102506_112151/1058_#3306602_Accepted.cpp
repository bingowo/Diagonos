#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct BIGINT{
    int cnt;
    int v[101];
};

void DIV2(BIGINT *n){
    int carry=0;
    if(n->v[n->cnt-1]<2) n->cnt--,carry=1;
    for(int i=n->cnt-1;i>=0;i--){
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
}

void ADD1(BIGINT *n){
    int carry=0,i=1;
    n->v[0]=n->v[0]+1;
    carry=n->v[0]/10;
    n->v[0]=n->v[0]%10;
    while(carry!=0 && i<n->cnt){
        n->v[i]+=carry;
        carry=n->v[i]/10;
        n->v[i]=n->v[i]%10;
        i++;
    }
    if(carry!=0){
        n->v[i]=carry;
        n->cnt++;
    }
}
int main()
{
    string s;
    cin >> s;
    string ss(s,1,s.length()-1);
    string::reverse_iterator it;
    int sign=1;
    BIGINT n={0,{0}};
    for(it=ss.rbegin();it!=ss.rend();++it)
        n.v[n.cnt++]=*it-'0';
    if(s[0]=='-')   sign=-1;
    else    n.v[n.cnt++]=s[0]-'0';
    int bin[400]={0},cnt=0;
    while(n.cnt>0){
        int temp=n.v[0]%2;
        bin[cnt++]=temp;
        DIV2(&n);
        if(sign==-1 && temp){
            if(n.cnt==0){n.cnt++; n.v[0]=1;}
            else ADD1(&n);
        }
        sign=-sign;
    }
        for(int i=cnt-1;i>=0;i--)
            cout << bin[i];
        cout << endl;
    return 0;
}

