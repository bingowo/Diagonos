#include<stdio.h>
#include<string.h>
int main()
{
    int T,n;
    scanf("%d",&T);
    for(n=0;n<T;n++)
    {
        char s1[81],s2[81],s[81];
        printf("case #%d:\n",n);
        scanf("%s %s %s",s1,s2,s);
        int i,j,maxlen,maxlen1=0,maxlen2=0,lens1,lens2,lens,k,i1=-1,i2=-1,j1=-1,j2=-1,num,k1=0,k2=0;
        lens1=strlen(s1);
        lens2=strlen(s2);
        lens=strlen(s);
        for(i=0;i<lens-lens1-lens2;i++)
        {
            if(s[i]==s1[0]&&k1==0)
            {
                num=0;
                for(k=0;k<lens1;k++)
                {
                    if(s[i+k]==s1[k])num++;
                }
                if(num==lens1)
                {
                    i1=i+lens1;
                    k1=1;
                }
            }
            if(s[i]==s2[0]&&k2==0)
            {
                num=0;
                for(k=0;k<lens2;k++)
                {
                    if(s[i+k]==s2[k])num++;
                }
                if(num==lens2)
                {
                    i2=i+lens2;
                    k2=1;
                }
            }
        }
        k1=0;
        k2=0;
        for(j=lens-1;j>lens1+lens2-1;j--)
        {
            if(s[j]==s1[0]&&k1==0)
            {
                num=0;
                for(k=0;k<lens1;k++)
                {
                    if(s[j+k]==s1[k])num++;
                }
                if(num==lens1)
                {
                    j1=j;
                    k1=1;
                }
            }
            if(s[j]==s2[0]&&k2==0)
            {
                num=0;
                for(k=0;k<lens2;k++)
                {
                    if(s[j+k]==s2[k])num++;
                }
                if(num==lens2)
                {
                    j2=j;
                    k2=1;
                }
            }
        }
        if(j1!=-1&&i2!=-1)maxlen1=j1-i2;
        if(j2!=-1&&i1!=-1)maxlen2=j2-i1;
        if(maxlen2>maxlen1)maxlen=maxlen2;
        else maxlen=maxlen1;
        printf("%d\n",maxlen);
    }
    return 0;
}
