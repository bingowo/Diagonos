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
    char e1,e2;
    e1=d1[0];
    e2=d2[0];
    if(d1==d2) return p1-p2;
    else return d2-d1;

}


int main(){
    int T,N,i,j;
    char** a=0;

    char *p=0,s[10000];
    int len;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        a=(char**)malloc(N*sizeof(char*));

        for(j=0;j<N;j++){
            scanf("%s",&s);
            long long int len=strlen(s);
        p=(char*)malloc(len+1);
        strcpy(p,s);

            *(a+j)=p;

        }
       qsort(a,N,sizeof(char*),cmp);


     printf("case #%d:\n",i);
     for(j=0;j<N;j++){
        printf("%s ",a[j]);   }
    printf("\n");
    p=NULL;a=NULL;
    free(p);
    free(a);

    }

return 0;
}









