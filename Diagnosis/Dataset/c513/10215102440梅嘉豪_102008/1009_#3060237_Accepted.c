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
        char s[1000];
        int a=0,b=0,t;
        // unsigned int *p=(unsigned int*)s;
        int i=0;
        while((s[i]=getchar())!='\n') 
        {i++;}
        s[i]=0;
        unsigned char *p=(unsigned char*)s;
        // printf("%s\n",s);
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


