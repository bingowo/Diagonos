#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f(char* s,int sig,int cishu,int weizhi)
{
    int ans=0;
    char c=s[weizhi];
    weizhi++;
    if(weizhi==strlen(s)) return 1;
    if((sig<0)&&(c=='{'||c=='['||c=='(')&&cishu>0) sig=abs(sig);
    if(cishu==0) {
        if(c=='{') ans=1;
        else if(c=='[') ans=2;
        else ans=3;
        cishu++;
        return f(s,ans,cishu,weizhi);
    }
    else if(cishu<0) return 0;
    else if(c=='{') {
        if(sig!=3&&sig>0) return 0;
    }
    else if(c=='[') {
        if(sig!=1&&sig>0) return 0;
    }
    else if(c=='(') {
        if(sig!=2&&sig>0) return 0;
    }
    else if(c=='}'||c==']'||c==')') {
        cishu--;
        if(c=='}') return f(s,-3,cishu,weizhi);
        else if(c==']') return f(s,-1,cishu,weizhi);
        else return f(s,-2,cishu,weizhi);
    }
    if(c=='{'||c=='['||c=='('){
        if(c=='{') ans=1;
        else if(c=='[') ans=2;
        else ans=3;
        cishu++;
        return f(s,ans,cishu,weizhi);
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    char s[101];
    for(int t=0;t<T;t++){
        int x=0;
        scanf("%s",s);
        if(s[0]=='{') x=1;
        else if(s[0]=='[') x=2;
        else x=3;
        int ans=0;
        ans=f(s,x,1,1);
        if(ans>0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
