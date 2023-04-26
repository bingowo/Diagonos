#include <stdio.h>
#include <stdlib.h>
int cmpa(const void *a,const void *b)
{
    int *p1=(int *)a;
    int *p2=(int *)b;
    return *p1-*p2;
}
int cmpd(const void *a,const void *b)
{
    int *p1=(int *)a;
    int *p2=(int *)b;
    return *p2-*p1;
}
int main()
{
    char p;
    scanf("%c",&p);
    int a[1000]={0},i=0;
    while(scanf("%d",&a[i])!=EOF) i++;

    if(p=='A'){
        qsort(a,i,sizeof(a[0]),cmpa);
    }
    else {
        qsort(a,i,sizeof(a[0]),cmpd);
    }
    int e=i;
    for(int k=0;k<i;k++)
    {
        if(a[k]==a[k+1]){
            a[k]=a[k+1];
            
            e--;
        }
    }
    int j;
    for( j=0;j<i-1;j++){
        printf("%d ",a[j]);

    }
    printf("%d",a[j]);
}
