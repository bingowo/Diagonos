#include<stdio.h>
#define N 80
#include<stdlib.h>
int main()
{
    int i;
    char s[N];
    while(scanf("%s",s)==1)
    {
        for(i=0;s[i];i++)
        if(s[i]=='.')
        break;
        if(s[i]=='.')
        {
            double f=atof(s);
            for(i=0;i<sizeof(double);i++)
            printf("%02x ",((unsigned char*)&f)[i]);
        }
        else
        {
            int n=atoi(s);
            for(i=0;i<sizeof(int);i++)
            printf("%02x ",((unsigned char*)&n)[i]);
        }
        printf("\n");
    }
    return 0;
}