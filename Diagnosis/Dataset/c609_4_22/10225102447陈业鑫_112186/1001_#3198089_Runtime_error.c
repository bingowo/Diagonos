#include<stdio.h>
int main(){
    int num;
    int ifu = 0;
    scanf("%d",&num);
    int N[10], R[10];
    for(int i=0;i<num;i++){
        scanf("%d %d",&N[i],&R[i]);        
    }
     for(int i=0;i<num;i++){
     	char ret[10]={'\0',};
	 	int to = 0;
	 	int j = 0;
	 	if(N[i]<0){
		 	ifu = 1;
		 	N[i] = - N[i];
		 }
	 	while(N[i]>0){
	 	to = N[i]%R[i];
	 	N[i] = N[i]/R[i];
	 	switch(to){
		 	case 0:case 1:case 2:case 3:case 4:
			case 5:case 6:case 7:case 8:case 9:
				ret[j] = '0'+ to;
				break;
			case 10:case 11:case 12:case 13:
			case 14:case 15:case 16:case 17:
			case 18:case 19:case 20:case 21:
			case 22:case 23:case 24:case 25:
			case 26:case 27:case 28:case 29:
			case 30:case 31:case 32:case 33:
			case 34:case 35:case 36:
				ret[j] = 'A' + to - 10;
				break;
		}
		j++;
	 	}
	 	if(ifu==1){
		 	printf("-");
		 	ifu = 0;
		 }
		 for(int k=j-1;k>-1;k--){
		 printf("%c",ret[k]);
		 }
		 printf("\n");
	}
    return 0;
}