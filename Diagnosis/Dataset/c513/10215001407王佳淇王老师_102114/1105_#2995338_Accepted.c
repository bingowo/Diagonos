#include<stdio.h>
int main(){
	int w,h;
	scanf("%d %d",&w,&h);
	int Image[100][100];
	int out[100][100]={0};
	for(int i=0;i<h;i++)
	for(int j=0;j<w;j++) scanf("%d",&Image[i][j]);
	for(int row=1;row<=h-2;row++){
		for(int col=1;col<=w-2;col++){
			int b[8]={0};
        int thres = Image[row][col];
        b[0] = Image[row-1][col-1]>=thres?1:0;
        b[1] = Image[row-1][col]>=thres?1:0;
		b[2] = Image[row-1][col+1]>=thres?1:0;
        b[3] = Image[row][col+1]>=thres?1:0;
        b[4] = Image[row+1][col+1]>=thres?1:0;
        b[5] = Image[row+1][col]>=thres?1:0;
        b[6] = Image[row+1][col-1]>=thres?1:0;
        b[7] = Image[row][col-1]>=thres?1:0;	
		int min_val = 255;
        int d;
     for(int shift = 0;shift<=7;shift++) //左移shift
    {
        d = 0;
        for(int i=0;i<8;i++)
            d = d*2+b[(i+shift)%8];
        if(d<min_val)
            min_val = d;
    }
	out[row][col]=min_val;				
}
}
for(int x=1;x<=h-2;x++){
		for(int y=1;y<=w-2;y++) {
		printf("%d",out[x][y]);
		printf(" ");}
		printf("\n");
		}
return 0;}
