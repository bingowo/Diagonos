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
    //printf("%d",EOF);
    while(n--)
    {
        //printf("Hello world0!\n");
        char t;
        int cout_0=0;
        int cout_1=0;
        while(scanf("%c",&t)!=EOF)
        {
            //printf("Hello world1!\n");
            while(t)
            {
                if(t&1)
                {
                   cout_1++;
                }
                else
                {
                    cout_0++;
                }
                t=t>>1;
            }
        }
        snack(cout_1+cout_0,cout_1);
    }
   // printf("Hello world!\n");
    return 0;
}
