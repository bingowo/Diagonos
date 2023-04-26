#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char n[505];
    scanf("%s",n);

    int len=strlen(n);//长度
    int a[100]= {0};
    int i=0;
    while(len!=0)//二进制
    {
        a[i]=len%2;
        len=len/2;
        i++;
    }

    printf("0001");
    for(int i=9;i>=0;i--)//输出
    {
        printf("%d",a[i]);
    }

    len=strlen(n);
    int len1=len-len%3;
    for(int i=0;i<len1;i+=3)//每三位
    {
        int b[10]= {0};
        int x=0;
        x=(n[0+i]-48)*100+(n[1+i]-48)*10+n[2+i]-48;//转为整数
        //printf("%d\n",x);
        int j=0;
        while(x!=0)//二进制
        {
            b[j]=x%2;
            x=x/2;
            j++;
        }
        for(int k=9; k>=0; k--)//输出
        {
            printf("%d",b[k]);
        }
    }
    
    int y=0,z=-1;//-1
    if(len%3==1)//末一
    {
        y=n[len-1]-48;
        z=3;
    }
    else if(len%3==2)//末二
    {
        y=(n[len-2]-48)*10+n[len-1]-48;
        z=6;
    }
    int b[10]= {0};
    int j=0;
    while(y!=0)//二进制
    {
        b[j]=y%2;
        y=y/2;
        j++;
    }
    for(int k=z; k>=0; k--)//输出
    {
        printf("%d",b[k]);
    }
    return 0;
}
