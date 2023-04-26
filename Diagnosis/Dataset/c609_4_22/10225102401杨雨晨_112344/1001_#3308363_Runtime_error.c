#include <stdio.h>
void change(int n ,int r)
{
    if(n/r){change(n/r,r); printf("%c",n%r>9?n%r+'0':n%r+'A'-'0');  }
    printf("%c",n%r>9?n%r+'0':n%r+'A'-'0');
}
int main(){
    int N;
    int n,r;
    scanf("%d",N);
    while(N>0){
        change(n,r);N--;
    }
}