#include <stdio.h>
#include <stdlib.h>
 int cmpA(const void * a,const void * b)
{
    return (*(int*)a-*(int*)b);
}
int cmpD(const void * a,const void * b)
{
    return (*(int*)b-*(int*)a);
}

int main()
{
    char sign;
    scanf("%c\n",&sign);
    int i=0,N[100];
    while(scanf("%d",&N[i])!=EOF){
        i++;
        for(int j=0;j<i-1;j++){
            if(N[i]==N[j]){
                i--;
               break;
            }
        }
    }
    if(sign=='A') qsort(N,i,sizeof(int),cmpA);
    else if(sign=='D') qsort(N,i,sizeof(int),cmpD);
    for(int j=0;j<i;j++){
        if(j==i-1) printf("%d",N[j]);
        else printf("%d ",N[j]);
    }
    return 0;
}
