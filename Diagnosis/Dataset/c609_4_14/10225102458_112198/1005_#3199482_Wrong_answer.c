#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void change(int a,char c)
{
    if(c=='-')a=-1;
    else if(c=='0')a=0;
    else a=1;
}
int main()
{
    int n,cdd,max,bet=1;
    char s[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        max=0;
        for(int i=strlen(s)-1;i>=0;i--){
            change(cdd,s[i]);
            max+=cdd*bet;
            bet*=3;
        }
        bet=1;
        printf("case #%d:\n%d\n",i,max);
    }
    return 0;
}
