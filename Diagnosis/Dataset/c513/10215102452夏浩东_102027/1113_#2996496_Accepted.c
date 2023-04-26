#include <stdio.h>
#include <stdlib.h>
int R[110][40];
int main()
{
    for(int i=0;i<110;i++){
        for(int j=0;j<40;j++) R[i][j]=0;
    }
    R[11][39]=1;
    int mm=0,nn=0;
    scanf("%d %d",&mm,&nn);
    for(int i=12;i<=9+nn;i++){
        for(int k=i-mm;k<i;k++){
            int left=0;
            for(int j=39;j>=0;j--){
            	int temp = R[i][j]+R[k][j]+left;
                 R[i][j]=temp%10;
                 left=temp/10;
            }
        }
    }
    if(nn==2) printf("1");
	else if(nn==1) printf("0");
	else{
		int zero=0;
	    while(R[9+nn][zero]==0) zero++;
	    for(int i=zero;i<40;i++) printf("%d",R[9+nn][i]);
	}
	return 0;
}