//1014
#include <stdio.h>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	long long int qm=a/b;
	long long int hm=a%b;
	int flag=0;
	if(hm==0) flag=1;
	int qmn[101],hmn[101];
	int lq=0,lh=0,i=0;
	//printf("%d %d\n",qm,hm);
	int carry=0;
	for(i=0;i<100;i++){
		qmn[i]=0;
		hmn[i]=0;
	}
	while(hm>0){
		hmn[lh]=hm%3+carry;
		hmn[lh]++;
		if(hmn[lh]>=3){
			hmn[lh]-=3;
			carry=1;
		}
		else{
			carry=0;
		}
		lh++;
		hm/=3;
	}
	//8 1: 8-3 022->133->210->10-1->102	
	while(qm>0){
		qmn[lq]=qm%3+carry;	
		//printf("\ntest:%d\n",qmn[lq]);
		qmn[lq]++;
		//printf("\ntest1:%d\n",qmn[lq]);		
		if(qmn[lq]>=3){
			qmn[lq]-=3;
			carry=1;
		}
		else{
			carry=0;
		}
		//printf("\ntest2:%d\n",qmn[lq]);
		lq++;
		qm/=3;
	}
	if(carry==1){
		qmn[lq]+=carry;
		qmn[lq]++;
		lq++;
	}
	//printf("%d\n",lq);
	//if(flag==1) lq++;
	for(i=lq-1;i>=0;i--){
		qmn[i]--;
		if(qmn[i]==-1) qmn[i]=2;
		printf("%d",qmn[i]);
	}
	if(flag==1) return 0;
	printf(".");
	for(i=lh-1;i>=0;i--){
		hmn[i]--;
		if(hmn[i]==-1) hmn[i]=2;
		printf("%d",hmn[i]);		
	}
	
} 