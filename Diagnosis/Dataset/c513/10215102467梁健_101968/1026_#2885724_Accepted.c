#include<stdio.h>
#include<string.h>
#include<math.h>
int comp1(const void *a,const void *b)
{
    int a1=*(int *)a,b1=*(int *)b;
    return (a1>b1)?1:-1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int s[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
        char c=getchar();
    }
    qsort(s,n,sizeof(int),comp1);
    int res=0;
    for(int m=0;m<n;m+=2){
        res=abs(s[m]-s[m+1])+res;
    }
    printf("%d",res);
    return 0;
}
