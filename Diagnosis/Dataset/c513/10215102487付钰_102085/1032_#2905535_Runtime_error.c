#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void* a,const void* b)
{
    int *s1=*(int *)a;
    int *s2=*(int *)b;
    while(*s1!=-1&&*s2!=-1&&*s1==*s2) s1++,s2++;
    return *s2-*s1;
}
int main()
{
    int t,n ,j;
    scanf("%d\n",&t);
    while(t--){
        scanf("%d",&n);
        int a[1000][51];
        for(int i=0;i<n;i++){
            int j=0;
            while(scanf("%d",&a)&&a[i][j]!=-1) j++;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int k=0;k<n;k++){
            for(int j=0;a[k][j+1]!=-1;j++)
                printf("%d ",a[k][j]);
            printf("%d\n",a[k][j]);
        }
    }

}
