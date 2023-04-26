#include <stdio.h>
#include <stdlib.h>

void trans(int n,int r){
char a[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
while(n){
printf("%c",a[n%r]);
n=n/r;}
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
