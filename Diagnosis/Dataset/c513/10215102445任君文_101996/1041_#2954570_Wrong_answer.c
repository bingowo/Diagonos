#include<stdio.h>
#include<string.h>
int main()
{
    int n=0,MAX=1;
    char c;
    char s;
    s=getchar();
    while((c=getchar())!=EOF)
    {
        if(c=='\n')
        {
            break;
        }
        else if(s!=c)
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