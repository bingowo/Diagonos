# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int* baseconvertion(int N,int *length);

int main(){
    int T;
    scanf("%d",&T);
    int count;
    for (count = 0; count < T; count++){
        int x,y;
        scanf("%d%d",&x,&y);
        int lengthOfX,lengthOfY;
        int *px;
        int *py;
        px = baseconvertion(x,&lengthOfX);
        py = baseconvertion(y,&lengthOfY);
        int length = (lengthOfX > lengthOfY)? lengthOfX:lengthOfY;
    return 0;
}

int* baseconvertion(int N,int *length){
    int baseR[100] = {0};
    int num;
    int pl = 0;
    int *p;
	p = baseR;
    do{
        num = N % 2;
        N = (N-num)/2;
        baseR[pl]= num;
        pl++;
    }while(N > 0);
    *length = pl;
    int i;
	return p;
}
