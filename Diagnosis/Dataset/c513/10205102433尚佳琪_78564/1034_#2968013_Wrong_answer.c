#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double p[128]={0};
int cmp(const void *a,const void *b)
{
    char s1=*(char*)a;
    char s2=*(char*)b;
   /* if(p[s1]!=p[s2])
    {
        if(p[s1]>p[s2])
            return -1;
        else
            return 1;
    }*/
    if(p[s2]>p[s1])
            return 1;

    //else return s2-s1;
    else if(fabs(p[s2]-p[s1])<1e-8)        //字母使用频率相同的情况
        return s2-s1;
                    /*if(p1==p2) return ch2-ch1;  //相同字母，小写在大写前面
                    else  return p1-p2;*/
    else
            return -1;
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
        char s[1000];
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        printf("%s\n",s);
    }

    return 0;
}

