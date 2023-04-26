#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int s[100005];
int cmp_2(const void *a, const void *b){
        return *(int *)a-*(int *)b;}
int cmp_1(const void *a, const void *b){
        

}
int main()
{
    int i=0;char c;
    memset(s,0,sizeof(s));
    while((c=getchar())!='\n'){
        if(isdigit(c)||c=='-'){
            ungetc(c,stdin);
            scanf("%d",&s[i++]);
        }
    }
    qsort(s,i,sizeof(int),cmp_1);
    for(int j=0;j<i;j++){
        printf("%d ",s[j]);
    }

    return 0;
}