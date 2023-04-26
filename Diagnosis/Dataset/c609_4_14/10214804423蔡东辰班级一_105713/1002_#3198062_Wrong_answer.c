#include <stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
	    int cnt = 1;//
	    int tempcnt = 0;
		int n, before, after;
		scanf("%d", &n);
		int m = 1;//初始移动
		while(n>>m != 0){
			before = (n>>(m-1))&1;
			after = (n>>m)&1;
			if(before!=after){
				cnt = (cnt==0)?2 : ++cnt;
				tempcnt = (cnt>=tempcnt)? cnt:tempcnt;
			}
			else{
				tempcnt = (cnt>tempcnt)? cnt:tempcnt;
				cnt = (cnt==0)?0:--cnt;
			}
			m++;
		}
		printf("case #%d:\n%d\n", i, tempcnt);
	}

	return 0;
	
}