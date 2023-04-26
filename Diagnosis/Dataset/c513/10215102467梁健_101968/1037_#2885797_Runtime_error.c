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
    long n,m;
    scanf("%l %l",&n,&m);
    unsigned long long s[n];
    for(int i=0;i<n;i++){
        scanf("%llu",&s[i]);
    }
    qsort(s,n,sizeof(unsigned long long),comp1);
    unsigned long long res[m];
    for(int i=0;i<m;i++){
        res[i]=s[i];
    }
    unsigned long long R=0;
    for(int i=m-2;i>-1;i--){
        R=R+(res[m-1]-res[i]);
    }
    unsigned long long p[m];
    for(int i=0;i<m;i++){
        p[i]=s[n-1-i];
    }
    unsigned long long R1=0;
    for(int i=0;i<m;i++){
        R1=R1+(p[0]-p[i]);
    }
    if(R1<R)R=R1;
    printf("%llu",R);
    return 0;
}
