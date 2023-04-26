#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long int lli;

typedef struct
{
    lli num;
    char word[16];
}W;


lli min(char s[])
{
    lli a[128];for(int i=0;i<128;i++) a[i]=-1;
    int digit=0,N=1; char *p=s;
    a[*p]=1;
    while (*++p){
        if (a[*p]==-1){
            a[*p]=digit;
            digit=digit?digit+1:2;
            N++;
        }
    }
    if (N<2) N=2; //不可能是一进制
    long long ans=0;
    p=s; while (*p) ans=ans*N+a[*p++];
    return ans;



}


int cmp(const void *a,const void *b)
{
    W pa=*(W*)a,pb=*(W*)b;
    if(pa.num!=pb.num) return pa.num>pb.num?1:-1;
    else return strcmp(pa.word,pb.word);
}



int main()
{
    lli N;scanf("%lld",&N);
    char xx=getchar();
    W words[N];
    for(int i=0;i<N;i++){
        scanf("%s",&words[i].word);
        words[i].num=min(words[i].word);
    }

    qsort(words,N,sizeof(W),cmp);

     for(int i=0;i<N;i++){
        printf("%s\n",&words[i].word);
    }
    
    return 0;
}
