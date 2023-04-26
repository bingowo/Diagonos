#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int llu;

typedef struct{
    llu R;
    llu H;
    llu sideS;
    llu topS;
}CD;

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    CD cds1[n],cds2[n];
    for(int i=0;i<n;i++){
        scanf("%llu%llu",&cds1[i].R,&cds1[i].H);
        cds2[i].R=cds1[i].R;
        cds2[i].H=cds2[i].H;
    }
    llu totalS=0;
    printf("%llu",totalS);


}




