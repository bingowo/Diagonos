#include <stdio.h>
#include <math.h>
#include <string.h>
char ans1[1009];
int k,l;

void f(int n)
{
    if(n!=0){
        f(n/3);
        ans1[k++]=n%3+'0';
    }
}

int main()
{
    int a,b;
    char ans2[1009];
    scanf("%d%d",&a,&b);
    int x,y;
    x=a/b;
    y=a%b;
    f(x);
    if(y!=0){
        ans1[k++]='.';
        f(y);
    }
    ans1[k]=0;
    ans2[k+1]=0;
    ans2[0]='0';
    int temp=0;
    for(int len=k;len>=1;len--){
        if(ans1[len-1]=='.')ans2[len]='.';
        else{
            ans2[len]=(temp+ans1[len-1]+1-'0')%3+'0';
            temp=(temp+ans1[len-1]+1-'0')/3;
        }
    }
    ans2[0]=temp+'0';
    if(ans2[0]!='0')printf("%c",ans2[0]);
    for(int i=1;i<=k;i++){
        if(ans2[i]=='.')printf(".");
        else if(ans2[i]-'0'==0)printf("2");
        else printf("%d",ans2[i]-'0'-1);
    }
    return 0;
}
