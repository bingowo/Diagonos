#include<stdio.h>
int main(){
	int a, n, m, x;
	scanf("%d %d %d %d", &a, &n, &m, &x);
	if(x<4){
		printf("%d", (x-1)*a);
	}
	else{//x>=4
		int a_t2[2] = {1, 1};//a+t,第3站上车人数
		int a_t1[2] = {0, 1};//t，第2站上车人数
		int total[2] = {2, 0};//2a,第3站出发时的人数
		int for_m[2]; 
		for(int i=4;i<n;i++){
			int temp[2];
			temp[0] = a_t2[0];
			temp[1] = a_t2[1];
			total[0] += a_t1[0];
			total[1] += a_t1[1];//第i站出发时车上的人数
			a_t2[0] += a_t1[0];
			a_t2[1] += a_t1[1];
			a_t1[0] = temp[0];
			a_t1[1] = temp[1];
			if(i==x){
				for_m[0] = total[0];
				for_m[1] = total[1];
			}
		}
		int t = (m-a*total[0])/total[1];
		//m = ？a+？t-->t=?
		printf("%d", for_m[0]*a+for_m[1]*t);
	}
	return 0;
}