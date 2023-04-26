#include <stdio.h>
#include <stdlib.h>

void trans(int n,int r,int pd){
char a[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char b[100];
int i=0;
if(pd==0){
    b[i]='-';
    i=i+1;
}
while(n){
b[i++]=a[n%r];
n=n/r;}
for(i=i-1;i>=0;i--){
    printf("%c",b[i]);
}
printf("\n");
}

int main()
{int T,N,R;
int pd=1;
scanf("%d",&T);
for(int i=0;i<T;i++){
    scanf("%d%d",&N,&R);
    if(N<0){
        N=-N；
        pd=0;
    }
    trans(N,R,pd);
}

return 0;
}
