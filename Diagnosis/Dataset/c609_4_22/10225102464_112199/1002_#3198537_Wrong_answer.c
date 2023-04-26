#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,re,m;
    scanf("%d",&n);
    int a[1000];
    int b[1000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        int j=0;
        for(;a[i]>0;a[i]/=2)
        {
            b[j++]=a[i]%2;
        }
        b[j]='\0';

        int c=1;
        int d[1000];
        for(int p=0;p<j-1;p++)
        {

            if(b[p]!=b[p+1])
            {
                c++;
                if(p==j-2)
                {
                    d[m++]=c;c=1;
                }
            }
            else{
                d[m++]=c;c=1;
            }
        }
        d[m]='\0';
        int re=1;
        for(int y=0;y<m;y++)
        {
            re=d[y]>re?d[y]:re;
        }
        printf("case #%d:\n",i);
        printf("%d\n",re);


    }
    return 0;




}