#include <stdio.h>
#include <math.h>
#include <string.h>
char ans1[109];
int k,l;

void f1(int n)
{
    if(n!=0){
        f1(n/3);
        ans1[k++]=n%3+'0';
    }
}

void f2(int n,int r)
{
    if(n!=0){
        ans1[k++]=n/r+'0';
        f2(n%r,r/3);
    }
}

int main()
{
    int a,b;
    char ans2[109];
    scanf("%d%d",&a,&b);
    int x,y;
    x=a/b;
    y=a%b;
    f1(x);
    if(x==0){
        ans1[k++]='0';
    }
    if(y!=0){
        ans1[k++]='.';
        f2(y,b/3);
    }
    ans1[k]=0;
    int temp=0;
    int l=0;
    for(int len=k-1;len>=0;len--){
        if(ans1[len]=='.'){
            ans2[l++]='.';
        }
        else{
            ans2[l++]=(temp+ans1[len]+1-'0')%3+'0';
            temp=(temp+ans1[len]+1-'0')/3;
        }
    }
    if(temp!=0)ans2[l++]=temp+'0'+1;
    ans2[l]=0;
    for(int i=l-1;i>=0;i--){
        if(ans2[i]=='.')printf(".");
        else if(ans2[i]-'0'==0)printf("2");
        else printf("%d",ans2[i]-'0'-1);
    }
    return 0;
}
