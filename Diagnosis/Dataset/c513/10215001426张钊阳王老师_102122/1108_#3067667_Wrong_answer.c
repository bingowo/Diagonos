#include <stdio.h>
#include <stdlib.h>



int main()
{
    int T;
    scanf("%d",&T);
    for(int z=0;z<T;z++)
    {
        int remainder[150]={0},quotient[150]={0};
        int m,n,i,j;
        scanf("%d %d",&m,&n);//输入被除数和除数
        printf("case #%d:\n",z);
        printf("0.");
        for(i=1;i<=150;i++)//i:商的位数
        {
            remainder[m]=i;//m：除数的余数remainder[m]:余数对应的商的位数
            m*=10;//余数扩大10位
            quotient[i]=m/n;//商
            m=m%n;//求余数
            if(m==0)//余数为零即除完
            {
                for(j=1;j<=i;j++)   printf("%d",quotient[j]);
                printf("\n");
                break;//退出循环
            }
            if(remainder[m]!=0)//若该余数对应的位在前面已经出现过
            {
                for(j=1;j<=i;j++)   printf("%d",quotient[j]);
                printf("\n");
                printf("%d-%d",remainder[m],i);
                break;//退出
            }
	}
    }
    return 0;
}
