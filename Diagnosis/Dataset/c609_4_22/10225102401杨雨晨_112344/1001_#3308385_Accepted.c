#include <stdio.h>
int divide(int n,int r){return n%r>9?n%r+'A'-10:n%r+'0';}
void change(int n ,int r)
{   int i;
    if(n/r){change(n/r,r);printf("%c",divide(n,r));}
    else printf("%c",divide(n,r));
}
int main(){
    int N;
    int n,r,i;;
    scanf("%d",&N);
    for (i=0;i<N;i++){
        scanf("%d%d",&n,&r);
        if (n<0){printf("-");n=-1*n;}
        change(n,r);
        printf("\n");
    }
  
}