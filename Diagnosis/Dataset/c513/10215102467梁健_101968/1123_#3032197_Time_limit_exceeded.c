#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct dna
{
    int time;
    char s[21];
}DNA;
int cmp(const void *a,const void *b){
    DNA* x=(DNA*)a;
    DNA* y=(DNA*)b;
    if(x->time!=y->time)return x->time>y->time?1:-1;
    else return strcmp(x->s,y->s);
}
int main()
{
    int n;scanf("%d",&n);
    DNA*a;
    a=(DNA*)malloc(sizeof(DNA)*n);
    scanf("%s",a[0].s);a[0].time=1;
    int p=1;
    for(int i=1;i<n;i++){
        char jud[21];scanf("%s",jud);
        int flag=1;
        for(int j=0;j<p;j++){
            if(strcmp(jud,a[j].s)==0){
                a[j].time++;
                flag=0;
                break;
            }
        }
        if(flag){
            strcpy(a[p].s,jud);
            a[p].time=1;
            p++;
        }
    }
    qsort(a,p,sizeof(DNA),cmp);
    for(int i=0;i<p;i++){
        printf("%s\n",a[i].s);
    }
    
    return 0;
}