#include <stdio.h>
#define N 500
char* add(char *s1,char *s2)
{
    int left=0;
    char *s;
    for(int i=N-1;i>0;i--)
    {
        int n= s1[i]-'0'+s2[i]-'0'+left;
        s[i] = (char)(n%10);
        left = n/10;
    }
    return s;
}
char* mul(char *s1,int num)
{
    int left=0,count=0;
    char *s
    while(num>0)
    {
        int temp = num%10;
        num = num/10;
        for(int i=N-count;i>0;i--)
        {
            int n = (ns[i]-'0')*temp+left;
            s[i] = (char)(n%10);
            left = n/10;
            count++;
        }
    }
    return s;
}
int cmp(char*s1,char*s2)
{
    
}