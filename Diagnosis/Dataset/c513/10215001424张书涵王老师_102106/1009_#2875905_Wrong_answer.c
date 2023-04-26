#include <stdio.h>
#include <stdlib.h>
char b[10000];

void erjinzhi(char* a)
{
    int i,j,l;
    for(i=0;a[i];i++)
    {
        l=a[i];
        for(j=0;l>0;j++)
        {
            b[j]=l%2+48;
            l=l/2;
        }
    }
}

int main()
{
    int T,l=0,o=0;
    scanf("%d ",&T);
    char a[T][1000];
    int i,j;
    for(i=0;i<T;i++)
      gets(a[i]);
    for(i=0;i<T;i++)
    {
        erjinzhi(a[i]);
        for(j=0;b[j];j++)
        {
            if(b[j]=='1')
                l=l+1;
            else
                o=o+1;
        }
        printf("%d/%d\n",l,l+o);
    }
}
