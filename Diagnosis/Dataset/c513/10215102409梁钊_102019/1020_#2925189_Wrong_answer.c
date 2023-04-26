#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct file
{
    long time_c ;
    char month[10] ;
    char time[5] ;
    int sto ;
    char name[63] ;
}file;

int ncmp(const void* _a , const void* _b)
{
    file* a = (file*)_a ; file* b = (file*)_b ;
    return strcmp((*a).name,(*b).name) > 0 ? 1 : -1 ;
}

int scmp(const void* _a , const void* _b)
{
    file* a = (file*)_a ; file* b = (file*)_b ;
    return (*a).sto - (*b).sto > 0 ? 1 : -1 ;
}

int tcmp(const void* _a , const void* _b)
{
    file* a = (file*)_a ; file* b = (file*)_b ;
    return (*a).time_c - (*b).time_c > 0 ? 1 : -1 ;
}

int main()
{
    int n ;
    while( scanf("%d",&n) != EOF && n != 0 ){
        file files[n];
        for(int i=0;i<n;i++){
            scanf("%s %s",&files[i].month,&files[i].time) ;
            scanf("%d",&files[i].sto) ;
            scanf("%s",&files[i].name) ;
            long t = 0 , dig = 12 ;
            for(int j=2;j<=10;j++){
                if(files[i].month[j]>='0' && files[i].month[j]<='9'){
                    t = t + pow(11,dig) * ( files[i].month[j] - '0' ) ;
                    dig -- ;
                }
            }
            dig = 4 ;
            for(int j=0;j<=5;j++){
                if(files[i].time[j]>='0' && files[i].time[j]<='9'){
                    t = t + pow(11,dig) * ( files[i].time[j] - '0' ) ;
                    dig -- ;
                }
            }
            files[i].time_c = t ;
        }
        char field1[5] ,field[5] ;
        scanf("%s",&field1);
        scanf("%s",&field);
        if(field[1]=='N') qsort(files,n,sizeof(files[0]),ncmp) ;
        else if(field[1]=='S') qsort(files,n,sizeof(files[0]),scmp) ;
        else qsort(files,n,sizeof(files[0]),tcmp) ;
        for(int j=0;j!=n;j++){
            for(int k=0;k!=10;k++){
                printf("%c",files[j].month[k]) ;
            }
            printf(" %s %16d %s\n",files[j].time,files[j].sto,files[j].name) ;
        }
        printf("\n") ;
    }
}