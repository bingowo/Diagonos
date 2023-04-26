#include<stdio.h>
#include<string.h>
#include<math.h>
int comp1(const void *a,const void *b)
{
    unsigned long long a1=*(unsigned long long *)a,b1=*(unsigned long long *)b;
    return (a1>b1)?1:-1;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    unsigned long long s[n];
    for(int i=0;i<n;i++){
        scanf("%llu",&s[i]);
    }
    qsort(s,n,sizeof(unsigned long long),comp1);
    unsigned long long R=0;
    unsigned long long minus[n-1];
    for(int i=0;i<n;i++){
        minus[i]=s[n]-s[i];
    }
    qsort(minus,n-1,sizeof(unsigned long long),comp1);
    for(int i=0;i<m;i++){
        R=R+minus[i];
    }
    printf("%llu",R);
    return 0;
}
