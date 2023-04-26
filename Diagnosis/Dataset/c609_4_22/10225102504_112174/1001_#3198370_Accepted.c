#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,k=1,i,j;
    scanf("%d\n",&n);
    int c[100][1000],d[100],e[100];
    for(i=0;i<n;i++){
        j=0;
        scanf("%d %d",&a,&b);
        if(a<0){
            a=-a;
            d[i]=1;}
        while(a!=0){
            k=a%b;
            a=a/b;
            c[i][j]=k;
            j++;
        }
        e[i]=j-1;
    }
    for(int m=0;m<n;m++){
        if(d[m]==1)
        printf("-");
        for(int l=e[m];l>=0;l--){

                if(c[m][l]<10)
                    printf("%d",c[m][l]);
                else
                    printf("%c",c[m][l]+55);
        }
        printf("\n");
        }
    return 0;
}
