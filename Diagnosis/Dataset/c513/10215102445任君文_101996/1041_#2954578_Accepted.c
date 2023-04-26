#include<stdio.h>
#include<string.h>
int main()
{
    int n=1,MAX=1;
    char c;
    char s;
    s=getchar();
    while((c=getchar())!='\n')
    {
        if(s!=c)
        {
            n++;
        }
        else
        {
            n=1;
        }
        if(MAX<n)
        {
            MAX=n;
        }
        s=c;
    }
    printf("%d\n",MAX);
    return 0;
}