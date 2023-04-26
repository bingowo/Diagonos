#include <stdio.h>
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}

int main(){
    char c;
    int s[100];
    int i=0;
    int j;
    scanf("%c",&c);
    while(scanf("%d",&s[i])!=EOF){
        i++;
    }
    qsort(s,i,sizeof(s[0]),cmp);
    if(c=='A'){
        printf("%d ",s[0]);
        for(j=1;j<i;j++){
            if(s[j]!=s[j-1]){
                printf("%d ",s[j]);
            }

        }
    }
    else{
        printf("%d ",s[i-1]);
        for(j=i-2;j>=0;j=j-1){
            if(s[j]!=s[j+1]){
                printf("%d ",s[j]);
            }
        }
    }
    return 0;






}
