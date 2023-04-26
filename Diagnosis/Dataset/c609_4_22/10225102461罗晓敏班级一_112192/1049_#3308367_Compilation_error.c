#include <stdio.h>
#define digit 500
typedef struct bigint{
	int cnt;
	int num[digit];          //个位在num[0] 且数存完了剩余的都是0 
}bigint;
//正数a+正数b=c
void bigint_addition(bigint* a,bigint* b,bigint* c){
	int i,temp=0;
	for(i=0;i<a->cnt||i<b->cnt;i++){
		c->num[i]=(a->num[i]+b->num[i]+temp)%10;
		temp=(a->num[i]+b->num[i]+temp)/10;
		//printf("%d ",c->num[i]);
	}
	if(temp==0){
		c->cnt=i;
	}else{
		c->num[i]=temp;
		c->cnt=i+1;
	}
}
//正数a-正数b=c并且a>b
void bigint_subtraction(bigint* a,bigint* b,bigint* c){
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
	int max=a->cnt>b->cnt?a->cnt:b->cnt
	for(i=max-1;c->num[i]==0&&i>=0;i--);
	c->cnt=i+1;
}
//将数字字符串a转化为bigint b 除了数字其余全为0 
void stringtobigint(char a[],bigint* b){
	int i,j,k=0;
	for(i=0;i<digit;i++){
		b->num[i]=0;
	}
	for(i=0;a[i];i++);
	for(j=i-1;j>=0;j--){
		b->num[k++]=a[j]-'0';
	}
	b->cnt=i;
}
//a>b返回正数, a=b返回0, a<b返回负数
int ifadayub(char a[],char b[]){
	int x=strlen(a),y=strlen(b);
	if(x>y){
		return 1;
	}else if(x<y){
		return -1;
	}else{
		return strcmp(a,b);
	}
}
void test01(){
	int i;
	char s1[digit+1],s2[digit+1];
	while(scanf("%s%s",s1,s2)){
		bigint a,b,c;
		stringtobigint(s1,&a);
		stringtobigint(s2,&b);
		bigint_addition(&a,&b,&c);
		for(i=c.cnt-1;i>=0;i--){
			printf("%d",c.num[i]);
		}
		printf("\n");
	}
}
void test02(){
	int i;
	char s1[digit+1],s2[digit+1];
	while(scanf("%s%s",s1,s2)!=EOF){
		bigint a,b,c;
		stringtointarray(s1,&a);
		stringtointarray(s2,&b);
		int judge=ifadayub(s1,s2);
		if(judge>0){
			bigint_subtraction(&a,&b,&c);
		}else if(judge==0){
			printf("0\n");
			continue;
		}else{
			printf("-");
			bigint_subtraction(&b,&a,&c);
		}
		for(i=c.cnt-1;i>=0;i--){
			printf("%d",c.num[i]);
		}
		printf("\n");
	}
}
int main(){
	//test01();
	test02();
	return 0;
} 