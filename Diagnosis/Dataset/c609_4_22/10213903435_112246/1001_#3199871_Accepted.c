#include <stdio.h>
#include <stdlib.h>
#define N 5000
int main()
{
    int t,arr[N][2];    //定义二维数组用来存放每组测试实例的整数
    char rslt[N][100];  //定义一个二维数组来存放每组实例的结果数据
    int i=0,j=0;
    scanf("%d",&t);     //输入测试实例组数
    while(i<t)
    {   //使用循环将每组数据读入到二维数组中并进行进制转换
        scanf("%d%d",(*(arr+i)),(*(arr+i)+1));
        int n=*(*(arr+i)),r=*(*(arr+i)+1);
        if(n>=0)
        do
        {
            rslt[i][j++]=(n%r)>=10?(char)(n%r-10+'A'):(char)(n%r+'0');
            //实现从10开始用A、B、C...表示，将结果以字符形式存放在rslt数组中
        }while(n/=r);
        else if(n<0)
        {
            n=abs(n);
            do
            {
                rslt[i][j++]=(n&r)>=10?(char)(n%r-10+'A'):(char)(n%r+'0');
            }while(n/=r);
            rslt[i][j++]='-';       //对于负数要在结果末尾添加‘-’，因为数组中存放的顺序是反的
        }
        rslt[i][j]=0;   //每一行的结果加0表示结束
        i++,j=0;
    }
    i=j=0;
    for(;i<t;i++)
    {
        while(rslt[i][++j]);
        for(;j>=0;)
        {
            printf("%c",rslt[i][--j]);
            //每一行倒置输出
        }
        printf("\n");
        j=0;    //开始重新计数
    }
    return 0;
}
