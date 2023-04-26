#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int size;
    int ws;
    char name[64];
    char dt[18];
} wj;

int cmpn(const void* a,const void* b)
{
    wj* a0=(wj*)a;
    wj* b0=(wj*)b;
    return strcmp(a0->name,b0->name);
}
int cmps(const void* a,const void* b)
{
    wj* a0=(wj*)a;
    wj* b0=(wj*)b;
    if(a0->size!=b0->size)
        return a0->size-b0->size;
    return strcmp(a0->name,b0->name);
}
int cmpt(const void* a,const void* b)
{
    wj* a0=(wj*)a;
    wj* b0=(wj*)b;
    if(strcmp(a0->dt,b0->dt)!=0)
        return strcmp(a0->dt,b0->dt);
    return strcmp(a0->name,b0->name);
}

int main() {
    wj x[100];
    int n,i,j,l,k;
    char s[1000];
    char s0[10];
    scanf("%d\n",&n);
    while (n!=0){
        for(i=0;i<n;i++){
            x[i].size=0;
            x[i].ws=0;
            for(j=0;j<18;j++)
                x[i].dt[j]=0;
            for(j=0;j<64;j++)
                x[i].name[j]=0;
        }
        for(i=0;i<n;i++){
            gets(s);
            l=strlen(s);
            for(j=0;j<17;j++)
                x[i].dt[j]=s[j];
            while(s[j+1]==' ')
                j++;
            for(j++;s[j]!=' ';j++){
                x[i].ws++;
                x[i].size=x[i].size*10+s[j]-'0';
            }
            k=0;
            for(j++;j<l;j++){
                x[i].name[k]=s[j];
                k++;
            }
        }
        gets(s0);
        if(s0[6]=='N')
            qsort(x,n,sizeof(x[0]),cmpn);
        else if(s0[6]=='S')
            qsort(x,n,sizeof(x[0]),cmps);
        else
            qsort(x,n,sizeof(x[0]),cmpt);
        for(i=0;i<n;i++){
            printf("%s",x[i].dt);
            for(j=0;j<16-x[i].ws;j++)
                printf(" ");
            printf("%d %s\n",x[i].size,x[i].name);
        }
        scanf("%d",&n);
    }
    return 0;
}
