#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int w,h,d;
	char ch;
	int im[201][201];
	scanf("%d %d %d %c",&w,&h,&d,&ch);
	int d1;
	if(ch=='R') d1=d%360;
	if(ch=='L') d1=360-d%360;
	for(int x=0;x<h;x++)
	for(int y=0;y<w;y++) scanf("%d",&im[x][y]);
	//x列y行 
	if(d1==90) {
		printf("%d %d\n",h,w);
		for(int x=0;x<w;x++){
		for(int y=h-1;y>=0;y--){
			printf("%d",im[y][x]);
			if(y!=0) printf(" ");
			else printf("\n");
		}}}
	//
	if(d1==180) {
		printf("%d %d\n",w,h);
		for(int x=h-1;x>=0;x--){
		for(int y=w-1;y>=0;y--){
			printf("%d",im[x][y]);
			if(y!=0) printf(" ");
			else printf("\n");
		}}}
	///
	if(d1==270) {
		printf("%d %d\n",h,w);
		for(int x=w-1;x>=0;x--){
		for(int y=0;y<h;y++){
			printf("%d",im[y][x]);
			if(y!=h-1) printf(" ");
			else printf("\n");
		}}}
		///
		if(d1==0||d1==360){
				printf("%d %d\n",w,h);
		for(int x=0;x<h;x++){
		for(int y=0;y<w;y++) {
			printf("%d",im[x][y]);
			if(y!=w-1) printf(" ");
			else printf("\n");
		}}}
		
		
	return 0;
	
}