#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{
    int a[500];
    int b[500];
    int sign1,sign2;
}val;

void add(int*a,int*b)
{
    int i,carry=0;
    for(i=0;i<500;i++)
    {
        int t=a[i]+b[i]+carry;
        a[i]=t%10;
        carry=t/10;
    }
}

void min(int*a,int*b)
{
    int i,j,carry=0;
    for(i=0;i<500;i++)
    {
        int t=a[i]-b[i]+10-carry;
        a[i]=t%10;
        carry=1-t/10;
    }
}

void mul(int*a,int*b)
{
    int i,j,d[500]={0},carry=0;
    for(i=0;i<500;i++)
    {
        for(j=0;j<500;j++)
        {
            int t=a[i]*b[j]+carry+d[i+j];
            d[i+j]=t%10;
            carry=t%10;
        }
    }
}

int main()
{
    char s[20];scanf("%s",s);
    int n,i,j;scanf("%d",&n);
    val d1={{0},{0},0,0},d2={{0},{0},0,0};
    if(n==0)printf("1");
    else
    for(i=0;i<strlen(s);)
    {
        int m=0,f=1;
        if(s[i]=='-'){f=-1;i++;}
        else if(s[i]=='+'){f=1;i++;}
        while(isdigit(s[i]))
        {
            m=m*10+s[i]-'0';
            i++;
        }
        if(s[i]=='i')
        {
            if(m==0){d1.b[0]=1;d1.sign2=f;}
            else
            {   j=0;
                while(m>0)
                {
                    d1.b[j++]=m%10;
                    m/=10;
                }
                d1.sign2=f;
            }
            i++;
        }
        else
        {
            j=0;
            while(m>0)
            {
                d1.a[j++]=m%10;
                m/=10;
            }
            d1.sign1=f;
        }
    }
}
