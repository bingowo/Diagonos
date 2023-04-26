#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double p[26];

int cmp(const void *a,const void *b)
{
    char x=*(char*)a;
    char y=*(char*)b;

    int m,n;
    if(x>='A'&&x<='Z') m=x-'A';
    else if(x>='a'&&x<='z') m=x-'a';

    if(y>='A'&&y<='Z') n=y-'A';
    else if(y>='a'&&y<='z') n=y-'a';

    if(p[m]!=p[n])//频率不同
        return p[n]-p[m];
    else{       //频率相同
        if(m==n)//同种字母，如A和a
        {
            if(x!=y) return y-x;//小写排在大写前
        }
        else return m-n;//不同种字母
    }

}

int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
        printf("case #%d:\n",k);
        for(int i=0;i<26;i++)
            scanf("%lf",&p[i]);
        char s[101];
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        printf("%s\n",s);
    }
    return 0;
}
