#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
typedef long long ll;
typedef unsigned long long ull;
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

#define N 20
int book[256];
int n;
char s[N],r[N];
int ri[N];

void Clean(){
    n=0;
    memset(book,0,sizeof(book));
    for(int i=0;s[i]!='\0';i++){
        if(!book[s[i]]){
            book[s[i]]=1;
            s[n++]=s[i];
        }
    }
    s[n]='\0';
}

void dfs(int step){
    if(step==n || step>1&&r[step-1]=='\0'){
        printf("%s\n",r);
        return;
    }

    if(step>0){
        r[step]='\0';
        ri[step]=-1;
        dfs(step+1);
        for(int i=ri[step-1]+1;i<n;i++){
            r[step]=s[i];
            ri[step]=i;
            dfs(step+1);
        }
        return;
    }
    if(step==0){
        for(int i=0;i<n;i++){
            r[step]=s[i];
            ri[step]=i;
            dfs(step+1);
        }
        return;
    }
}

int main(){
    int pros;
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%s",s);
        Clean();
        qsort(s,n,sizeof(s[0]),strcmp);
        printf("case #%d:\n",cnt);
        dfs(0);
    }

    return 0;
}
