#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    char* p;
    char* q;
    int a1;
    int a2;
}hhh;
int cmp(const void *a,const void *b){
    char* m1;
    char* m2;
    char* n1;
    char* n2;
    m1=(*(hhh*)a).p;
    m2=(*(hhh*)b).p;
    n1=(*(hhh*)a).q;
    n2=(*(hhh*)b).q;
    int f;
    int aa;
    f=strcmp(n1,n2);
    if(f!=0){
        return f;
    }
    else{
        aa=strcmp(m1,m2);
        return -aa;

    }
}

int main()
{
    int T;
    scanf("%d",&T);
    char c1=getchar();
    hhh* xxx;
    xxx=(hhh*)malloc(T*sizeof(hhh));
    char smax[2000000];
    int ph=0;
    for(int i=0;i<T;i++){
        xxx[i].p=smax+ph;
        char c;
        while((c=getchar())!='@'){
            smax[ph]=c;
            ph++;
        }
        smax[ph]='\0';
        ph++;
        xxx[i].q=smax+ph;
        while((c=getchar())!='\n'){
            smax[ph]=c;
            ph++;
        }
        smax[ph]='\0';
        ph++;

    }
    qsort(xxx,T,sizeof(hhh),cmp);
    for(int i3=0;i3<T;i3++){
        int i=0;
        while((xxx[i3].p[i])!='\0'){
            printf("%c",xxx[i3].p[i]);
            i++;
        }
        printf("@");
        i=0;
        while(xxx[i3].q[i]!='\0'){
            printf("%c",xxx[i3].q[i]);
            i++;
        }
        printf("\n");
    }
    free(xxx);
    return 0;
}
