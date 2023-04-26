#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[200][200];
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int num=a[0][0],d1=0,d2=0;
    char d[400]={0};
    int q=0;
    do{
        int x,y;
        x=a[d1][d2+1];
        y=a[d1+1][d2];
        if(x<=y){
            d2++;
            num+=x;
            d[q++]='R';
        }
        else{
            d1++;
            num+=y;
            d[q++]='D';
        }
    }while(d1<m-1&&d2<n-1);
    //num+=a[d1][d2];
    while(d1==m-1&&d2<n-1){
        d2++;
        num+=a[m-1][d2];
        d[q++]='R';
    }
    while(d1<m-1&&d2==n-1){
        d1++;
        num+=a[d1][n-1];
        d[q++]='D';
    }
    printf("%d\n",num);
    for(int i=0;i<q;i++){
        printf("%c",d[i]);
    }
    return 0;
}
