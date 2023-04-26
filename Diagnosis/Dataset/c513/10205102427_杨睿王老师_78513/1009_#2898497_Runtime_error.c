//1009
#include <stdio.h>
#include <math.h>
int GCD(int a,int b){
	return b == 0 ? a:GCD(b,a%b);
}
int main(){
	int i,T;
	scanf("%d",&T);
	char ch=getchar();
	for(i=0;i<T;i++){
		char s[121];
		int l=0;
		while((ch=getchar())!='\n'){
			s[l]=ch;
			l++;
		}
		int j,w=0,q=0,cnt=0,len=0;
		for(j=0;j<l;j++){
			int b[100];
			b[0]=0;
			int tmp=(int)s[j];
			//printf("%d/",tmp);
			while(tmp>0){
				b[q]=tmp%2;
				if(b[q]==1) cnt++;
				tmp/=2;
				q++;
			}
			b[q]=0;
			q++;
			/*for(int y=0;y<q;y++){
				printf(";%d ", b[y]);
			}
			//printf("\nq:%d\n",q);

			//w=w+q;
			//printf("\nw:%d\n",w);*/
			q=0;
		}
		int gcd=GCD(cnt,w);
		w=l*8;
		//printf("\n%d %d",cnt,w);
		printf("%d/%d\n",cnt/gcd,w/gcd);
	}
}