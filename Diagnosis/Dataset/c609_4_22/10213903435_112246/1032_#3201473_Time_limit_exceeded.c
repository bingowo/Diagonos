#include<stdio.h>
int main()
{
    char s[50];
    char *p=s;
    scanf("%s",s);
    int cnt=1;
    while(*(p+1))
    {
        int temp=1;
        if(*p!=*(p+1)&&*(p+2))temp++;
        else if(*p!=*(p+1)&&(!*(p+2))){temp++;cnt=cnt<temp?temp:cnt;}
        else if(*p==*(p+1)&&cnt<temp)cnt=temp;
    }
    printf("%d",cnt);
    return 0;
}