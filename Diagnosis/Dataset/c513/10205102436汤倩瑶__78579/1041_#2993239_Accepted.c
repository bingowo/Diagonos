#include<stdio.h>
#include<string.h>
int main()
{
    char s[55];
    scanf("%s",s);
    int l=strlen(s);
    int cnt=1,max=1;
    int i=0,j;
    while(i<l)
    {
        j=i;
        while((j+1)<l)
        {
            if(s[j]!=s[j+1]){j++;cnt++;}
            else break;
        }
        if(cnt>max)max=cnt;

        cnt=1;
        i=j+1;
    }
    printf("%d",max);
    return 0;
}
