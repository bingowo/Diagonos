#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef long long int lli;
typedef struct{
    lli r;
    lli h;
    lli SuperficialAreal;
    lli Bcsearea;
    lli Literalarea;
}Cylinder;

int cmp(const void *a,const void *b)
{
    Cylinder *pa = (Cylinder *)a;
    Cylinder *pb = (Cylinder *)b;
    return pb->Literalarea>pa->Literalarea?1:-1;
}
int main(void)
{
    int n,m,Maxid;
    lli Maxarea  = 0,MaxSuperficialarea=0;
    scanf("%d %d",&n,&m);
    Cylinder input[n];
    for (int i=0; i<n; i++) {
        scanf("%lld %lld",&input[i].r,&input[i].h);
        input[i].Bcsearea = input[i].r*input[i].h;
        input[i].Literalarea = 2*input[i].r*input[i].h;
        input[i].SuperficialAreal = input[i].Bcsearea+input[i].Literalarea;
    }
    qsort(input, n, sizeof(Cylinder), cmp);
    for (int i=0; i<n; i++) {
        int choice = 1;
        lli area = input[i].SuperficialAreal;
        for (int j=0; j<n&&choice <m; j++) {
            if(i==j||input[j].r>input[i].r){
                continue;
            }
            area+=input[j].Literalarea;
            choice++;
        }
        if (choice==m) {
            Maxarea = area>Maxarea?area:Maxarea;
        }
    }
    Maxarea += MaxSuperficialarea;
    printf("%lld",Maxarea);
    return 0;
}
