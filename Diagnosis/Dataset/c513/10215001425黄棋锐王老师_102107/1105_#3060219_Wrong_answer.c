#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() 
{	int IM[200][200]={0};
	int W,H;
	scanf("%d%d",&W,&H);
	int i,j;
	for(i=0;i<H;i++)
 {
	for(j=0;j<W;j++)
	scanf("%d",&IM[i][j]);
 }
 
 	for(i=1;i<H-1;i++)
 	{	for(j=1;j<W-1;j++)
 		{	int co=IM[i][j];
 			int b[8]={0};
 			b[0]=IM[i-1][j-1]>=co?1:0;
 			b[1]=IM[i-1][j]>=co?1:0;
 			b[2]=IM[i-1][j+1]>=co?1:0;
 			b[3]=IM[i][j-1]>=co?1:0;
 			b[4]=IM[i][j+1]>=co?1:0;
 			b[5]=IM[i+1][j-1]>=co?1:0;
 			b[6]=IM[i+1][j]>=co?1:0;
 			b[7]=IM[i+1][j+1]>=co?1:0;
 			int shift=0,k=0;
 			int min=255;//2^8-1
 			for(shift=0;shift<8;shift++)//二进制数依次左移 
 			{	int d=0;
 				for(k=0;k<8;k++) d=d*2+b[(k+shift)%8];//d为左移shift位后的十进制值
				 if(d<min) min=d; //取最小值 
			 }
 			printf("%d",min);
 			char c=(j==W-2)?'\n':' ';
 			putchar(c);
		 }
	}
    return 0;
}
