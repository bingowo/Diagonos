#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T,N,i,j;
    char** a=0;
    char *p=0,*s=0;
    long long int n =1e18 ;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        a=(char**)malloc(N*sizeof(char*));
        s=(char*)malloc(n+1);
        for(j=0;j<N;j++){
            scanf("%s",&s);
            long long int len =strlen(s);
            p=(char*)malloc(len+1);    //len+1 * sizeof(char)
            strcpy(p,s);
            *(a+j)=p;

        }
       qsort(a,N,sizeof(char*),cmp);

        for(j=0;j<N;j++){
            printf("%s ",*a[j]);

        }






     printf("case #%d",i);
     for(j=0;j<N;j++){
        printf("%s",*a++);   }
    p=NULL;a=NULL;s=NULL;
    free(p);
    free(a);
    free(s);
    }


}
