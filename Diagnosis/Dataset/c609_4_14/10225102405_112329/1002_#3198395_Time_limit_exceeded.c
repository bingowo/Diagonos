#include<stdio.h>
int main()
{
    int T,a[10],x,y,k,answer,an,s[T][100];
    int i,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<T;i++){
        x=a[10];
        k=0;
        while(x!=0){
            x/=2;
            y=x%2;
            s[i][k]=y;
            k++;
        }
        for(j=0;j<k-2;k++){
            an=1;
            answer=1;
            while(s[i][j+an]!=s[i][j+an-1]){
                an++;
            }
            if (an>answer) {answer=an;}
        }
        printf("case #%d;\n%d",i,answer);
    }

}
