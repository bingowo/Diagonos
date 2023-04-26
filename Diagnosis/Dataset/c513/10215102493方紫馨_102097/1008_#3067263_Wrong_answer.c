#include<stdio.h>
#include<math.h>
void binary(int a,char *s){
	int d=1;
	for(int i=0;i<32;i++){
		if(d&a==1){
			s[i]='1';
		}else{
			s[i]='0';
		}			
		a>>1;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		int x,y;
		scanf("%d%d",&x,&y);
		char ax[32],ay[32];
		binary(x,ax);
		binary(y,ay);
		int cnt=0;
		for(int i=0;i<32;i++){
			if(ax[i]!=ay[i])
				cnt++;
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}