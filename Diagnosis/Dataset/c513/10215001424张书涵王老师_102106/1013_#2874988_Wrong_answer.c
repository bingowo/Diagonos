#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char c[1000];
    int lenth,xslenth;  //整个字符串的长度，小数点后面的字符串的长度
    scanf("%s",c);
    lenth=strlen(c);
    int zhengshu=0,fenzi=0,fenmu;
    int j,i;
    for(j=0;c[j]&&c[j]!='.';j++)
    {
        if(c[j]=='1')
            zhengshu=zhengshu*3+1;
        else
        {
            if(c[j]=='0')
                zhengshu=zhengshu*3;
            else
                zhengshu=zhengshu*3-1;
        }
    }
    if(c[j]=='\0')
        printf("%d ",zhengshu);
    else
    {
        j++;   //跳过小数点，到小数点后的第一位数字
        i=lenth-1;
        for(;c[i]=='0';i--);
        xslenth=i-j+1;
        fenmu=pow(3,xslenth);
        for(;j<=i;j++)
        {
            if(c[j]=='0')
                fenzi=3*fenzi;
            else
            {
                if(c[j]=='1')
                    fenzi=3*fenzi+1;
                else
                    fenzi=3*fenzi-1;
            }
        }
        if(zhengshu>=0)
        {
            if(fenzi<0)
                {
                    fenzi=fenmu+fenzi;
                    zhengshu=zhengshu-1;
                    }
        }
        else
        {
            if(fenzi>0)
            {
                fenzi=fenzi-fenmu;
                zhengshu=zhengshu+1;
                fenzi=(-1)*fenzi;
            }
        }
        if(zhengshu==0)
            printf("%d %d",fenzi,fenmu);
        else
        printf("%d %d %d",zhengshu,fenzi,fenmu);
    }
}
