#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char way[201];
	int m,n,i,j,result=0,k;
	int list[201][201]={};
	for(i=0;i<201;i++)way[i]='\0';
	scanf("%d%d",&m,&n);  //行数和列数
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)scanf("%d",&list[i][j]);  //输入矩阵 
	} 
	result=list[0][0];
	i=0;j=0;k=0;
	while(i<m && j<n){
		if(i==m-1 && j==n-1)break; 
		if(i+1<m && j+1<n){
			if(list[i][j+1]>list[i+1][j]){
				i++;way[k++]='D';  //向下走
			}
			else {
			    j++;way[k++]='R';  //向右走 
		    }
		}
		else if(i+1==m){  //不能向下 
			j++;way[k++]='R';
		}
		else if(j+1==n){
			i++;way[k++]='D'; 
		}
		result+=list[i][j];  //最短长度 
	}
	way[k]='\0';  //构成字符串 
	printf("%d\n%s",result,way);
	return 0;
}