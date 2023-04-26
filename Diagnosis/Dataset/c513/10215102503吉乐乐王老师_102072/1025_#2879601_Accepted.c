#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int dic[128];
    char str[1000];
}node;

int cmp(const void *a,const void*b){
    node x=*(node*)a;node y=*(node*)b;
    int cntx=0,cnty=0;
    for(int i=0;i<128;i++){
        if(x.dic[i]!=0)cntx++;
    }
    for(int i=0;i<128;i++){
        if(y.dic[i]!=0)cnty++;
    }
    if(cntx==cnty)return strcmp(x.str,y.str);
    return cnty-cntx;
}
int main(){
    int t;int idx=0;
    scanf("%d",&t);getchar();
    while(t--){
        int num;
        scanf("%d",&num);getchar();
        node* tar=(node*)malloc(sizeof(node)*num);int ti=0;
        while(num--){
            scanf("%s",tar[ti].str);getchar();
            for(int i=0;i<128;i++)tar[ti].dic[i]=0;
            for(int i=0;i<strlen(tar[ti].str);i++){
                char ch=tar[ti].str[i];tar[ti].dic[ch]++;
            }
            ti++;
        }
        qsort(tar,ti,sizeof(tar[0]),cmp);
        printf("case #%d:\n",idx++);
        for(int i=0;i<ti;i++){
            printf("%s\n",tar[i].str);
        }
    }
}