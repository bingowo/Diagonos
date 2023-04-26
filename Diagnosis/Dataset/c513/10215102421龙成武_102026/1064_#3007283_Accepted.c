#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
double func(char *s)
{
    char operator[100],*p,*q;
    double ans,val[100],t1,t2,temp;
    int i,len,numofop=0,numofval=0,valofop[100]={0};    //valofop记录当前操作符的操作数个数,numofval记录总的操作数个数,numofop记录操作符个数
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]==' ')
            s[i]=0;
    }
    p=s-1;
    q=strchr(p+1,0);
    while(p!=s+len)
    {
        if(*(p+1)=='+'||*(p+1)=='-'||*(p+1)=='*'||*(p+1)=='/')
        {
            operator[numofop++]=*(p+1);      //当前的操作符在operator里的索引为numofop-1
        }
        else
        {
            sscanf(p+1,"%lf",&val[numofval++]);
            valofop[numofop-1]++;
            while (valofop[numofop-1] == 2)       //当前操作符有俩操作数，则可以进行运算
            {
                t2 = val[--numofval];
                t1 = val[--numofval];
                switch (operator[--numofop])
                {
                case('+'):
                    temp = t1 + t2;break;
                case('-'):
                    temp = t1 - t2;break;
                case('*'):
                    temp = t1 * t2;break;
                case('/'):
                    temp = t1 / t2;break;
                }
                valofop[numofop] = 0;
                val[numofval++] = temp;
                valofop[numofop-1]++;
            }
        }
        p=q;
        q=strchr(p+1,0);
    }
    ans=val[0];
    return ans;
}
int main()
{
    int T,i;
    char s[100];
    double ans;
    scanf("%d",&T);
    gets(s);
    for(i=0;i<T;i++)
    {
        gets(s);
        ans=func(s);
        printf("case #%d:\n%6f\n",i,ans);
    }
    return 0;
}
