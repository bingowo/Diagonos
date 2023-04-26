#include<stdio.h>
int main()
{
    int T,a[10],x,y,k,answer,an,s[10][100];
    int i,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<T;i++){
        x=a[i];
        k=0;
        while(x!=0){
            y=x%2;
            x/=2;
            s[i][k]=y;
            k++;
        }
        answer=1;
        for(j=0;j<k-1;j++){
            an=1;
            if(s[i][j]==s[i][j+1]){an=1;}
            else {while(s[i][j+an]!=s[i][j+an-1]&&(j+an<=k-1)){
                          an++;
                      }
                  if (an>answer) {answer=an;}
                  }
        }
        printf("case #%d:\n%d\n",i,answer);

     }
    return 0;
}
