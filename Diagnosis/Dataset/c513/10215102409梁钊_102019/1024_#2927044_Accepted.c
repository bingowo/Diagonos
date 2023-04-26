#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct csv
{
    char s[12] ;
    int scores ;
}csv ;

int cmp(const void* _a , const void* _b)
{
    csv* a = (csv*)_a ; csv* b = (csv*)_b ;
    if((*a).scores==(*b).scores) return strcmp((*a).s,(*b).s) > 0 ? 1 : -1 ;
    else return (*b).scores - (*a).scores > 0 ? 1 : -1 ;
}
int main()
{
    int t ;
    scanf("%d",&t) ;
    for(int i=0;i!=t;i++){
        int n,m,g;
        scanf("%d %d %d",&n,&m,&g) ;
        int sco[m] ;
        for(int j=0;j!=m;j++) scanf("%d",&sco[j]) ;
        csv csv[n] ;
        for(int j=0;j!=n;j++){
            scanf("%s",&csv[j].s) ;
            int num ;
            scanf("%d",&num) ;
            int scos = 0 ;
            for(int k=0;k!=num;k++){
                int tmp ; scanf("%d",&tmp) ;
                scos += sco[tmp-1] ;
            }
            csv[j].scores = scos ;
        }
        qsort(csv,n,sizeof(csv[0]),cmp);
        int count = 0 ;
        for(int j=0;j!=n;j++){
            if(csv[j].scores>=g) count++ ;
        }
        printf("case #%d:\n%d\n",i,count) ;
        for(int j=0;j!=count;j++)
            printf("%s %d\n",csv[j].s,csv[j].scores) ;
        
    }
}