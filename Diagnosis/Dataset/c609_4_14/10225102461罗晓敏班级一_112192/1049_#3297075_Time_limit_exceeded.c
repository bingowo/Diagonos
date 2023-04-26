#include <stdio.h>
#define digit 500
typedef struct bigint{
	int cnt;
	int num[digit];          //个位在num[0]
	int sign;                //1为正  0为负 1/0为0 
}bigint;
//加法
void bigint_addition(bigint* a,bigint* b,bigint* c){           //a+b=c
	int i,temp=0;
	for(i=0;i<a->cnt||i<b->cnt;i++){
		c->num[i]=(a->num[i]+b->num[i]+temp)%10;
		temp=(a->num[i]+b->num[i]+temp)/10;
		//printf("%d ",c->num[i]);
	}
	if(temp){
		c->num[i++]=temp;
		c->cnt=(a->cnt>b->cnt?a->cnt:b->cnt)+1;
		return;
	}
	c->cnt=a->cnt>b->cnt?a->cnt:b->cnt;
	
}
//减法
void bigint_subtraction(bigint* a,bigint* b,bigint* c){   //正数a-正数b=c并且a>b 
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
//将数字字符串转化为bigint类型
void stringtointarray(char a[],bigint* b){
	int z=0;
	if(a[0]=='-'){
		b->sign=0;
		z=1;
	}else if(a[0]=='+'){
		b->sign=1;
		z=1;
	}else{
		b->sign=1;
	}
	int i,j,k=0;
	for(i=z;a[i];i++);
	for(j=i-1;j>=z;j--){
		b->num[k++]=a[j]-'0';
	}
	for(j=i-z;j<digit;j++){
		b->num[j]=0;
	}
	b->cnt=i-z;
} 
int ifadayub(bigint* a,bigint *b){         //绝对值   a>b返回正数, a=b返回0, a<b返回负数
	int sign=0;int i;
	if(a->num[a->cnt-1]==0&&b->num[b->cnt-1]==0) return 0;
	if(a->sign==1&&b->sign==0)return 1;
	else if(a->sign==0&&b->sign==1)return -1;
	else if(a->sign==1&&b->sign==1){
		if(a->cnt!=b->cnt)return a->cnt-b->cnt;
		else 
			for(i=a->cnt-1;i>=0;i--){
				if(a->num[i]!=b->num[i]){
					return a->num[i]-b->num[i];
				}
			}
			return 0;
	}else{
		if(a->cnt!=b->cnt)return b->cnt-a->cnt;
		else 
			for(i=a->cnt-1;i>=0;i--){
				if(a->num[i]!=b->num[i]){
					return b->num[i]-a->num[i];
				}
			}
			return 0; 
	}
}
int main(){
	int i;
	char s1[digit+1],s2[digit+1];
	while(scanf("%s%s",s1,s2)){
		bigint a,b,c;
		stringtointarray(s1,&a);
		stringtointarray(s2,&b);
		int judge=ifadayub(&a,&b);
		if(a.sign==1&&b.sign==1){
			if(judge>0){
				c.sign=1;
				bigint_subtraction(&a,&b,&c);
			}else if(judge==0){
				c.cnt=1;
				c.num[0]=0;
			}else{
				c.sign=0;
				bigint_subtraction(&b,&a,&c);
			}
		}else if(a.sign==1&&b.sign==0){
			c.sign=1;
			bigint_addition(&a,&b,&c);
		}else if(a.sign==0&&b.sign==1){
			c.sign=0;
			bigint_addition(&a,&b,&c);
		}else{
			if(judge>0){
				c.sign=1;
				bigint_subtraction(&b,&a,&c);
			}else if(judge==0){
				c.cnt=1;
				c.num[0]=0;
			}else{
				c.sign=0;
				bigint_subtraction(&a,&b,&c);
			}
		}
		/*printf("%d\n",a.cnt);
		for(i=a.cnt-1;i>=0;i--){printf("%d",a.num[i]);}
		printf("\n");
		printf("%d\n",b.cnt);
		for(i=b.cnt-1;i>=0;i--){printf("%d",b.num[i]);}
		printf("\n");*/
		if(c.sign==0&&(c.num[c.cnt-1]!=0)){
			printf("-");
		}
		for(i=c.cnt-1;i>=0;i--){
			printf("%d",c.num[i]);
		}
		printf("\n");
	}
	return 0;
} 