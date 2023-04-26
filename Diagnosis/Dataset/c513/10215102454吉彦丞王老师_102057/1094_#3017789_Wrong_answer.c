#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
	char s[120];
	int l;
};
int cmp(const void *pa,const void *pb){
	struct data a,b;
	a=*((struct data *)pa);
	b=*((struct data *)pb);
	if(a.l==b.l){
		return strcmp(b.s,a.s);
	}
	else{
		return b.l-a.l;
	}
}
int main(){
	int number;
	scanf("%d",&number);
	struct data p[number];
	int n=0;
	for(int i=0;i<number;i++){
		scanf("%s",p[i].s);
		p[i].l=strlen(p[i].s);
		if(p[i].s[0]=='-'){
			n++;
		}
	}
	if(n==0){
		qsort(p,number,sizeof(p[0]),cmp);
		int a1[p[0].l];
		int a2[p[0].l];
		for(int i=0;i<p[0].l;i++){
			a1[i]=0;
			a2[i]=0;
		}
		for(int i=p[0].l-1;i>=0;i--){
			a1[i]=p[0].s[i]-'0';
		}
		for(int i=p[0].l-1;i>=p[0].l-p[number-1].l;i--){
			a2[i]=p[number-1].s[i-p[0].l+p[number-1].l]-'0';
		}
		for(int i=p[0].l-1;i>=0;i--){
			a1[i]=a1[i]-a2[i];
			if(a1[i]<0){
				a1[i]+=10;
				a1[i-1]--;
			}
		}
		int t=0;
		for(int i=0;i<p[0].l;i++){
			if(a1[i]==0){
				t++;
			}
			else{
				break;
			}
		}
		for(int i=t;i<p[0].l;i++){
			printf("%d",a1[i]);
		}
		printf("\n");
	}
	else if(n==number){
		qsort(p,number,sizeof(p[0]),cmp);
	}
	else{
		struct data x[n];
		struct data y[number-n];
		int num1=0;
		int num2=0;
		for(int i=0;i<number;i++){
			if(p[i].s[0]=='-'){
				x[num1]=p[i];
				num1++;
			}
			else{
				y[num2]=p[i];
				num2++;
			}
		}
	}

}