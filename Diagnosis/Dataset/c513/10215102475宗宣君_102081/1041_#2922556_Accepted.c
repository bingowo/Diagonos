#include<stdio.h>
#include <string.h>
int main()
{
    char s[51];int n[50]={0},i,j = 0,max = 0;
    gets(s);
    for(i = 0;i<strlen(s)-1;i++)
    {
        if(s[i]!=s[i+1]) n[j]++;
        else j++;
    }
    for(i = 0;i<=j;i++)
        max = n[i]>max?n[i]:max;
    printf("%d",max +1);
    return 0;
}
