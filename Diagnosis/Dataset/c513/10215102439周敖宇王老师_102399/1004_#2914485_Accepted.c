#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void ToInt(int x)
{
    int c = sizeof(x);
    unsigned char* p = (unsigned char*)&x;
    while (c--)
        printf("%02x ", *p++);
    printf("\n");

}
void ToDouble(double x)
{
    int c = sizeof(x);
    unsigned char* p = (unsigned char*)&x;
    while (c--)
        printf("%02x ", *p++);
    printf("\n");
}
int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==NULL)
        {
            ToInt(atoi(s));
        }
        else
        {
            ToDouble(atof(s));
        }
    }
    return 0;
}