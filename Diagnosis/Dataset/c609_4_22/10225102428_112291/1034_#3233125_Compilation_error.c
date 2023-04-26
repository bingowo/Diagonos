#include<stdio.h>
#include<string.h>
int main()
{
    char str[100000];
    scanf("%s",&str);
    int n;
    n=trans(str);
    printf("%d",n);
    return 0;
}
int trans(char str[100000])
{
    int len=strlen(str);
    s[2]="0x";
    int n=strstr(str,s);
    if(n==NULL)return -1;
    else{
            strncpy(dest,str+n,2);
            
        
    }
}
