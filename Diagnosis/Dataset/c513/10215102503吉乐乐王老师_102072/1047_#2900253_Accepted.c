#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
    char ch;
    int count;
}node;
int main(){
    int t;scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        char s[501];char *ps=s;
        gets(s);
        node ret[501];int idx=0;
        int cnt=0;
        while(*ps){
            char pre=*ps;cnt=1;
            ps++;
            while(*ps==pre&&*ps){
                cnt++;
                pre=*ps;ps++;
                if(cnt>=255)break;
            }
            ret[idx].count=cnt;
            ret[idx].ch=pre;
            idx++;
        }
        printf("case #%d:\n",cas++);
        for(int i=0;i<idx;i++){
            printf("%d%c",ret[i].count,ret[i].ch);
        }
        putchar('\n');
    }
}