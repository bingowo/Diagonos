#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return a-b;
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        char s[101];
        scanf("%s",&s);
        int l=strlen(s);
        int a[l];
        for(int j=0;j<l;j++)
        {
            a[j]=0;
        }
        int num=0;
        for(int j=1;j<l;j++)
        {
            if(s[j]==s[j-1])
            {
                a[j]=1;
                a[j-1]=1;
            }
        }
        for(int j=0;j<l;j++)
        {
            if(a[j]==1)
            {
                num++;
            }
        }
        printf("case #%d:\n",i);
        if(num==l)
        {
           printf("%d\n",num+1); 
        }
        else
        {
            if(l-num<=2)
            {
                printf("%d\n",num+2);
            }
            else
            {
                char str[l-num];
                int n=0;
                for(int j=0;j<l;j++)
                {
                    if(a[j]==0)
                    {
                        str[n]=s[j];
                        n++;
                    }
                }
                int b[l-num-2];
                for(int j=0;j<l-num-2;j++)
                {
                    b[j]=2;
                }
                for(int j=1;j<l-num-1;j++)
                {
                    int m=j;
                    int x=1;
                    for(int k=1;m-k>=0&&m+k<l-num;k++)
                    {
                        if(str[m-k]==str[m+k])
                        {
                            b[j-1]+=2;
                        }
                    }
                }
                qsort(b,l-num-2,sizeof(int),cmp);
                printf("%d\n",b[l-num-3]+num);
            }
        }
    }
    return 0;
}
