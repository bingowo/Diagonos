#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,k=1,c[100][100],j=0,i;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        while(a!=0){
            k=a%b;
            a=a/b;
            c[i][j]=k;
            j++;
        }
    }
    for(int m=0;m<i;m++){
        for(int l=j-2;l>=0;l--){
            if(c[m][l]!=0){
                if(c[m][l]<10)
                    printf("%d",c[m][l]);
                else
                    printf("%c",c[m][l]+55);}
        }
        printf("\n");
        }
    return 0;
}
