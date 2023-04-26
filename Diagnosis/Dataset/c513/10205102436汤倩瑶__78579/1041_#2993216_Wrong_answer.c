#include<stdio.h>
#include<string.h>
int main()
{
    char s[55];
    scanf("%s",s);
    int l=strlen(s);
    int cnt=1,max=1;
    int i=0,j;
    while((i+1)<l)
    {
        j=i;
        while((j+1)<l)
        {
            if(s[j]!=s[j+1]){j++;cnt++;}
            else {j++;cnt=1;}
        }
        if(cnt>max)max=cnt;
        i=j;
    }
    printf("%d",max);
    return 0;
}
