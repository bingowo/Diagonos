/*思路：
    1，读入素数进制
    2，对每位数字，乘以其位权
    3，求和*
    
    
    需要大整数计算*/
#include<stdio.h>
#define N 40

int input(int (*p)[N])//p为指针，指向的是n个元素构成的数组
{
    int i=0,n;
    char c;
    do
    {
        scanf("%d%c",&p[i++][N-1],&c);
    } while (c==',');
    return i;
}

void mult_n(int a[],int n)//大整数乘法（乘以一个素数n），整数每一位乘以n,计算进位
{
    int i;
    for(i=N-1;i>0;i--)a[i]*=n;
    for(int i=N-1;i>0;i--){
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
}

void add(int a[],int b[])//大整数加法，两个整数对应为数字分别相加，注意进位
{
    int i;
    for(i=N-1;i>0;i--){
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
}

void output(int a[])//输出
{
    int i=0;
    while(i<N&&a[i]==0)i++;
    if(i>=N){
        printf("0\n");
        return ;}
    while(i<N)printf("%d",a[i++]);
    printf("\n");
}

int prime[]={
    2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
};

int main(){
    int p[25][N]={0};//定义一个二维数组，每一行对应素数进制的一位
    int d[N]={0};
    int num=input(p);
    int i,j;
    for(i=0;i<num;i++){
        for(j=0;j<num-i-1;j++)
            mult_n(p[i],prime[j]);
        add(d,p[i]);
    }
    output(d);
    return 0;
}
