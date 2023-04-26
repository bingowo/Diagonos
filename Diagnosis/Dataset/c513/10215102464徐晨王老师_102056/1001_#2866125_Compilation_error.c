#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trans(int n,int r){
char a[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char b=a[n%r];
n=n/r;
while(n){
char c=a[n%r];
n=n/r;
strcat(c,b);
char b=c;
};
printf("%s\n",c);
}

int main()
{int T,N,R;
scanf("%d",&T);
for(int i=0;i<T;i++){
    scanf("%d%d",&N,&R);
    if(N<0)N=-N;
    trans(N,R,);
}

return 0;
}
