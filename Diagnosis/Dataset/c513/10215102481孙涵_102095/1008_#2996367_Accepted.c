# include <stdio.h>
# include <stdlib.h>
# include <string.h>


int main(){
    int T;
    scanf("%d",&T);
    int count;
    for (count = 0; count < T; count++){
        int x,y;
        scanf("%d %d",&x,&y);
        int lengthOfX,lengthOfY;
        int *px;
        int *py;
        int basex[100] = {0};
	    int num1;
	    int pl1 = 0;
	    do{
	        num1 = x % 2;
	        x = (x-num1)/2;
	        basex[pl1]= num1;
	        pl1++;
	    }while(x > 0);
	    lengthOfX = pl1;
        int basey[100] = {0};
	    int num2;
	    int pl2 = 0;
	    do{
	        num2 = y % 2;
	        y = (y-num2)/2;
	        basey[pl2]= num2;
	        pl2++;
	    }while(y > 0);
	    lengthOfY = pl2;
        int bigLength = (lengthOfX > lengthOfY)? lengthOfX:lengthOfY;
        int smallLength = (lengthOfX > lengthOfY)? lengthOfY:lengthOfX;
        int i;
        int t = 0;//计算从第0到第smallLength-1位有多少个不一样的 
		for (i = 0; i < bigLength; i++){
			if(basex[i] != basey[i]){
				t++;	
			}
		} 
		printf("%d\n",t);
	}
}

