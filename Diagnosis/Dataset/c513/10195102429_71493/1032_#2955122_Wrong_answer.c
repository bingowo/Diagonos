#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int *s1,*s2;
    s1=(int *)a;
    s2=(int *)b;
    while(*s1!=-1&&*s2!=-1&&*s1==*s2) s1++,s2++;
    return *s2-*s1;
}

int main()
{

    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++){
            int data[1001][51];
            int n,j=0;
            scanf("%d",&n);
            for(int m=0;m<n;m++){
                    int j=0;
                    while(scanf("%d",&data[m][j])&&data[m][j]!=-1){
                            j++;}}
                    qsort(data,t,sizeof(data[0]),cmp);
            for(k=0; k<n; k++){
                    for(j=0; data[k][j+1]!=-1; j++)
                         printf("%d ",data[k][j]);
                    printf("%d\n",data[k][j]);
        }

    }
    return 0;
}
