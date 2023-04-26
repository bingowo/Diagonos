#include<stdio.h>
#include<string.h>

int main()
{
    long long t,n;//t是实验组数，n是每组的数据
    scanf("%d",&t);
    int out[33];
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n",i);
        int u = 0, k = 0;//u和k用来计数
        while(n>0)
        {
          out[u++] = n % 2;
           n /= 2;
        }//out数组倒序存入二进制的数
        out[u]=-1;
        int max=1,length =1;
        for (int p1=0,p2=1;out[p1]!=-1&&out[p2]!=-1;p1++,p2++)
        {
            if(out[p1]!=out[p2])
            length++;
            else{
                if(length>max)
                max=length;
                length=1;
            }
        }
        if (max<length)max=length;
        printf("%d\n",max);

    }
    return 0;
}