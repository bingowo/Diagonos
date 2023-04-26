#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas-->0){
        int n,p,m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        if((m+p-t)%2 != 0 || (t-p+m)%2 != 0 || m+p-t <0||t-p+m < 0) {printf("0");printf("\n");}
        else{int ml = (m+p-t)/2;
        int mr = (t-p+m)/2;
        //printf("%d\n",ml);
        //printf("%d\n",mr);
        int mp = m,mlp = ml;
        int A = 1,B = 1;
        while(mp>= m-ml +1){
            A *= mp;
            mp--;
        }
        while(mlp<=ml){
            B*=mlp;
            mlp++;
        }
        //printf("%d %d",A,B);
        double num = A/B;
        num = (double)num + 2.0 - pow(2.0,(double)mr-n+t) - pow(2.0,(double)ml-t+1);
        printf("%0.f",num);
        printf("\n");}
    }
    return 0;
}
