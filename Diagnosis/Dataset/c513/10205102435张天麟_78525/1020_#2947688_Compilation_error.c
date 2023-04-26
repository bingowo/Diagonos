#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char s[100];
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int size;
    char name[64];
}wenjian;
int cmpN(const void *a,const void *b)
{

}
int cmpS(const void *a,const void *b)
{

}
int cmpT(const void *a,const void *b)
{

}
int main()
{
    int n,i;
    scanf("%d",&n);
    while(n!=0)
    {
        wenjian wj[n];
        for(i=0;i<n;i++)
        {
            gets(wj[i].s);
            int j=0;
            char c=;
        }
        scanf("%d",&n);
    }
    return 0;
}
