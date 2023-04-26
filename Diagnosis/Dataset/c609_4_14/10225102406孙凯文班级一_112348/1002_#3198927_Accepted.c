#include<stdio.h>
int main()
{
    int n,a,j=1,b,c=-1,h=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        while(a!=0)
        {
            b=a%2;
            if(b!=c) h++,c=b,a=a/2;
            else
            {
                if(h>j) j=h;
                h=1;
                a=a/2;
            }
        }
    if(h>j) j=h;
    printf("case #%d:\n%d\n",i,j);
        j=1;
        h=0;
        c=-1;
    }
    return 0;
}
