//math\1077.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*

*/
//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

int Aweight[1050];
int Barr[550];
int Bend[550];

int arrcmp(int *x,int *y)
{
    return Aweight[*x]<Aweight[*y]?1:-1;
}
int endcmp(int *x,int *y)
{
    return *x>*y?1:-1;
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int lena;
    scanf("%d",&lena);
    int temin;
    int nowAw=9999999;
    for(int ia=0;ia<lena;++ia){
        scanf("%d",&temin);
        Aweight[temin]=nowAw--;
    }
    int lenb;
    int Bendsize=0;
    int Barrsize=0;
    scanf("%d",&lenb);
    for(int ib=0;ib<lenb;++ib){
        scanf("%d",&temin);
        if(Aweight[temin]==0){
            Bend[Bendsize++]=temin;
        }else{
            Barr[Barrsize++]=temin;
        }
    }
    qsort(Barr,Barrsize,sizeof(Barr[0]),arrcmp);
    qsort(Bend,Bendsize,sizeof(Bend[0]),endcmp);
    for(int i=0;i<Barrsize;++i)
        printf("%d ",Barr[i]);
    for(int i=0;i<Bendsize;++i){
        printf("%d ",Bend[i]);
    }
}
