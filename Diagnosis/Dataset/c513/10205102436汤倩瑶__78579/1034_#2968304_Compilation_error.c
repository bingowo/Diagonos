#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double p[128]={0};
int cmp(const void *a,const void *b)
{
    char s1=*(char*)a;
    char s2=*(char*)b;
   if(s1-s2==32)return -1;
    else if(s2-s1==32)return 1;
    else{
       if(f[c1-'A']>f[c2-'A'])return -1;
       else return 1;
    }

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        for(int i=0;i<26;i++)
        {
            scanf("%lf",&p['A'+i]);
            p['a'+i]=p['A'+i];
        }
        char s[101];
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        printf("case #%d:\n%s\n",i,s);
    }
    return 0;
}