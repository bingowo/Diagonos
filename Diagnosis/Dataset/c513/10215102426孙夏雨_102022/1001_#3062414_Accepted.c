#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int N;
    int R;
} AAA;

void change(AAA* p1)
{
    char ans[100]={0};
    int i=0;
    if((p1->N)<0) printf("-");
    int n=abs(p1->N);
    int r=p1->R;
    int yu=0;
    if(r==10) {printf("%d\n",n);return ;}
    else {
        while(n>0){
            yu=n%r;
            n/=r;
            if(yu<10){
                ans[i]=yu+'0';
                i++;
            }
            else {
                ans[i]=yu-10+'A';
                i++;
            }
        }
        ans[i]=0;
        for(int j=i-1;j>=0;j--) printf("%c",ans[j]);
        printf("\n");
        return ;
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    AAA* p=(AAA* )malloc(T*sizeof(AAA));
    for(int i=0;i<T;i++){
        scanf("%d %d",&((p+i)->N),&((p+i)->R));
    }
    for(int j=0;j<T;j++){
        AAA* p1=p+j;
        change(p1);
    }
    free(p);
    return 0;
}
