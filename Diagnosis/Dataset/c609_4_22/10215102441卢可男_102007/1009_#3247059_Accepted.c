#include <stdio.h>
#include <stdlib.h>
void snack(int m,int n)//最简分数输出
{
    int a,b,t;
    a=m;
    b=n;
    while(b)
    {
        t=a%b;
        a=b;
        b=t;
    }
    m/=a;
    n/=a;
    printf("%d/%d\n",n,m);
}
int main()
{
    int n;
    scanf("%d",&n);
    char c=getchar();
    while(n--)
    {
        //printf("Hello world0!\n");
        char t;
        int all=0;
        int cout_1=0;
        while((t=getchar())!='\n')
        {
            all++;
            //printf("Hello world1!\n");
            while(t)
            {
                //printf("Hello world2!\n");
               t=t&(t-1);
               cout_1++;


            }
        }
        all=8*all;
        snack(all,cout_1);
    }
    //printf("Hello world!\n");
    return 0;
}

