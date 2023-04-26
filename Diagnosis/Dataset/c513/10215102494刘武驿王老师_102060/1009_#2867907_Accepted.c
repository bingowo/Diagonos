#include<stdio.h>
int GCD(int m,int n)

{   int a,b;
    if (m>n)
    {
        a=m;
        m=n;
        n=a;
    }

    if (n%m==0) return m;
    if (n%m!=0) return GCD(n-m,m);
    }

int main()
{
    int num;
    scanf("%d",&num);
    char o=getchar();
    for(int m=0;m<num;m++)
    {
        int sum=0,count=0;
        char c;
        int j=0;
        char str[120];
        while((c=getchar())!='\n')
        {
            str[j]=c;
            j++;
        }
        unsigned char a;
        for(int n=0;n<j;n++)
        {
            a=str[n];
            int tmp;
            tmp=(int)a;
            for(int shu=0;shu<8;shu++)
            {
                if(tmp&1==1) count++;
                tmp>>=1;
            }
        }
        sum=j*8;
        int div=GCD(count,sum);
        sum/=div;
        count/=div;
        printf("%d/%d\n",count,sum);
    }
}