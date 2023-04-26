#include<stdio.h>

int main()
{
    char A[500];
    int B[500];
    int C[10];
    int D[4];
    int E[7];
    for(int j=0;j<4;j++)
    {
        D[j]=0;
    }
    for(int j=0;j<7;j++)
    {
        E[j]=0;
    }
    for(int j=0;j<10;j++)
    {
        C[j]=0;
    }
    int i=0,count,count1,k=9,sum=0,sign1=0,sign2=0;
    int *p=B;
    scanf("%s",A);
    while(A[i])
    {
        B[i]=A[i]-'0';
        i++;
    }
    printf("0001");
    if(i%3==1)
    {
        sign1=1;
    }
    if(i%3==2)
    {
        sign2=2;
    }
    count=i/3;
    count1=count;
    while(i)
    {
        C[k]=i%2;
        i=i/2;
        k--;
    }
    for(int q=0;q<10;q++)
    {
        printf("%d",C[q]);
    }
    for(int j=0;j<10;j++)
    {
        C[j]=0;
    }
    k=9;
    while(count--)
    {
        sum=B[3*count-3]*100+B[3*count-2]*10+B[3*count-1];
        while(sum)
        {
            C[k]=sum%2;
            sum=sum/2;
            k--;
        }
        for(int q=0;q<10;q++)
        {
            printf("%d",C[q]);
        }
        for(int j=0;j<10;j++)
        {
        C[j]=0;
        }
        k=9;
    }
    if(sign1)
    {   k=3;
        sum=B[3*count1];

        while(sum)
        {
            D[k]=sum%2;
            sum=sum/2;
            k--;
        }
        for(int q=0;q<4;q++)
        {
            printf("%d",D[q]);
        }


    }
    if(sign2)
    {
        k=6;
        sum=B[3*count1]*10+B[3*count1+1];

        while(sum)
        {
            E[k]=sum%2;
            sum=sum/2;
            k--;
        }
        for(int q=0;q<7;q++)
        {
            printf("%d",E[q]);
        }
    }

}