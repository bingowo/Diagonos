#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a,const void *b)
{
    int* _a=(int*)a;
    int* _b=(int*)b;
    return *_a>*_b;
}

int cmp2(const void *a,const void *b)
{
    int* _a=(int*)a;
    int* _b=(int*)b;
    return *_a<*_b;
}

int main()
{
    int a[100],i=0,j,b[100],sz;
    char s;
    scanf("%c",&s);
    while(scanf("%d",&a[i])!=EOF){
        i++;
    }
    sz=sizeof(a)/sizeof(a[0]);
    if (s=='A'){
        qsort(a,i,sizeof(a[0]),cmp1);
    }
    else if(s=='D'){
        qsort(a,i,sizeof(a[0]),cmp2);
    }
    for(j=0;j<i;j++){
        if(a[j]!=a[j+1]) {printf("%d ",a[j]);}
    }

}
