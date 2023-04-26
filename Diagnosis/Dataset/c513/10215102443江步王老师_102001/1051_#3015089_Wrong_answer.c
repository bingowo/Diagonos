#include<stdio.h>
#include<malloc.h>

char ch[64];

void init_();
int main()
{
    init_();

    int t;
    int i,j,k;
    scanf("%d\n",&t);

    for (i=0;i<t;++i)
    {
        char s[101];
        int bi[1000]={0};
        int len=0;//len为二进制的长度
        scanf("%s",s);

        char* p = s;
        int n=0;//n为字符个数
        while (*p)
        {
            n++;
            char c=*p;

            int num=0;
            while(c>0)
            {
                bi[n*8-1-num]=c%2;
                num++;
                c/=2;
            }
            len+=8;
            p++;
        }
        //printf("len=%d\n",len);
        
        while ((len%6)!=0)
        {
            len++;
        }

        int num=len/6;
        //printf("num=%d\n",num);
        int* d = (int *)malloc(sizeof(int)*num);

        for (j=0;j<num;++j)
        {
            d[j]=0;
        }

        for (j=0;j<num;++j)
        {
            for (k=j*6;k<(j+1)*6;k++)
            {
                d[j]=d[j]*2+bi[k];
            }
        }

        printf("case #%d:\n",i);
        for (j=0;j<num;++j)
        {
            printf("%c",ch[d[j]]);
        }

        if (num<4)
        {
            for (j=0;j<4-num;++j)
            {
                putchar('=');
            }
        }

        putchar('\n');
        free(d);
    }
    return 0;
}

void init_()
{
    int i;
    for (i=0;i<26;++i)
    {
        ch[i]='A'+i;
    }
    for (i=26;i<26+26;++i)
    {
        ch[i]='a'+i-26;
    }

    for (i=52;i<52+10;++i)
    {
        ch[i]='0'+i-52;
    }
    ch[62]='+';ch[63]='/';

    return ;
}