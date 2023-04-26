#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>


void cheng(int*a,int n,int wei)
{
    int yu;
    for(int i=0;i<wei;i++)
    {
        int c=a[i];
        a[i]=(a[i]*n+yu)%10;
        yu=(c*n+yu)/10;
    }
    while(yu>0) {a[wei]=yu;wei++;yu/=10;}
    printf("%d",wei);
}

int main()
{
    char s[1100];
    scanf("%s",s);
    int a[100000]={0};
    a[0]=1;
    int wei=1;
    int n=strlen(s);
    for(int i=0;i<n-1;i++)
    {
        if(i==0) {if(s[i]!=s[i+1]) cheng(a,2,wei);}
        else if(i==n-1) if(s[i]!=s[i-1]) cheng(a,2,wei);
        else
        {if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1]) cheng(a,3,wei);
        if(s[i]==s[i-1]&&s[i]!=s[i+1]) cheng(a,2,wei);
        if(s[i]==s[i+1]&&s[i]!=s[i-1]) cheng(a,2,wei);
        if(s[i-1]==s[i+1]&&s[i]!=s[i-1]) cheng(a,2,wei);}
    }
    return 0;




}
