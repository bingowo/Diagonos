#include<stdio.h>

int main()
{
    char A[500];
    int B[500];
    int C[10];
    int D[4];
    int E[7];
    for(int j2=0;j2<4;j2++)
    {
        D[j2]=0;
    }
    for(int j3=0;j3<7;j3++)
    {
        E[j3]=0;
    }
    for(int j1=0;j1<10;j1++)
    {
        C[j1]=0;
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
    for(int j5=0;j5<10;j5++)
    {
        C[j5]=0;
    }
    k=9;
    while(count)
    {
        sum=B[3*(count1-count+1)-3]*100+B[3*(count1-count+1)-2]*10+B[3*(count1-count+1)-1];
        while(sum)
        {
            C[k]=sum%2;
            sum=sum/2;
            k--;
        }
        for(int q3=0;q3<10;q3++)
        {
            printf("%d",C[q3]);
        }
        for(int j6=0;j6<10;j6++)
        {
        C[j6]=0;
        }
        k=9;
        count--;
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
        for(int q1=0;q1<4;q1++)
        {
            printf("%d",D[q1]);
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
        for(int q2=0;q2<7;q2++)
        {
            printf("%d",E[q2]);
        }
    }

}