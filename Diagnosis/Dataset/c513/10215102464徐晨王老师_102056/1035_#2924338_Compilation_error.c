#include <stdio.h>
#include <string.h>
struct data{
   int R;
   int H;
   int sum;
};
int main(){
    int n,m;
    scsanf("%d%d",&n,&m);
    struct data p[1000];
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].R,&p[i].H);
    }
    qsort()
}