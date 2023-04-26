#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int s[100005];
int cmp(const void *a, const void *b){
        int num_1=*(int *)a;
        int num_2=*(int *)b;
        int i=0,j=0;
        while(num_1){num_1/=10;i++;}
        while(num_2){num_2/=10;j++;}
        if(i!=j) return j-i;
        else return *(int *)a-*(int *)b;

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
    qsort(s,i,sizeof(int),cmp);
    for(int j=0;j<i;j++){
        printf("%d ",s[j]);
    }

    return 0;
}