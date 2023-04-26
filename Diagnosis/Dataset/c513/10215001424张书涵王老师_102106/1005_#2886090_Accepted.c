#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        char s[55];//存储八进制数字
        scanf("%s",s);
        int j,l;
        l=strlen(s)-1;
        char c[155];//存储十进制的数字
        int number=0;//十进制中存储的数字的位数，如果做除法的时候十进制中还有数字没有被读取到，就再加上后面未读到的数字，如果已经没有数字未被读到，就乘10
        for(;l!=1;l--)//从最后一位数开始做除法，然后将除出的数字存储在c中
        {
            int jfshuzi,shuzi=s[l]-'0';//注意每次循环l的值都会发生改变，将现在这个循环中对应那个数开始;jfshuzi指的是目前这个数字乘10或加上后面未读到的数字后变成的值
            j=0;
            do
            {
                if(j<number)
                    jfshuzi=shuzi*10+c[j]-'0';//j是来读取十进制数组的位置的，number是十进制数组的位数，如果j小于number，说明数组中还有没有用到的数字
                else
                    jfshuzi=10*shuzi;//否则我们做除法就是直接乘十。比如7/8，是让7乘10后除8得商，而71/8是让7加上1后用71来除把得到商
                c[j++]=jfshuzi/8+'0';
                shuzi=jfshuzi%8;
            }
            while(shuzi!=0||j<number);
            number=j;//除尽之后得到的j是多加了一个1，刚好用来表示十进制数组中存储的位数
        }
        c[number]='\0';//最后要加上终止符号，不然没办法输出
        printf("case #%d:\n0.",i);
        for(j=0;c[j];j++)
            printf("%c",c[j]);
        printf("\n");
    }
}
