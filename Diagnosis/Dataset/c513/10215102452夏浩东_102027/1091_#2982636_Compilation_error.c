#include <stdio.h>
#define N 500
char* add(char *s1,char *s2)
{
    int left=0;
    char *s;
    for(int i=N-1;i>=0;i++)
    {
        int n= s1[i]-'0'+s2[i]-'0'+left;
        s[i] = (char)(n%10);
        left = n/10;
    }
    return s;
}