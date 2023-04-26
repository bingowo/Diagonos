#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define C 21
int cmp(const void* a,const void* b)
{
    return *(char*)a-*(char*)b;
}
int main()
{
    int T,i,j,len;scanf("%d",&T);
    char s[C];
    for(int cas=0;cas<T;++cas)
    {
        scanf("%s",s);
        len=strlen(s);int flag=0,max=0,match=len-1;
        for(i=len-1;i>0;--i)
        {
            for(j=i-1;j>-1;--j)
                if(s[j]<s[i]){flag=1;if(j>max){max=j;match=i;}
        }
        if(flag)
        {
            char tmp=s[match];s[match]=s[max];s[max]=tmp;
            qsort(s+j+1,len-j-1,sizeof(char),cmp);
            printf("case #%d:\n%s\n",cas,s);
        }
        else
        {
            s[len]='0';s[len+1]='\0';
            qsort(s,len+1,sizeof(char),cmp);
            for(i=0;s[i];i++)
            {
                if(s[i]>'0')
                {
                    s[0]=s[i];
                    s[i]='0';
                    break;        
                }
            }
            printf("case #%d:\n%s\n",cas,s);
        }
    }
    return 0;
}