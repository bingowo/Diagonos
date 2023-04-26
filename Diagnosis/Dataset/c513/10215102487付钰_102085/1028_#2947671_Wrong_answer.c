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
    int a[1000]={0},b[1000]={0},c[1000]={0},i=0;
    while(scanf("%d",&a[i])!=EOF) i++;

    if(p=='A'){
        qsort(a,i,sizeof(a[0]),cmpa);
    }
    else {
        qsort(a,i,sizeof(a[0]),cmpd);
    }
    int e=i,o=0,l=0;
    for(int k=0;k<i;k++)
    {
        if(a[k]==a[k+1]){
                b[o]=a[k];
                i--;
                o++;
            //a[k+1]=a[k+2];
            //e--;
        }
    }
    for(int u=0;u<e;u++){
        for(int r=0;r<o;r++){
            if(a[u]!=b[r])
            {c[l]=a[u];
                l++;
                }

        }
    }
    int j;
    for( j=0;j<l;j++){
        printf("%d ",c[j]);

    }
    printf("%d",c[j]);
}
