#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int cmp(const void *a,const void *b)
{
    char a1=*(char *)a,b1=*(char *)b;
    return a1>b1?1:-1;
}

int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        char judge[128];
        for(int i=0;i<128;i++){
            judge[i]=0;
        }
        printf("case #%d:\n",step);
        char s[17];scanf("%s",s);
        char as[17];
        int k=0;
        for(int i=0;i<strlen(s);i++){
            if(judge[s[i]]++==0)as[k++]=s[i];
        }
        as[k]=0;
        qsort(as,k,sizeof(char),cmp);
        //as是排好的去重序列；
        int len=strlen(as),time=1;
        for(int i=0;i<len;i++)
            time*=2;
        time--;
    }
    return 0;
}
