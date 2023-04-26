#include <stdio.h>
#include <stdlib.h>

double arr[123]={0};
int cmp(const void*a,const void*b)
{
    char aa=*(char*)a,bb=*(char*)b;
    if(arr[aa]>arr[bb]) return -1;
    else if(arr[aa]<arr[bb]) return 1;
    else
    {
        if(aa+32==bb)
            return 1;
        else if(aa-32==bb)
            return -1;
        else
        {
            if(aa>'Z') aa-=32;
            if(bb>'Z') bb-=32;
            if(aa>bb) return 1;
            else if(aa<bb) return -1;
        }
    }
    return 0;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        for(int i=0;i<26;i++)
        {
            scanf("%lf",&arr['A'+i]);
            arr['a'+i]=arr['A'+i];
        }
        char s[101]={0};
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n%s\n",i,s);
    }
    return 0;
}