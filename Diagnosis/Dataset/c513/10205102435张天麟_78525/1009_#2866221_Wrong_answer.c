#include<stdio.h>
int zxgbs(int a,int b)
{
    int c;
    if(a<b)
    {
        c=a;
        a=b;
        b=c;
    }
    if(a%b==0)return b;
    else return zxgbs(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    char c;
    scanf("%c",&c);
    for(i=0;i<n;i++)
    {
        int j=0,sum=0;
        scanf("%c",&c);
        while(c!='\n')
        {
            while(c!=0)
            {
                sum+=c%2;
                c/=2;
            }
            j++;
            scanf("%c",&c);
        }
        printf("%d/%d\n",sum,j*8);
    }
    return 0;
}
