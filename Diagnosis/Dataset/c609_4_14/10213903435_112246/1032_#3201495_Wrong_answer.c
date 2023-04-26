#include<stdio.h>
int main()
{
    char s[50];
    scanf("%s",s);
    char *p=s;
    int cnt=1;
    while(*(p+1))
    {
        int temp=1;
        if(*p++!=*(p+1)&&*(p+2))temp++;
        else if(*p++!=*(p+1)&&(!*(p+2))){temp++;cnt=cnt<temp?temp:cnt;}
        else if(*p==*(p+1)&&cnt<=temp){cnt=temp;p++;}
        else p++;
    }
    printf("%d",cnt);
    return 0;
}