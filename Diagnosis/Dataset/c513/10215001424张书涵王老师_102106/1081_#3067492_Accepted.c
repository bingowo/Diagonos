#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nci(char*s1,char*s2,int*c,int n)
{
    int i,j;
    if(s1[0]==0)
    {
        int n1=n,i,n2=n,j;
        for(i=0;n1>0;n1=n1/10,i++)
            s1[i]=n1%10+'0';
        for(i=0;n2>0;n2=n2/10,i++)
            s2[i]=n2%10+'0';
        int lenth;
        lenth=strlen(s1);
        for(j=0;j<lenth;j++)
        {
            for(i=0;i<lenth;i++)
                c[i+j]=c[i+j]+(s1[i]-'0')*(s2[j]-'0');
        }
        int l=2*lenth-1;
        for(i=0;i<(2*lenth+1);i++)
        {
            if(c[i]>=10)
            {
                if(i==(l-1))
                    l++;
                c[i+1]=c[i+1]+c[i]/10;
                c[i]=c[i]%10;
            }
        }
        int lenth1;
        lenth1=strlen(s1);
        for(i=0;i<lenth1;i++)
            s1[i]=0;
        for(i=0;i<l;i++)
            s1[i]=c[i]+'0';
    }
    else
    {
        int lenth2,lenth1;
        lenth2=strlen(s2);lenth1=strlen(s1);
        for(i=0;i<(lenth1+lenth2+1);i++)
            c[i]=0;
        for(i=0;i<lenth1;i++)
        {
            for(j=0;j<lenth2;j++)
                c[i+j]=c[i+j]+(s1[i]-'0')*(s2[j]-'0');
        }
        int l=lenth1+lenth2-1;
        for(i=0;i<(lenth1+lenth2+1);i++)
        {
            if(c[i]>=10)
            {
                if(i==(l-1))
                    l++;
                c[i+1]=c[i+1]+c[i]/10;
                c[i]=c[i]%10;
            }
        }
        for(i=0;i<lenth1;i++)
            s1[i]=0;
        for(i=0;i<l;i++)
            s1[i]=c[i]+'0';
    }
}

void reverse(char*s)
{
    int i,j;
    char c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

int main()
{
    int T,question_num;
    scanf("%d",&T);
    for(question_num=0;question_num<T;question_num++)
    {
        int a,n;
        scanf("%d %d",&a,&n);
        printf("case #%d:\n",question_num);
        if(n==0)
            printf("1\n");
        else
        {
            char s1[1000]={0},s2[1000]={0};
            int c[1000]={0};
            int n1=n;
            if(n==1)
            {
                printf("%d\n",a);
                return 0;
            }
            for(;n1>1;n1--)
                nci(s1,s2,c,a);
            reverse(s1);
            printf("%s\n",s1);
        }
    }
}