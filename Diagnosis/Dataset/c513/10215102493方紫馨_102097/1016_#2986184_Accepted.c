#include<stdio.h>
int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	int ret[100],p,t=0,idx=0;
	if(n==0){
		printf("0");
		return 0;
	}	
	while(n!=0){
		p = n%r;
		n /= r;
		if(p<0){
			p -= r;
			n ++;
		}
		if(p>=0&&p<=9){
			ret[idx++] = p+'0';
		}else{
			ret[idx++] = p-10 +'A';
		}
	}
	for(int i=idx-1;i>=0;i--)
		printf("%c",ret[i]);
	
	return 0;
}