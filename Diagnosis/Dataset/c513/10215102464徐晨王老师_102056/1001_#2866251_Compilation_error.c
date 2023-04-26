#include <stdio.h>
#include <stdlib.h>

void trans(int n,int r){
char a[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char b[100];
int i=0;
while(n){
b[i++]=a[n%r];
n=n/r;}
for(i=i-1;i>=0;i--){
    printf("%c",b[i])
}
printf("\n");
}

int main()
{int T,N,R;
scanf("%d",&T);
for(int i=0;i<T;i++){
    scanf("%d%d",&N,&R);
    trans(N,R);
}

return 0;
}
