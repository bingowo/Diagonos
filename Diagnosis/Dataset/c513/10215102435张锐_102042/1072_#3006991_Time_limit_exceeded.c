#include <stdio.h>
#include <stdlib.h>
int all=0;
void f(char *s,long long int a,long long int b,long long int x,long long int y,int i,int t)
{
    if(i==1)
    {
        if(x+t==a&&y==b) {s[i]='E';all=1;return ;}
        if(x-t==a&&y==b) {s[i]='W';all=1;return ;}
        if(x==a&&y+t==b) {s[i]='N';all=1;return ;}
        if(x==a&&y-t==b) {s[i]='S';all=1;return ;}
    }
    else
    {
        s[i]='E';f(s,a,b,x+t,y,i-1,t*2);
        if(all==1) return ;
        else
        {
            s[i]='W';f(s,a,b,x-t,y,i-1,t*2);
            if(all==1) return ;
            else
            {
                s[i]='N';f(s,a,b,x,y+t,i-1,t*2);
                if(all==1) return ;
                else
                {
                    s[i]='S';f(s,a,b,x,y-t,i-1,t*2);
                    return ;
                }
            }
        }
    }

}
int main()
{
    long long int a,b;
    scanf("%lld%lld",&a,&b);
    long long int ta=a,tb=b;
    if(a<0) a=-a;
    if(b<0) b=-b;
    long long int sum=a+b,temp=1;int i=0;
    if(sum%2==0&&sum!=0) i=-1;
    for(;i>=0;i++)
    {
        if(sum<=temp) break;
        temp*=2;
    }
    printf("%d\n",i);
    if(i!=-1&&(a!=0||b!=0))
    {
        char s[100];
        f(s,ta,tb,0,0,i,1);
        for(int j=i;j>=1;j--) printf("%c",s[j]);
    }
    return 0;
}
