#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char s[51];
    scanf("%s",s);
    int len=strlen(s);
    int i,sum[len];
    for(i=0;i<len;i++)
    {   sum[i]=1;
        for(int l=i;l<len-1;l++)
        {if(s[l]!=s[l+1]) sum[i]++;
        else break; }   
    }
    int max=sum[0];
    for(int k=1;k<len;k++)
    if(max<s[k]) max=s[k];
    printf("%d",max);
    return 0;
    
}