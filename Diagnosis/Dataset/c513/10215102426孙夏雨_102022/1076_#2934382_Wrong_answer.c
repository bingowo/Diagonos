#include <stdio.h>
#include <stdlib.h>

int f(char c,int sig,int cishu)
{
    int ans=0;
    c=getchar();
    if(c=='\n') return 1;
    if((sig<0)&&(c=='{'||c=='['||c=='(')&&cishu>0) sig=abs(sig);
    if(cishu==0) {
        if(c=='{') ans=1;
        else if(c=='[') ans=2;
        else ans=3;
        cishu++;
        return f(c,ans,cishu);
    }
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
        if(c=='}') return f(c,-3,cishu);
        else if(c==']') return f(c,-1,cishu);
        else return f(c,-2,cishu);
    }
    if(sig!=0){
        if(c=='{') ans=1;
        else if(c=='[') ans=2;
        else ans=3;
        cishu++;
        return f(c,ans,cishu);
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    char c=getchar(),s[101];
    for(int t=0;t<T;t++){
        int x=0;
        //if(t>0) {c=getchar();}
        //printf("c=%c,s=%s\n",c,s);
        c=getchar();
        //printf("c1=%c",c);
        if(c=='{') x=1;
        else if(c=='[') x=2;
        else x=3;
        int ans=0;
        ans=f(c,x,1);
        if(ans>0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
