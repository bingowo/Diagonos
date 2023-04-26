#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char month[19][10]={{"pop"},{"no"},{"zip"},{"zotz"},{"tzec"},{"xul"},{"yoxkin"},{"mol"},{"chen"},{"yax"},{"zac"},{"ceh"},{"mac"},{"kankin"},{"muan"},{"pax"},{"koyab"},{"cumhu"},{"uayet"}};
typedef struct date
{
    char date[20];
    int year;
}DATE;
int cmp(const void *a,const void *b)
{
    DATE a1=*(DATE*)a;
    DATE b1=*(DATE*)b;
    int y1=a1.year,y2=b1.year;
    if(y1!=y2)return (y1>y2?1:-1);
    char d1[20],d2[20];
    strcpy(d1,a1.date);strcpy(d2,b1.date);
    int t1,t2,dp1,dp2,month1,month2;
    char ti1[3],ti2[3],m1[10],m2[10];
    for(int z=0;z<strlen(d1);z++)if(d1[z]=='.')dp1=z+1;
    for(int z=0;z<strlen(d2);z++)if(d2[z]=='.')dp2=z+1;
    for(int z=0;z<dp1;z++)ti1[z]=d1[z];
    for(int z=0;z<dp2;z++)ti2[z]=d2[z];
    t1=atoi(ti1);t2=atoi(ti2);
    for(int z=dp1;z<strlen(d1);z++)m1[z]=d1[z];
    for(int z=dp2;z<strlen(d2);z++)m2[z]=d2[z];
    int j1=-2,j2=-2;
    for(int z=0;z<19;z++){
        j1=strcmp(m1,month[z]);
        if(j1==0)month1=z;
    }
    for(int z=0;z<19;z++){
        j2=strcmp(m2,month[z]);
        if(j2==0)month2=z;
    }
    if(month1!=month2)return month1>month2?1:-1;
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
            scanf("%s %d",a[m].date,&a[m].year);
        }
        qsort(a,n,sizeof(DATE),cmp);
        for(int m=0;m<n;m++)printf("%s %d\n",a[m].date,a[m].year);
    }
    return 0;
}
