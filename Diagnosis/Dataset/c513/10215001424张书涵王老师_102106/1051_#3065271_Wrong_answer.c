#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void reverse(int* s)
{
    int i,j;
    int k;
    for(i=0,j=7;i<j;i++,j--)
    {
        k=s[i];
        s[i]=s[j];
        s[j]=k;
    }
}

int main()
{
    int T,question_num;
    scanf("%d ",&T);
    for(question_num=0;question_num<T;question_num++)
    {
        char s[101]={0};
        char c[100]={0};
        int total_num[1000]={0};//one_num用来存储每一个字符的二进制，total_num用来存储整个字符串的二进制;
        gets(s);
        int i,quotient=0,remainder=0,j,p=0;
        for(i=0;s[i];i++)
        {
            int one_num[9]={0};
            for(quotient=s[i],j=0;j<8;quotient=quotient/2,j++)
                one_num[j]=quotient%2;
            reverse(one_num);
            for(j=0;j<8;j++,p++)
                total_num[p]=one_num[j];
        }
        if(p%6==0)
        {
            int k=0;
            for(i=0;i<p;i++)
            {
                int number=0,q;
                for(j=i+5,q=0;j>=i;j--,q++)
                    number=number+total_num[j]*pow(2,q);
                if(number>=0&&number<=25)
                    c[k++]=number+65;
                if(number>=26&&number<=51)
                    c[k++]=number+71;
                if(number>=52&&number<=61)
                    c[k++]=number-4;
                if(number==62)
                    c[k++]='+';
                if(number==63)
                    c[k++]='/';
                i=i+5;
            }
            if(k%4!=0)
            {
                remainder=k+4-k%4;
                for(;k<remainder;k++)
                    c[k]='=';
            }
        }
        else
        {
            remainder=p%6;
            p=p+6-remainder;
            int k=0;
            for(i=0;i<p;i++)
            {
                int number=0,q;
                for(j=i+5,q=0;j>=i;j--,q++)
                    number=number+total_num[j]*pow(2,q);
                if(number>=0&&number<=25)
                    c[k++]=number+65;
                if(number>=26&&number<=51)
                    c[k++]=number+71;
                if(number>=52&&number<=61)
                    c[k++]=number-4;
                if(number==62)
                    c[k++]='+';
                if(number==63)
                    c[k++]='/';
                i=i+5;
            }
            if(k%4!=0)
            {
                remainder=k+4-k%4;
                for(;k<remainder;k++)
                    c[k]='=';
            }
        }
        printf("case #%d:\n",question_num);
        for(i=0;i<p;i++)
            printf("%c",c[i]);
        printf("\n");
    }
}