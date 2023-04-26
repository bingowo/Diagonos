#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *mayamonth[19]={"pop", "no","zip", "zotz", "tzec", 
"xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", 
"mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};

typedef struct
{
    int day , month , year ;
    char mon[6] ;
} maya ;

int cmp(const void *_a , const void *_b)
{
    maya* a = (maya*)_a ; maya* b = (maya*)_b ;
    if((*a).year != (*b).year)
        return (*a).year > (*b).year ;
    else if((*a).month != (*b).month)
        return (*a).month > (*b).month ;
    else
        return (*a).day > (*b).day ;
}

int get_month(char* mon)
{
    int i;
    for(i=0;i<19;i++)
    {
        if(strcmp(mon,mayamonth[i])==0)
            break;
    }
    return i+1;
}

int main()
{
    int t , n ;
    int time = 0 ;
    maya* a ;
    scanf("%d",&t) ;
    while(t--){
        int n = 0 ;
        scanf("%d",&n) ;
        a = (maya*)malloc(n*sizeof(maya)) ;
        for(int i=0; i<n; i++){
            scanf("%d",&a[i].day) ;
            getchar() ; getchar() ;
            scanf("%s",&a[i].mon) ;
            a[i].month = get_month(a[i].mon) ;
            scanf("%d",&a[i].year) ;
        }
        qsort(a,n,sizeof(maya),cmp) ;
        printf("case #%d:\n",time++) ;
        for(int i=0; i<n; i++){
            printf("%d. %s %d\n",a[i].day,a[i].mon,a[i].year) ;
        }
    }
}