#include<stdio.h>
int main(){
	int width,height,radio;
	char direction;
	scanf("%d %d %d %c",&width,&height,&radio,&direction);
	int a[height][width];
	int i,j;
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int rad=radio%360;
	if(direction=='L') rad=360-rad;
	if(rad==0||rad==360){
		printf("%d %d\n",width,height);
		for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	}
	else if(rad==90){
		printf("%d %d\n",height,width);
		for(i=0;i<width;i++){
			for(j=0;j<height;j++){
				printf("%d ",a[height-1-j][i]);
			}
			printf("\n");
		}
	}
	else if(rad==180){
		printf("%d %d\n",width,height);
		for(i=0;i<height;i++){
			for(j=0;j<width;j++){
				printf("%d ",a[height-1-i][width-1-j]);
			}
			printf("\n");
		}
	}
	else{
		printf("%d %d\n",height,width);
		for(i=0;i<width;i++){
			for(j=0;j<height;j++){
				printf("%d ",a[j][width-1-i]);
			}
			printf("\n");
		}
	}
}