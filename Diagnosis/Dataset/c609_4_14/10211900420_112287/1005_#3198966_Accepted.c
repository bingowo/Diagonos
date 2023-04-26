#include<stdio.h>
#include<string.h>
int pow(int a,int b)
{
    int sum,i;
    sum=1;
    for(i=0;i<b;i++)
    {
        sum=sum*a;
    }
    return sum;
}
int tri2d(char a)
{
    if(a=='1') return 1;
    if(a=='0') return 0;
    if(a=='-') return -1;
}
int main()
{
    char a[1000];
    int x,sum,j,len,i,T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        sum=0;
        scanf("%s",&a);
        len=strlen(a);
        for(j=0;j<len;j++)
        {
            x=tri2d(a[j]);
            sum=sum+x*pow(3,len-j-1);
        }
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}
