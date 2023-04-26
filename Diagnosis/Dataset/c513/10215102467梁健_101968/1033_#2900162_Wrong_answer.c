#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char mon[19][10]={{"pop"},{"no"},{"zip"},{"zotz"},{"tzec"},{"xul"},{"yoxkin"},{"mol"},{"chen"},{"yax"},{"zac"},{"ceh"},{"mac"},{"kankin"},{"muan"},{"pax"},{"koyab"},{"cumhu"},{"uayet"}};
typedef struct date
{
    char day[3];
    char month[20];
    int year;
}DATE;
int cmp(const void *a,const void *b)
{
    DATE a1=*(DATE*)a;
    DATE b1=*(DATE*)b;
    int y1=a1.year,y2=b1.year;
    if(y1!=y2)return (y1>y2?1:-1);
    char d1[20],d2[20];
    strcpy(d1,a1.month);strcpy(d2,b1.month);
    int m1,m2,t1,t2;
    for(int z=0;z<19;z++)if(strcmp(d1,mon[z])==0)m1=z;
    for(int z=0;z<19;z++)if(strcmp(d2,mon[z])==0)m2=z;
    t1=atoi(a1.day);t2=atoi(b1.day);
    if(m1!=m2)return m1>m2?1:-1;
    if(t1!=t2)return t1>t2?1:-1;
    return 0;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    DATE *a=NULL;
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        scanf("%d",&n);
        a=(DATE*)malloc(sizeof(DATE)*n);
        for(int m=0;m<n;m++){
            scanf("%s %s %d",a[m].day,a[m].month,&a[m].year);
        }
        qsort(a,n,sizeof(DATE),cmp);
        for(int m=0;m<n;m++)printf("%s %s %d\n",a[m].day,a[m].month,a[m].year);
    }
    return 0;
}
