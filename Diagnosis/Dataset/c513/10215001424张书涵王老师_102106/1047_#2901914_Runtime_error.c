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
        char c[1000];
        int l,j,k=0,r=0;
        printf("case #%d:\n",i);
        for(j=0;s[j];j=k+1)
        {
            l=1;
            int k1;
            char c2[100];
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
                int n,m;
                n=l/255;
                m=l%255;
                for(k=0;k<3*n;k++)
                {
                    if(k==0||k%3==0)
                        c2[k]='2';
                    else
                        c2[k]='5';
                }
                for(;m>0;k++)
                {
                    c2[k]=m%10+'0';
                    m=m/10;
                }
                c2[k]=0;
                reverse(c2);
                for(k=0;c2[k];k++,r++)
                    c[r]=c2[k];
                c[r++]=s[k];
            }
        }
        for(r=0;c[r];r++)
            printf("%c",c[r]);
        printf("\n");
    }
}
