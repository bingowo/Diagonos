#include <stdio.h>
void change(int n ,int r)
{   int i;
    if(n/r){change(n/r,r); printf("%c",i=n%r>9?n%r+'0':n%r+'A'-'0');  }
    printf("%c",i=n%r>9?n%r+'0':n%r+'A'-'0');
}
int main(){
    int N;
    int n,r,i;;
    scanf("%d",N);
    for (i=0;i<N;i++){
        scanf("%d %d",&n,&r);
        if (n<0){printf("-");n=-1*n;}
        change(n,r);
        printf("\n");
    }
}