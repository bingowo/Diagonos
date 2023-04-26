#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    int n;
    fgets(str,strlen(str),stdin);
    n=maxstr(str);
    printf("%d",n);
    return 0;
}
int maxstr(char str[50])
{
    int i=0,l=1,max=l;
    if(strlen(str)==1)max=1;
    else{
        while(i<strlen(str)){
            if(str[i]!=str[i+1])l=l+1;
            else i++;max=max>l?max:l;
        }
    }
    
    return max;
}