#include <stdio.h>
char ans[100];
void n2r(int n,int r);

int main()
{
    int T,N,R;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&R);
        n2r(N,R);
        printf("%s\n",ans);
    }
}
void n2r(int n,int r)
{
    char temp[100];
    int re,leng=0,flag=0;
    if(n<0)
    {
        flag=1;
        n=-n;
    }
    while(n!=0)
    {
        re=n%r;
        if(re<10)   temp[leng++]='0'+re;
        else    temp[leng++]='A'+re-10;
        n=n/r;
    }
    if(flag)
    {
        ans[0]='-';
        for(int i=1,j=leng-1;j>=0;i++,j--)  ans[i]=temp[j];
        ans[leng+1]=0;
    }
    else    
    {
        for(int i=0,j=leng-1;j>=0;i++,j--)  ans[i]=temp[j];
        ans[leng]=0;
    }
}