#include<stdio.h>
#include<math.h>
int main()
{
    char c[40];
    scanf("%s",c);
    int num1[40],num2[40];
    int i1=0,i2=0,f=0;
    long long a1=0,a2=0,a3,k=1;
    for(int n=0;c[n];n++)
    {
        if(f==0)
        {
            if(c[n]=='2'){num1[i1]=-1;i1++;}
            else if(c[n]!='.'){num1[i1]=c[n]-'0';i1++;}
        }
        else
        {
            if(c[n]=='2'){num2[i2]=-1;i2++;}
            else if(c[n]!='.'){num2[i2]=c[n]-'0';i2++;}
        }
        if(c[n]=='.')f=1;
    }
    while(i1>0){
        a1+=num1[i1-1]*k;
        k*=3;i1--;
    }
    k=1;
    a3=pow(3,i2);
    while(i2>0){
        a2+=num2[i2-1]*k;
        k*=3;i2--;
    }
    if(a2<0&&a1>0){a2+=a3;a1--;}
    else if(a2>0&&a1<0){a2=a3-a2;a1++;}
    if(a2*a1!=0)printf("%lld %lld %lld",a1,a2,a3);
    else if(a1==0&&a2!=0)printf("%lld %lld",a2,a3);
    else printf("%lld",a1);
    return 0;
}