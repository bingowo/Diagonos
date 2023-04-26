#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int h=0;h<n;h++)
    {
        int a[26]={0},b[26]={0},c[26]={0};
        char d;
        int a1,b1;
        int num1=-1,i1=0;
    while((d=getchar())!=' ')
    {
        if(d==',') {a[++num1]=i1;i1=0;}
        else{i1=d-'0'+i1*10;}
    }
    a[++num1]=i1;
    //输入第一个数组 0-num1
    a1=num1+1;//a1为第一个数组中元素个数
    int num2=-1,i2=0;
    while((d=getchar())!='\n')
    {
        if(d==',') {b[++num2]=i2;i2=0;}
        else{i2=d-'0'+i2*10;}
    }
    b[++num1]=i2;
    ////输入第二个数组，0-num2
    b1=num2+1;//b1为第二个数组中元素个数
    int prime[26]=
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
//质数
       for(int t=0;t<a1/2;t++)
    {
        int me=a[t];
        a[t]=a[a1-1-t];
        a[a1-1-t]=me;
    }//第一组数据换位置
    for(int t=0;t<b1/2;t++)
    {
        int me=b[t];
        b[t]=b[b1-1-t];
        b[b1-1-t]=me;
    }//第二组数据换位置
    int j=0,m,count=(a1>b1)?a1:b1;//count为结果数组中初始元素个数
    for(m=0,n=0;m<count;m++,n++)
            {c[m]=(a[m]+b[m]+j)%prime[n];
            j=(a[m]+b[m]+j)/prime[n];}
            if((a[m-1]+b[m-1]+j)>=prime[n-1]) 
            {c[m]=(a[m-1]+b[m-1]+j)/prime[n-1];count++;}
            //如果最高次项大于其对应的质数，再进一项
     printf("case #%d:\n",h);
     for(int i=count-1;i>0;i--)
        {
           printf("%d,",c[i]);
        }
        printf("%d",c[0]);//输出c
        printf("\n");
    }
       
    return 0;
}
