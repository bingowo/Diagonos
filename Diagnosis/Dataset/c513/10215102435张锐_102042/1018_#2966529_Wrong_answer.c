#include <stdio.h>
#include <stdlib.h>
void add(int *ans,int *t)
{
    int last=0;
    for(int i=999;i>=0;i--)
    {
        int temp=ans[i]+t[i]+last;
        if(temp>9) ans[i]=temp-10,last=1;
        else ans[i]=temp,last=0;
    }
}
void mult(int *t,int n)
{
    int x1=n%10,x2=n/10;
    int last=0;int a[1000],b[1000];
    for(int i=0;i<1000;i++) a[i]=0,b[i]=0;
    for(int i=999;i>=0;i--)
    {
        int temp=t[i]*x1+last;
        if(temp>9) {a[i]=temp%10,last=temp/10;}
        else a[i]=temp,last=0;
    }
    last=0;
    if(t[998]==0) t[998]=1;
    for(int i=999;i>=0;i--)
    {
        int temp=t[i]*x2+last;
        if(temp>9) {b[i-1]=temp%10,last=temp/10;}
        else b[i-1]=temp,last=0;
    }
    last=0;
    for(int i=999;i>=0;i--)
    {
        int temp=a[i]+b[i]+last;
        if(temp>9) t[i]=temp-10,last=1;
        else t[i]=temp,last=0;
    }
}
int main()
{
    int p[26]={101,97,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    int ans[1000]={0};
    char c;int s[30];int i=0;
    do{
        scanf("%d",&s[i++]);
    }while((c=getchar())==',');
    for(int j=i-1;j>=0;j--)
    {
        int t[1000]={0};t[999]=1;
        for(int l=0;l<i-j-1;l++) mult(t,p[25-l]);
        mult(t,s[j]);
        add(ans,t);
    }
    int pp;
    for(pp=0;pp<1000;pp++) if(ans[pp]!=0) break;
    if(pp==1000) printf("0");
    for(int k=pp;k<1000;k++) printf("%d",ans[k]);
    printf("\n");
    return 0;
}