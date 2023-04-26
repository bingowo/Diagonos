#include<stdio.h>
#include<string.h>
void multi(int *a,int b,int* res,int lena,int lenres)
{
    int next=0,tmp,i;
    for(i=0;i<lena;i++)
    {
        tmp=a[lena-i-1]*b;
        tmp+=next;
        res[lenres-i-1]=tmp%10;
        next=tmp/10;
    }
}
int main()
{
    char s[2000];
    scanf("%s",s);
    int ans[1000],res[1000],len=1000;
    for(int i=0;i<1000;i++) 
    {
        ans[i]=0;
        res[i]=0;
    }
    ans[999]=1;
    if(s[0]!=s[1])
    {
        multi(ans,2,res,len,len);
        for(int i=0;i<1000;i++) 
        {
        ans[i]=res[i];
        res[i]=0;
        }
    }
    for(int j=1;j<strlen(s)-1;j++)
    {
        int m=1;
        if(s[j]!=s[j+1]) m++;
        if(s[j]!=s[j-1]&&s[j+1]!=s[j-1]) m++;
        multi(ans,m,res,len,len);
        for(int i=0;i<1000;i++) 
        {
        ans[i]=res[i];
        res[i]=0;
        }
    }
    if(s[strlen(s)-1]!=s[strlen(s)-2])
    {
        multi(ans,2,res,len,len);
        for(int i=0;i<1000;i++) 
        {
        ans[i]=res[i];
        res[i]=0;
        }
    }
    int test=0;
    for(int i=0;i<1000;i++)
    {
        if(ans[i]!=0) test=1;
        if(test==1) printf("%d",ans[i]);
    }
}