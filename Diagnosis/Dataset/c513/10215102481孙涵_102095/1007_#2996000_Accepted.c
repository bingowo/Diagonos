# include <stdio.h>
# include <stdlib.h>
# include <string.h>


int main(){
    int T;
    scanf("%d",&T);
    int count;
    for (count = 0; count < T; count++){
    	printf("case #%d:\n",count);
        int N;
        int len;
        scanf("%d",&N);
	    int baseR[100] = {0};
	    int num;
	    int pl = 0;
	    do{
	        num = N % 2;
	        N = (N-num)/2;
	        baseR[pl]= num;
	        pl++;
	    }while(N > 0); 
	    int length;
	    length = pl;
		int i;
	    for (i = 0; i < (len/2); i++){
	    	int temp = baseR[i];
	    	baseR[i] = baseR[ (length)-1-i ];
	    	baseR[ (length)-1-i ] = temp;
		}
		
		int k, j;
		int count = 1;
		int max = 1;
		for (k = 0; k < (length); k++){
			for (j = k; j < (length) - 1; j++){
				if (baseR[j] != (baseR[j+1])){
					count++;
					if (count > max){
						max = count;
					}
				}
				else{
					break;
				}
			}
			count = 1;
		}       
        printf("%d\n",max);
    }
    return 0;
}
