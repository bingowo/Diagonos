#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    getchar();getchar();char s[10001];
    scanf("%s",s);int i,j;int d[4],a[1001]={0},b[1001]={0};
    for(i=strlen(s)-1;i>=0;i--)
    {
        trans(s[i],d);
        for(j=3;j>=0;j--)
        {
            if(i==strlen(s)-1&&j==3){a[0]=-1;}
            zj(a,b);
        }
    }
    
}