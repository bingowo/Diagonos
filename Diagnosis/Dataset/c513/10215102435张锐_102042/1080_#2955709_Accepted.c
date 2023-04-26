#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void mult(int *s,int a)
{
    int last=0;
    for(int i=999;i>=0;i--)
    {
        int temp=s[i]*a+last;
        if(temp<10) s[i]=temp,last=0;
        else if(temp>9)
        {
            s[i]=temp%10;last=temp/10;
        }
    }
}
void add(int *ans,int *t)
{
    int last=0;
    for(int i=999;i>=0;i--)
    {
        int temp=ans[i]+t[i]+last;
        if(temp<10) ans[i]=temp,last=0;
        else {ans[i]=temp-10,last=1;}
    }
}
int main()
{
    int e;
    scanf("%d",&e);
    for(int h=0;h<e;h++)
    {
        char s[1000];int p[1000]={0};int ans[1000]={0};
        scanf("%s",s);
        int len=strlen(s);
        int j=0;int x=0;int bo=1;
        printf("case #%d:\n",h);
        if(strcmp(s,"0")==0) printf("0");
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
        for(int ii=j-1,g=0;ii>=0;ii--,g++)
        {
            int t[1000]={0};t[999]=1;
            for(int j=0;j<g;j++)
            {
                mult(t,2);
            }
            if(p[ii]!=0) {mult(t,p[ii]);add(ans,t);}
        }
        bo=0;
        for(int jj=0;jj<1000;jj++)
        {
            if(ans[jj]!=0) bo=1;
            if(bo) printf("%d",ans[jj]);
        }
        printf("\n");
    }
    return 0;
}
