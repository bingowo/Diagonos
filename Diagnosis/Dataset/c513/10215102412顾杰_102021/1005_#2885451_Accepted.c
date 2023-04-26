#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
void pad(int*ans,char s)
{
    int r=0,i,j;
    ans[0]+=s-'0';
    for(i=0;ans[i]==0;i++);
    for(j=999;ans[j]==0;j--);
    do
    {
        r=ans[i]+10*r;
        ans[i++]=r/8;
        r%=8;
    }
    while(i<j+10);
}
int main() {
    int n,i,j,ans[1000],k;
    char s[501];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   memset(ans,0,1000*sizeof(int));
        scanf("%s",s);
        j=strlen(s)-1;
        while(s[j]=='0')j--;
        for(j;j>=2;j--)pad(ans,s[j]);
        for(j=999;j>=0&&ans[j]==0;j--);
        printf("case #%d:\n%d.",i,ans[0]);
        for(k=1;k<=j;k++)printf("%d",ans[k]);
        if(j<0)printf("0");
        printf("\n");
    }
    return 0;
}
