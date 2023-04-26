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
            if(MAX<n)
            {
                MAX=n;
            }
            n=1;
        }
        s=c;
    }
    if(MAX<n)
    {
        MAX=n;
    }
    printf("%d\n",MAX);
    return 0;
}