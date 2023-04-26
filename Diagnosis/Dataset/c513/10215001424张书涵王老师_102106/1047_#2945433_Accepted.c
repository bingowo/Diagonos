#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* c)
{
    int i,j;
    char s;
    for(i=0,j=strlen(c)-1;i<j;i++,j--)
    {
        s=c[i];
        c[i]=c[j];
        c[j]=s;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        char s[1000];
        scanf("%s",s);
        char c[1000]={0};
        int l,j,k=0,r=0;
        printf("case #%d:\n",i);
        for(j=0;s[j];j=k+1)
        {
            l=1;
            int k1;
            char c2[100]={0};
            for(k=j;s[k];k++)//计算相同字符的个数l
            {
                if(s[k]==s[k+1])
                    l=l+1;
                else
                    break;
            }
            k1=k;
            if(l<=255)
            {
                for(k1=0;l>0;k1++)
                {
                    c2[k1]=l%10+'0';
                    l=l/10;
                }
                c2[k1]=0;
                reverse(c2);
                for(k1=0;c2[k1];k1++,r++)
                    c[r]=c2[k1];
                c[r++]=s[k];
            }
            else
            {
                int n,m,p;
                n=l/255;
                m=l%255;
                for(k1=0;k1<3*n;k1++)
                {
                    if(k1==0||k1%3==0)
                        c2[k1]='2';
                    else
                        c2[k1]='5';
                    if(k1%3==2)
                        c2[++k1]=s[k];
                }
                char c3[1000];
                for(p=0;m>0;p++)
                {
                    c3[p]=m%10+'0';
                    m=m/10;
                }
                c3[p]=0;
                reverse(c3);
                for(p=0;c3[p];p++,k1++)
                    c2[k1]=c3[p];
                c2[k1]=s[k];
                for(p=0;c2[p];p++,r++)
                    c[r]=c2[p];
            }
        }
        for(r=0;c[r];r++)
            printf("%c",c[r]);
        printf("\n");
    }
}
