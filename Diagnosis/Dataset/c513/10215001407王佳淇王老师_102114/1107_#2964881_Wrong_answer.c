#include<stdio.h>
int main(){
	int  T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		printf("case #%d:\n",i);
		int s[3][3],t[3][3]={0};
		for(int j=0;j<3;j++)
		for(int k=0;k<3;k++) scanf("%d",&s[j][k]);
		t[0][0]=s[0][0]+s[0][1]+s[1][0];
		t[0][1]=s[0][1]+s[0][2]+s[1][1]+s[0][0];
		t[0][2]=s[0][2]+s[0][1]+s[1][2];
		t[1][0]=s[0][0]+s[2][0]+s[1][0]+s[1][1];
		t[1][1]=s[1][1]+s[1][2]+s[1][0]+s[0][1]+s[2][1];
		t[1][2]=s[1][2]+s[1][1]+s[0][2]+s[2][2]; 
		t[2][0]=s[2][0]+s[2][1]+s[1][0];
		t[2][1]=s[2][1]+s[2][2]+s[2][0]+s[1][1];
		t[2][2]=s[2][2]+s[2][0]+s[1][2];
		for(int j=0;j<3;j++){
		for(int k=0;k<3;k++) {
		printf("%d ",(t[j][k]+1)%2);
         }printf("\n");}
	}
	
	
	
	
}