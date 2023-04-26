#include <stdio.h>
int main()
{
int T;
scanf("%d",&T);
char b[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
for(int i=0;i<T;i++)
{
int N,R;
scanf("%d%d",&N,&R);
int k=0,a[100];
if(N<0) {N=-N;}
do{
int r=N%R;
a[k++]=b[r];
N=N/R;
}while(N);
if(N<0) printf("-");
for(k=k-1;k>=0;k--) printf("%c",a[k]);
printf("\n");
}
return 0;
}

