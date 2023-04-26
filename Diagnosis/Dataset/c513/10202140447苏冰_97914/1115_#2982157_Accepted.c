#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
{
    int* p=(int*)a;
    int* q=(int*)b;
    return (*p-*q);
}
int main()
{
    char s[30];
    int a[30];
    int xx[30];
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        scanf("%s",s);
        printf("case #%d:\n",cas);
        int len=strlen(s);int flag=0;
        for(int i=0;i<len;i++) a[i]=s[i]-'0';
        for(int i=len-2;i>=0;i--)
        {
            flag=0;int sign=0;
            int min=0,pos=0;
            for(int j=len-1;j>i;j--)
            {
                if(a[j]>a[i])
                {
                    flag=1;
                    if(sign==0)
                    {
                        min=a[j];
                        pos=j;
                        sign=1;
                    }
                    if(a[j]<min)
                    {
                        min=a[j];
                        pos=j;
                    }
                }
            }
            if(flag)
            {
                int t=a[i];
                a[i]=a[pos];
                a[pos]=t;
                int k=0;
                for(int j=i+1;j<len;j++)
                {
                    xx[k++]=a[j];
                }
                qsort(xx,k,sizeof(xx[0]),cmp);
                for(int j=0;j<=i;j++) printf("%d",a[j]);
                for(int j=0;j<k;j++) printf("%d",xx[j]);
                break;
            }
        }
        if(flag==0)
        {
            for(int i=len;i>=1;i--) a[i]=a[i-1];
            a[0]=0;
            len++;
            for(int i=len-2;i>=0;i--)
        {
            flag=0;int sign=0;
            int min=0,pos=0;
            for(int j=len-1;j>i;j--)
            {
                if(a[j]>a[i])
                {
                    flag=1;
                    if(sign==0)
                    {
                        min=a[j];
                        pos=j;
                        sign=1;
                    }
                    if(a[j]<min)
                    {
                        min=a[j];
                        pos=j;
                    }
                }
            }
            if(flag)
            {
                int t=a[i];
                a[i]=a[pos];
                a[pos]=t;
                int k=0;
                for(int j=i+1;j<len;j++)
                {
                    xx[k++]=a[j];
                }
                qsort(xx,k,sizeof(xx[0]),cmp);
                for(int j=0;j<=i;j++) printf("%d",a[j]);
                for(int j=0;j<k;j++) printf("%d",xx[j]);
                break;
            }
        }

        }
        printf("\n");
    }
    return 0;
}
