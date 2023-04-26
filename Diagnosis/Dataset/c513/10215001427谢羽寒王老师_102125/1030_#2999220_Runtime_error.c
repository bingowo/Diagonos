#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *x,const void *y)
{
    char *p1,*p2,*d1,*d2;
    p1=*((char**)x);
    p2=*((char**)y);
    int u=0;
    while(*(p1++)=='-') u++;
    d1=p1+u;
    u=0;
    while(*(p2++)=='-') u++;
    d2=p2+u;

    if(d1==d2) return p1-p2;
    else return d2-d1;

}


int main(){
    int T,N,i,j;
    char** a=0;
    char *p=0,*s=0;
    long long int n =1e18 ;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        a=(char**)malloc(N*sizeof(char*));
        p=(char*)malloc(n+1);
        for(j=0;j<N;j++){
            scanf("%s",&p+j);
            *(a+j)=p+j;

        }
       qsort(a,N,sizeof(char*),cmp);

        for(j=0;j<N;j++){
            printf("%s ",*a[j]);

        }


     printf("case #%d:",i);
     for(j=0;j<N;j++){
        printf("%s",*a++);   }
    p=NULL;a=NULL;s=NULL;
    free(p);
    free(a);
    free(s);
    }

return 0;
}