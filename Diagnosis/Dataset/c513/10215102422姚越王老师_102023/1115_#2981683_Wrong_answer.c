#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define C 25
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
        len=strlen(s);int flag=0;
        for(i=len-1;i>0;--i)
        {
            for(j=i-1;j>-1;--j)
            {
                if(s[j]<s[i]){flag=1;break;}
            }
            if(flag)break;
        }
        if(flag)
        {
            char tmp=s[i];s[i]=s[j];s[j]=tmp;
            qsort(s+j+1,len-j-1,sizeof(char),cmp);
            printf("case #%d:\n%s\n",cas,s);
        }
        else
        {
            for(j=len;j>1;--j)s[j]=s[j-1];
            s[1]='0';s[len+1]='\0';
            printf("case #%d:\n%s\n",cas,s);
        }
    }
    return 0;
}