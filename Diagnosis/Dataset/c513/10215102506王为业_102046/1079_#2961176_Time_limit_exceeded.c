//dsum\1075.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*

*/
//#define LOCAL
#define int long long

#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;
int cmp(int*x,int*y)
{
    return *x>*y?1:-1;
}
int arr[1010];
int nans[1010*505];
int anslen=0;
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        anslen=0;
        printf("case #%d:\n",iT);
        int n,m;
        scanf("%d %d",&n,&m);
        for(int in=0;in<n;++in){
            scanf("%d",&arr[in]);
        }
        for(int alen=1;alen<=n;++alen){
            int temsum=0;
            for(int i=0;i<alen;++i){
                temsum+=arr[i];
            }//get sum of section
            nans[anslen++]=temsum;
            int be=0,af=alen;//af points to the next one
            while(af!=n){//when af hasn't been beyond the section
                temsum-=arr[be];
                temsum+=arr[af];
                nans[anslen++]=temsum;
                ++be,++af;
            }
        }
        qsort(nans,anslen,sizeof(nans[0]),cmp);

        for(int i=1;i<anslen;++i){
            nans[i]+=nans[i-1];
        }//make sum array;
        int L,U;
        for(int im=0;im<m;++im){//receive operation
            scanf("%d %d",&L,&U);
            printf("%d\n",L==1?nans[U-1]:nans[U-1]-nans[L-2]);
        }
    }
}
