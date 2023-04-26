#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        int fir=-1,val;
        printf("case #%d:\n",c);
        for(int i=8;i>=0;i--)
        {
            scanf("%d",&val);
            if(val==0)
                continue;
            if(fir!=-1&&val>0) //fir使第一个正数不会带上符号
                putchar('+');
            if(val==-1)
                putchar('-');
            else if(val!=1)
                printf("%d",val);
            if(i>1)
                printf("x^%d",i);
            else if(i==1)
                putchar('x');
            fir=i;
            if((val==1||val==-1)&&i==0) //特殊情况处理
                putchar('1');
        }
        if(fir==-1)
            putchar('0');
        puts("");
    }
    return 0;
}
//注意表示的方式吧
//知道原理也要会表达
