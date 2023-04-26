#include<stdio.h>
#include <string.h>
int main()
{
    char s[1001],a[1001],b[1001];
    scanf("%s",s);
    int len = strlen(s),i;
    for(i = 0;i<len;i++)
    {
        if(s[i]>='a'&&s[i]<='z') s[i] = s[i]-32;
        b[0] = s[i];
        b[1] = '\0';
        if(s[i]>=a[0])
        {
            strcat(b,a);
            strcpy(a,b);
        }
        else
        {strcat(a,b);}

    }
    printf("%s",a);
    return 0;
}
