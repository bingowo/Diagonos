#include<stdio.h>
int main()
{
    int t,i,sum=0,j,x=0,z=1;
    int a[130];
    char s[62];
    for(i=0;i<130;i++) a[i]=-1;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",s);
        for(j=0;s[j]!='\0';j++);
        a[(int)s[0]]=1;
        for(int q=0;q<j;q++)
        {
            if(a[(int)s[q]]==-1) a[(int)s[q]]=x,x++;
            if(x==1) x++;
        }
        j--;
        for(;j>-1;j--)
        {
            sum=sum+z*a[(int)s[j]];
            z=z*x;
        }
        printf("case #%d:\n%d\n",i,sum);
        sum=0;
        x=0;
        z=1;
        for(j=0;j<130;j++) a[j]=-1;
    }