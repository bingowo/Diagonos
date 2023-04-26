#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
    /*嘛嘛大概思路就是说1检测大小写小写减97大写减呃多少来着65吧应该2比较那个倒霉数组里的频率要是相同就比较*/
}

int main()
{
    double fre[27];
    char s[101];
    int T,cnt=0;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<26;i++)
            scanf("%f",fre[i]);
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        printf("case #%d:\n%s\n",cnt++,s);
    }
    return 0;
}
