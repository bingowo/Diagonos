#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int power(int base,int n)
{
    int i;
    int p;
    p=1;
    if(n==0) return 1;
    for(i=1;i<=n;i++)
        p=p*base;
    return p;
}
void add(int *ans,int *t)
{
    int last=0;
    for(int i=999,j=99;j>=0;j--,i--)
    {
        int temp=ans[i]+t[j]+last;
        if(temp<10) ans[i]=temp,last=0;
        else {ans[i]=temp-10,last=1;}
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int h=0;h<t;h++)
    {
        char s[1000];int p[1000]={0};int ans[1000]={0};
        scanf("%s",s);
        int len=strlen(s);
        int j=0;int x=0;int bo=1;
        while(bo)
        {
            bo=0;x=0;
            for(int i=0;i<len;i++)
            {
                int temp=((s[i]-'0')+x*10)%2;
                if(temp==0) s[i]=((s[i]-'0'+x*10)/2)+'0',x=temp;
                else
                {
                    s[i]=(s[i]-'0'+x*10)/2+'0';
                    x=temp;
                }
                if(s[i]!='0') bo=1;
            }
            p[j++]=x;
        }
        for(int k=0,kk=j-1;k<j;k++,kk--)
        {
            int num=p[kk]*power(2,k);
            int t[100]={0};int ii=99;
            while(num) {t[ii--]=num%10;num=num/10;}
            add(ans,t);
        }
        bo=0;
        printf("case #%d:\n",h);
        for(int jj=0;jj<1000;jj++)
        {
            if(ans[jj]!=0) bo=1;
            if(bo) printf("%d",ans[jj]);
        }
        printf("\n");
    }
    return 0;
}
