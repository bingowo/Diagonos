#include <stdio.h>
#define digit 100
typedef struct bigint{
	int cnt;
	int num[digit];          //个位在num[0]
}bigint;
//减法
void bigint_subtraction(bigint* a,bigint* b,bigint* c){   //a-b=c并且a>b 
	int i;
	for(i=0;i<a->cnt||i<b->cnt;i++){
		if(a->num[i]>=b->num[i]){
			c->num[i]=a->num[i]-b->num[i];
		}else{
			while(a->num[i]<b->num[i]){
				a->num[i+1]-=1;
				a->num[i]+=10;
			}
			c->num[i]=a->num[i]-b->num[i];
		}
	}
	c->cnt=a->cnt>b->cnt?a->cnt:b->cnt;
	for(i=c->cnt-1;i>=0&&c->num[i]==0;i--);
	c->cnt=i+1;
}
void stringtointarray(char a[],bigint* b){
	int i,j,k=0;
	for(i=0;a[i];i++);
	for(j=i-1;j>=0;j--){
		b->num[k++]=a[j]-'0';
	}
	for(j=i;j<digit;j++){
		b->num[j]=0;
	}
	b->cnt=i;
} 
int main(){
	int i;
	char s1[100],s2[100];
	while(scanf("%s%s",s1,s2)!=EOF){
	    bigint a,b,c;
	    stringtointarray(s1,&a);
	    stringtointarray(s2,&b);
	}
	bigint_addition(&a,&b,&c);
	for(i=c.cnt-1;i>=0;i--){
		printf("%d",c.num[i]);
	}
	printf("\n");
	return 0;
} 