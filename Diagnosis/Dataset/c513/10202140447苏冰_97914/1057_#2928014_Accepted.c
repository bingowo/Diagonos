#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    char s[1010];
    scanf("%s",s);
    char s1[1010]={0},s2[1010]={0};
    int j=0,k=0;
    s1[k]=s[0];
    for(int i=1;i<strlen(s);i++)
    {
        if(s[i]>=s1[k])
        {
            s1[++k]=s[i];
        }
        else
        {
            s2[j++]=s[i];
        }
    }
    for(int m=k;m>=0;m--) printf("%c",toupper(s1[m]));
    for(int m=0;m<j;m++) printf("%c",toupper(s2[m]));
    return 0;
}
