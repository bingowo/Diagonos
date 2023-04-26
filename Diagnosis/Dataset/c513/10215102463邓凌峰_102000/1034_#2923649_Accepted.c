#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char low;
    char up;
    double f;
}Z;

typedef struct{
    char c;
    double ff;
}W;

int cmp(const void *a,const void *b)
{
    W pa=*(W*)a,pb=*(W*)b;
    if(pa.ff!=pb.ff) return pa.ff>pb.ff?-1:1;
    else{
        if(abs(pa.c-pb.c)==32) return pa.c>pb.c?-1:1;//同大小写字母(例如A，a)
        return tolower(pa.c)>tolower(pb.c)?1:-1;//不同字母(如a，b)
    }
}


int main()
{
    int T;scanf("%d",&T);

    for(int i=0;i<T;i++){//获取字母频率表
        Z zifu[26];
        for(int j=0;j<26;j++){
            scanf("%lf",&zifu[j].f);
            zifu[j].low='a'+j;
            zifu[j].up='A'+j;
        }

        char xx=getchar();//读掉回车

        W words[101];
        char tmp=getchar();
        int cnt=0;
        while(tmp!='\n'){
            words[cnt].c=tmp;
            if('a'<=tmp && tmp<='z')
                words[cnt].ff=zifu[tmp-'a'].f;
            if('A'<=tmp && tmp<='Z')
                words[cnt].ff=zifu[tmp-'A'].f;
            tmp=getchar();
            cnt++;
        }
        qsort(words,cnt,sizeof(W),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<cnt;j++){
            printf("%c",words[j].c);
        }
        printf("\n");

    }

}

