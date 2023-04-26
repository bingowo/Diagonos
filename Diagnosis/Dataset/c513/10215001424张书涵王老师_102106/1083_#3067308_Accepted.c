#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void multiply(int a,int b,char* s1,char* s2,int n)
{
    int i,j;
    int c[10001];
    if(s1[0]==0)
    {
        int quotient=0;
        for(quotient=a,i=0;quotient>0;quotient=quotient/10,i++)
            s1[i]=quotient%10+'0';
        for(quotient=a-1,i=0;quotient>0;quotient=quotient/10,i++)
            s2[i]=quotient%10+'0';
        int l1,l2;
        l1=strlen(s1);l2=strlen(s2);
        for(i=0;i<(l1+l2+1);i++)
            c[i]=0;
        for(i=0;s2[i];i++)
        {
            for(j=0;s1[j];j++)
                c[i+j]=(s2[i]-'0')*(s1[j]-'0')+c[i+j];
        }
        int l;
        l=l1+l2-1;
        for(i=0;i<(l1+l2+1);i++)
        {
            if(i>=(l-1)&&c[i]>10)
                l++;
            if(c[i]>=10)
            {
                c[i+1]=c[i+1]+c[i]/10;
                c[i]=c[i]%10;
            }
        }
        for(i=0;s1[i];i++)
            s1[i]=0;
        for(i=0;i<l;i++)
            s1[i]=c[i]+'0';
    }
    else
    {
        int quotient,l2,l1;
        l1=strlen(s1);
        l2=strlen(s2);
        for(i=0;i<l2;i++)
            s2[i]=0;
        for(quotient=a-1,i=0;quotient>0;quotient=quotient/10,i++)
            s2[i]=quotient%10+'0';
        l2=strlen(s2);
        for(i=0;i<(l1+l2+1);i++)
            c[i]=0;
        for(i=0;s2[i];i++)
        {
            for(j=0;s1[j];j++)
                c[i+j]=(s2[i]-'0')*(s1[j]-'0')+c[i+j];
        }
        int l;
        l=l1+l2-1;
        for(i=0;i<(l1+l2+1);i++)
        {
            if(i>=(l-1)&&c[i]>=10)
                l++;
            while(c[i]>=10)
            {
                c[i+1]=c[i+1]+c[i]/10;
                c[i]=c[i]%10;
            }
        }
        for(i=0;s1[i];i++)
            s1[i]=0;
        for(i=0;i<l;i++)
            s1[i]=c[i]+'0';
    }
}

int main()
{
    int T,question_num;
    scanf("%d",&T);
    for(question_num=0;question_num<T;question_num++)
    {
        int n,i,j;
        scanf("%d",&n);
        char s1[10001]={0},s2[10001]={0};
        for(i=n,j=i-1;j>0;i--,j--)
            multiply(i,j,s1,s2,n);
        int num=0;
        for(i=0;s1[i];i++)
        {
            if(s1[i]=='0')
            {
                if(s1[i+1]!='0')
                {
                    num++;break;
                }
                else
                    num++;
            }
        }
        printf("case #%d:\n%d\n",question_num,num);
    }
}