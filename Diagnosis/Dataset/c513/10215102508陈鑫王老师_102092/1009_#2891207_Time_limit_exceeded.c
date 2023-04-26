#include<stdio.h>
#include<stdlib.h>
int gcd(int x,int y)
{
    int c,ans;
    if(x<y)
    {
        c=x;
        x=y;
        y=c;
    }
    ans=x%y;
    while(ans)
    {
        x=y;
        y=ans;
        ans=x%y;
    }
    return y;

}
void calculate1(char a[],int *num,int* num1)
{
    char* end=a;
    int n;
    while(*end)
        end++;
    char* p=a;
    while(p!=end)
    {
       n=*p;
       while(n)
       {
           if(n&1)*num1+=1;
           n=n>>1;
       }
       *num+=8;
       p++;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char a[121];
        gets(a);
        int num=0,num1=0,c;
        calculate1(a,&num,&num1);
        c=gcd(num1,num);
        printf("%lld/%lld\n",num1/c,num/c);


    }
    return 0;
}
