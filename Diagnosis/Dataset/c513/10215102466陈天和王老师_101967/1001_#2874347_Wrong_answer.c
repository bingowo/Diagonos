#include <stdio.h>
#include <stdlib.h>
int f(int n,int r);
int main()
{
    int num;
    int j,m;
    int rec=100;
    scanf("%d",&num);

    int a[100][2];
    for(int i=0;i<num;i++){
        scanf("%d %d", &a[i][0],&a[i][1]);
    }
    //input
    for(int i=0;i<num;i++) {
        char str[100];
        for (j = 0; a[i][0] != 0; j++) {
            if(a[i][0]>0){rec=1;}
            if(a[i][0]<0){
                rec=0;
                a[i][0]=-a[i][0];
            }//process sgn


            if (a[i][0] % a[i][1] < 10) { str[j] = '0' + (a[i][0] % a[i][1]); }
            else { str[j] = 'A' + a[i][0] % a[i][1] - 10; }
            a[i][0] = a[i][0] / a[i][1];
        }

        if(rec==0){printf("-");}

        for(int k=j-1;k>=0;k--){
            printf("%c",str[k]);
        }
        printf("\n");
    }
    return 0;

}
