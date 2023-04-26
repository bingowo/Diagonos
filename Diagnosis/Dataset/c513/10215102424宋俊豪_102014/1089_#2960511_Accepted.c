#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int slo(int a[],int b[])
{
    char s[20];int q,carry,t,i,n,cnt;
    scanf("%s %d %d",s,&cnt,&n);
    i=strlen(s);
    for(int j=0;j<i;j++)
    {
        a[j]=s[i-1-j]-'0';
        b[j]=a[j];
    }
    for(i=0;i<cnt-1;i++)
    {   int c[20]={0};
        for(int j=0;j<n;j++)
        {    carry=0;
            for(q=0;q<n;q++)
            {
                if((q+j)<n)
                {
                    t=a[q]*b[j]+carry;
                    c[q+j]+=t%10;
                    carry=t/10;
                }
            }
        }
        carry=0;
        for(int j=0;j<n;j++)
        {   q=0;t=c[j];c[j]=0;
            while(t>0&&(j+q)<n)
            {
                c[j+q]+=t%10;
                t/=10;
                q++;
            }
        }
        for(int j=0;j<n;j++)
        {
            a[j]=c[j];
        }
    }
    return n;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   int a[15]={0},b[15]={0};
        int j=slo(a,b);
        printf("case #%d:\n",i);
        for(j=j-1;j>=0;j--)
            printf("%d",a[j]);
        printf("\n");
    }
    return 0;
}
