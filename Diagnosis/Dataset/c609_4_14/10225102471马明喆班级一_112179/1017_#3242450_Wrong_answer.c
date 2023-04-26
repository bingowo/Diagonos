#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a , const void *b){
    return *(int *)a - *(int *)b;
}

int cmp2(const void *a , const void *b){
    return *(int *)b-*(int *)a;
}

int main(){
    char a=getchar();
    int s[10000];
    int i=0;
    int x;
    while(scanf("%d",&x)!=EOF) {
        s[i]=x;
        i++;
    }
    i--;
    if(a=='A')
        qsort(s,sizeof(s[0]),i,cmp1);
    else
        qsort(s,sizeof(s[0]),i,cmp2);
    for(int t=0;t<i;t++){
        if(s[t]==s[t+1]) {
            for (int x = t; x < i; x++) {
                s[x] = s[x + 1];
                i--;
            }
        }
    }
    for(int x=0;x<i;x++){
        printf("%d ",s[x]);
    }
    printf("%d\n",s[i]);
    return 0;
}