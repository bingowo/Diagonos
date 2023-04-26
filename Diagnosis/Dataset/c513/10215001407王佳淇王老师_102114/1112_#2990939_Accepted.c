#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	for(int v=0;v<T;v++){
	int a;
	scanf("%d",&a);
	int ans=0;
	if(a==0) printf("1");
	if(a==1) printf("1");
	if(a==2) printf("2");
	if(a==3) printf("2");
	if(a>=4){
	for(int w=0;w<=a/4;w++){
		for(int x=0;x<=(a-w*4)/3;x++){
		   for(int y=0;y<=(a-w*4-x*3)/2;y++)
		   ans++;
		}
	}
	printf("%d\n",ans);	}
	}
	return 0;
}