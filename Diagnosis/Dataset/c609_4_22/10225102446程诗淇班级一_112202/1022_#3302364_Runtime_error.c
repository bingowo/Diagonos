#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    char p[1000];
    char q[1000];
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
    hhh* xxx;
    xxx=(hhh*)malloc(T*sizeof(hhh));
    for(int i=0;i<T;i++){
        char t[1000];
        scanf("%s",t);
        int c;
        int k=0;
        int g=0;
        c=strlen(t);
        for(int j=0;j<c;j++){
            if(t[j]!='@'){
                xxx[i].p[g]=t[j];
                g++;
                continue;
            }

            if(t[j]=='@'){
                while(t[j+1]!='\0'){
                    xxx[i].q[k]=t[j+1];
                    j++;
                    k++;
                }
                break;
            }

        }
        xxx[i].a1=g;
        xxx[i].a2=k;


    }
    qsort(xxx,T,sizeof(hhh),cmp);
    for(int i3=0;i3<T;i3++){
        for(int i1=0;i1<xxx[i3].a1;i1++){
            printf("%c",xxx[i3].p[i1]);
        }
        printf("@");
        for(int i2=0;i2<xxx[i3].a2;i2++){
            printf("%c",xxx[i3].q[i2]);
        }
        printf("\n");


    }

    return 0;
}
