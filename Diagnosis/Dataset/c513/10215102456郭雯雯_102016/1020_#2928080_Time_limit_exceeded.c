#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    while(n!=0){
        int m=n;
        struct group{
            int year;int mou;int date;int hour;int minu;int size;
            char s[64];
        }g[m];
        char order[10];
        for(int i=0;i<m;i++){
            scanf("%d-%d-%d",&g[i].year,&g[i].mou,&g[i].date);
            scanf("%d:%d",&g[i].hour,&g[i].minu);
            scanf("%d",&g[i].size);
            scanf("%s",&g[i].s);
        }
        scanf("%s",order);
        printf("\n");
        scanf("%d",&n);
    }
}