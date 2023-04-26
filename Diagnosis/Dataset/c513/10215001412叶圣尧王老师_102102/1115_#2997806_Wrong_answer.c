#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void*a,const void*b)
{
    return *(char*)a-*(char*)b;
}

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char s[22],p[22];scanf("%s",s);int i,j;
        int len=strlen(s),flag=0;
        for(i=len-1;i>=0&&flag==0;i--)
        {
            for(j=len-2;j>=0&&flag==0;j--)
            {
                if(s[i]>s[j])
                {
                    int t=s[j];s[j]=s[i];s[i]=t;
                    qsort(s+j+1,len-j-1,sizeof(char),cmp);
                    flag=1;
                }
            }
        }
        printf("case #%d:\n%s\n",t,s);
    }
}
