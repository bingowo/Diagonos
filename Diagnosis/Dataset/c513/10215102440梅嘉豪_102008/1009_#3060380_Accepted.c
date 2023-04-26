#include <stdio.h>
#include <string.h>

int GCD(int a,int b)
{
    return b==0?a:GCD(b,a%b);
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        char s[1000]={0};
        int a=0,b=0,t;
        // unsigned int *p=(unsigned int*)s;
        unsigned char *p=(unsigned char*)s;
        // int i=0;
        // while((s[i]=getchar())!='\n') 
        // {i++;}
        // s[i]=0;
        // while((s[strlen(s)]=getchar())!='\n');//注意初始化s={0},否则strlen无意义
        // //不相等运算符优先级高于赋值运算符，注意用括号保证运算顺序！！
        // s[strlen(s)-1]=0;
        scanf("%[^\n]",s);
        char ch;
        while(ch=getchar())
        {
            if(ch=='\n')
            {
                s[strlen(s)]=0;
                break;
            }
            else    s[strlen(s)]=ch;
        }
        while(*p!=0)
        {
            t=1;
            for(int i=0;i<8;i++)
            {
                if((t&*p)) a++;
                t=t<<1;
            }
            p++;b++;
        }
        // printf("%d\n",b);

        b=b*8;
        int c=GCD(a,b);
        printf("%d/%d\n",a/c,b/c);

    }
}


