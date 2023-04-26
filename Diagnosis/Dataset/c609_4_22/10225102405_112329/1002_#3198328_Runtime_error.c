#include<stdio.h>
int main()
{
    int T,a[10],x,y,k,answer,an;
    int i,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",a[i]);
    }
    char s[T][100],L,M;
    for(i=0;i<T;i++){
        x=a[10];
        k=0;
        while(x!=0){
            x/=2;
            y=x%2;
            s[i][k]=y+'\0';
            k++;
        }
        for(j=0;j<k-1;k+=an-1){
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
