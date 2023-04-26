#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void f1(double n)
{
    int c=sizeof(n);
    unsigned char*p=(unsigned char*)&n;
    for(int i=0;i<c;i++)
    {
        printf("%02x ",*p);
        p++;
    }
    printf("\n");
}
void f2(int n)
{
    int c=sizeof(n);
    unsigned char*p=(unsigned char*)&n;
    for(int i=0;i<c;i++)
    {
        printf("%02x ",*p);
        p++;
    }
    printf("\n");
}
int main()
{
    char a[1000];
    while(scanf("%s",a)!=EOF)
    {
        if(strchr(a,'.'))
            f1(atof(a));
        else
            f2(atoi(a));
    }
    return 0;
}
