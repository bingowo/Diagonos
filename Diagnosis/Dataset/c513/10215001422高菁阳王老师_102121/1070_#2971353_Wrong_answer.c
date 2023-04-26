#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,a[100],b[100],m;
	
	a[1]=b[1]=1;
	a[2]=b[2]=2;
	a[3]=4;
	b[3]=3;

	for(i=4;i<21;i++){
			a[i]=a[i-1]+b[i-1];
			b[i]=b[i-1]+a[i-1]-b[i-2];
		}
	while(scanf("%d",&m)&&m!=-1)
	printf("%d\n",a[m-1]+b[m-1]);
	return 0;
}