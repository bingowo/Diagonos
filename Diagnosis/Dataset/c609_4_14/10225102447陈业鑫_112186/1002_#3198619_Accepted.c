#include<stdio.h>
int main(){
	int i, num, outp=0;
	scanf("%d",&num);
	int T[10];
	for(i=0;i<num;i++){
		scanf("%d",&T[i]);
	}
	int ret, ref, pd=0;
	for(i=0;i<num;){
		ret = T[i]%2;
		T[i] = T[i]/2;
		while(T[i]>0){
			ref = T[i]%2;
			T[i]=T[i]/2;
			if(ref!=ret){
				outp++;
				ret = ref;
			}
			else{
				if(outp>pd){
					pd = outp;
				}
				outp = 0;
			}
			if(outp>pd){
				pd = outp;
			}		
		}
		if(outp>pd){
			pd = outp;
		}
	pd++;			
	printf("case #%d:\n",i++);
	printf("%d\n",pd);
	pd = 0;
	outp = 0;
	}
	return 0;
}