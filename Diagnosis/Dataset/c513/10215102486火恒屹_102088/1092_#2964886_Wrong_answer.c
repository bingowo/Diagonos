#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int res[501]={0};
void time(int w)
{
    for(int i=500;i>=0;i=i-1)
        res[i]=res[i]*w;
    for(int i=500;i>=0;i=i-1)
    {
        while(res[i]>=10)
        {
            res[i]=res[i]-10;
            res[i-1]++;
        }
    }
}
int main()
{
    char s[1001];
    scanf("%s",&s);
    res[500]=1;
    if(s[0]!=s[1]) res[500]=2;
    for(int i=1;i<strlen(s)-1;i++)
    {
        int weight=1;
        if(s[i]!=s[i-1]) weight++;
        if(s[i]!=s[i+1]) weight++;
        if((s[i-1]==s[i+1])&&(weight==3)) weight=2;
        time(weight);
    }
    if(s[strlen(s)-2]!=s[strlen(s)-1])
        time(2);
    int i=0;
    while(res[i]==0)
        i++;
    for(int j=i;j<=500;j++)
        printf("%d",res[j]);
    return 0;
}
