#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    scanf("%s",&str);
    int n;
    fgets(str,strlen(str),stdin);
    n=maxstr(str);
    printf("%d",n);
    return 0;
}
int maxstr(char str[50])
{
    int i=0,l=1,max=0;
    if(strlen(str)==1)max=1;
    if(str[1]!=str[0])max=2;
    else max=1;
    l=max;
    for(int i=2;i<strlen(str);i++){
            if(str[i]!=str[i+1])l=l+1;
            else max=max>l?max:l;l=1;
        }
        max=max>l?max:l;
    return max;
}
