#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int a,b,z,f;
    scanf("%d %d",&a,&b);
    z=a/b;//整数部分
    f=a-z*b;//分数部分的分子
    int s[100000]={0};
    int z1=z,i=0;
     while(f!=0)
    {
       s[i]=f%3;
       i++;
       f/=3;
    }
    int count1=i;
    //count1为小数部分的数字个数
    while(z1!=0)
    {
       s[i]=z1%3;
       i++;
       z1/=3;
    }

    int j=0;//初始进值
    int s1[100000]={0};
    int m;
    for(m=0;m<i;m++)
    {
        s1[m]=s[m]+1+j-(s[m]+1+j)/3*3;
        j=(s[m]+1+j)/3;
    }
    if(s1[m-1]>=3)
        {s1[m]=s1[m-1]%3;s1[m-1]=s1[m-1]-s1[m-1]/3*3;i++;}//i为三进制所有数字个数之和
        int count2=i-count1;//整数部分的数字个数

       for(int p=0;p<i;p++)
        {
            s1[p]=s1[p]-1;
            if(s1[p]==-1) s1[p]=2;
        }//把-1变为2
        for(int k=0;k<i/2;k++)
        {
            int c=s1[k];
            s1[k]=s1[i-1-k];
            s1[i-1-k]=c;
        }//调换位置
        int l;
        for(l=0;l<count2;l++)
            printf("%d",s1[l]);
        printf(".");
        for(;l<i;l++)
            printf("%d",s1[l]);
        return 0;
}