#include <stdio.h>

int a[200][200];
int b[200][200];

int main()
{
	int w,h,d;
	char c;
	scanf("%d %d %d %c",&w,&h,&d,&c);
	int i,j;
	for (i=0;i<h;i++){
		for (j=0;j<w;j++){
			scanf("%d",&a[i][j]);
		}
	}
	d=d%360;
	d=d/90;
	int k;
	for (k=0;k<d;k++){
		int h1,w1;
		h1=w;
		w1=h;
		for (i=0;i<h1;i++){
			for (j=0;j<w1;j++){
				if(c=='R'){
					b[i][j]=a[h-j-1][i];
				}
				else{
					b[i][j]=a[j][w-i-1];
				}
			}
		}
		h=h1;
		w=w1;
		for (i=0;i<h;i++){
			for (j=0;j<w;j++){
				a[i][j]=b[i][j];
			}
		}
	}
	printf("%d %d\n",w,h);
	for (i=0;i<h;i++){
		for(j=0;j<w;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}