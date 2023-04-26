#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char s[110];
    double num;
    int flag;
}node;

int cmp(const void *a,const void *b)
{
    if((*(node*)a).flag != (*(node*)b).flag) return (*(node*)a).flag - (*(node*)b).flag;
    else{
        if((*(node*)a).num > (*(node*)b).num){
            if((*(node*)a).flag > 0) return 1;
            else return -1;
        }
        else {
            if((*(node*)a).flag > 0) return -1;
            else return 1;
        }
    }
}

int main()
{
    int n;scanf("%d",&n);
    node *ans = (node*) calloc(n,sizeof*ans);
    for(int i = 0;i < n;i++){
        scanf("%s",ans[i].s);
        if(ans[i].s[0] == '-') ans[i].flag = -1;
        else ans[i].flag = 1;
        if(!isdigit(ans[i].s[0])){
            ans[i].num = atof(ans[i].s+1);
        }
        else ans[i].num = atof(ans[i].s);
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    for(int i = 0;i < n;i++){
        printf("%s\n",ans[i].s);
    }
    free(ans);
    return 0;
}