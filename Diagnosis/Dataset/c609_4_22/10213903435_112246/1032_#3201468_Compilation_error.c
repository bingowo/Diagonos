#include<stdio.h>
int main()
{
    char s[50];
    char *p=s;
    scanf("%s",s);
    cnt=1;
    while(*(p+1))
    {
        temp=1;
        if(*p!=*(p+1))temp++;
        else if(*p==*(p+1)&&cnt<temp)cnt=temp;
    }
    if(cnt<temp)cnt=temp;
    printf("%d",cnt);
    return 0;
}