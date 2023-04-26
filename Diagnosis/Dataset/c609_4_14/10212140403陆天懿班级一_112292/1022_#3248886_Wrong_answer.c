#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

int n;
char *user[150000],*host[150000];
char t[1000005],*tu,*th;
int pi[150000];

int Cmp(int* pa,int* pb){
    int ia=*pa,ib=*pb;
    int t1;
    t1=strcmp(host[ia],host[ib]);
    if(t1) return t1;
    return -strcmp(user[ia],user[ib]);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",t);
        tu = strtok(t,"@");
        th = strtok(NULL,".");
        user[i]=calloc(strlen(tu)+1,sizeof(char));
        host[i]=calloc(strlen(th)+1,sizeof(char));
        strcpy(user[i],tu);
        strcpy(host[i],th);
        pi[i]=i;
    }

    qsort(pi,n,sizeof(pi[0]),Cmp);

    for(int i=0;i<n;i++)
        printf("%s@%s.com\n",user[pi[i]],host[pi[i]]);

    for(int i=0;i<n;i++)
        free(user[i]),free(host[i]);
    return 0;
}
