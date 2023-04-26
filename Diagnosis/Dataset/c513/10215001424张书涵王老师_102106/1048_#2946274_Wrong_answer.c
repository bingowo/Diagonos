#include <stdio.h>
#include <stdlib.h>

struct duoxiangshi
{
    char s1[100];
    char s2[100];
};

int main()
{
    char s11[100]={0};
    char s22[100]={0};
    while(scanf("%s%s",s11,s22)==2)
    {
        int i;
        int a[250]={0};//[]内表示指数的大小，存储每个指数对应的系数
        int l1,l2,sign1,sign2;//分别存储s1和s2的系数
        struct duoxiangshi c;
        for(i=0;s11[i];i++)
            c.s1[i]=s11[i];
        c.s1[i]=0;
        int j;
        for(j=0;s22[j];j++,i++)
            c.s2[j]=s22[j];
        c.s2[j]=0;
        for(i=0;c.s1[i];)
        {
            l1=0;
            sign1=(c.s1[i]=='-')?-1:1;
            if(c.s1[i]=='x')
                l1=1;
            if(c.s1[i]=='+'||c.s1[i]=='-')
                i++;
            for(;c.s1[i]>48&&c.s1[i]<58;i++)
                l1=l1*10+c.s1[i]-'0';
            l1=(sign1)*l1;
            int k1=0;
            for(;;i++)
            {
                if(c.s1[i]==0)
                {
                    k1=0;break;
                }
                else
                {
                    if(c.s1[++i]!='^')
                    {
                        k1=1;break;
                    }
                    else
                    {
                        i++;
                        for(;c.s1[i]>48&&c.s1[i]<58;i++)
                            k1=k1*10+c.s1[i]-'0';
                        break;
                    }
                }
            }
            for(j=0;c.s2[j];)//用s1分别乘s2
            {
                l2=0;
                sign2=(c.s2[j]=='-')?-1:1;
                if(c.s2[j]=='x')
                    l2=1;
                if(c.s2[j]=='-'||c.s2[j]=='+')
                    j++;
                for(;c.s2[j]>48&&c.s2[j]<58;j++)
                    l2=l2*10+c.s2[j]-'0';
                l2=(sign2)*l2;
                int k=0,k2=0;//分别的指数
                for(;;j++)
                {
                    if(c.s2[j]==0)
                    {
                        k2=0;break;
                    }
                    else
                    {
                        if(c.s2[++j]!='^')
                        {
                            k2=1;break;
                        }
                        else
                        {
                            j++;
                            for(;c.s2[j]>48&&c.s2[j]<58;j++)
                                k2=k2*10+c.s2[j]-'0';
                            break;
                        }
                    }
                }
                k=k1+k2;
                a[k]=a[k]+l1*l2;
            }
        }
        int k;
        for(k=250;k>=0;k--)
        {
            if(a[k]==0);
            else
            {
                printf("%d",a[k]);
                printf(" ");
            }
        }
        printf("\n");
        fflush(stdout);
    }
}