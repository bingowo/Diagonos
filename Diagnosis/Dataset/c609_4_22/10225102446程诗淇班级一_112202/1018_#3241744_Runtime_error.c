#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
    return *(int*)b-*(int*)a;
}

int main()
{
    int T;
    scanf("%d",&T);
    int s[100];
    for(int j=0;j<T;j++){
        scanf("%d",&s[j]);
    }
    qsort(s,T,sizeof(s[0]),cmp);
    int sum=0;
    for(int i=0;i<T-1;i=i+2){
        sum=sum+s[i]-s[i+1];

    }
    printf("%d",sum);
    return 0;

}
