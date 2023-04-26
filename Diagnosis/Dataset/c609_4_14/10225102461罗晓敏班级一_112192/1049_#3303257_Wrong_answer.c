#include <stdio.h>
#include <string.h>
#define digit 500
typedef struct bigint{
	int cnt;
	int num[digit];          //个位在num[0]
}bigint;
void bigint_subtraction(bigint* a,bigint* b,bigint* c){//正数a-正数b=c并且a>b 
	int i,max=a->cnt>b->cnt?a->cnt:b->cnt;
	for(i=0;i<max;i++){
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
	for(i=max-1;c->num[i]==0&&i>=0;i--);
	c->cnt=i+1;
}
//将数字字符串转化为bigint类型
void stringtointarray(char a[],bigint* b){
	int i,j,k=0;
	for(i=0;a[i];i++);
	for(j=i-1;j>=0;j--){
		b->num[k++]=a[j]-'0';
	}
	b->cnt=i;
} 
int ifadayub(char a[],char b[]){       //a>b返回1, a=b返回0, a<b返回-1
	int x=strlen(a),y=strlen(b);
	if(x>y){
		return 1;
	}else if(x<y){
		return -1;
	}else{
		return strcmp(a,b);
	}
}
int main(){
	int i;
	char s1[digit+1],s2[digit+1];
	while(scanf("%s%s",s1,s2)!=EOF){
		bigint a,b,c;
		for(i=0;i<digit;i++){
			a.num[i]=0;
		}
		for(i=0;i<digit;i++){
			b.num[i]=0;	
		}
		for(i=0;i<digit;i++){
			c.num[i]=0;	
		}
		stringtointarray(s1,&a);
		stringtointarray(s2,&b);
		int judge=ifadayub(s1,s2);
		if(judge==1){
			bigint_subtraction(&a,&b,&c);
		}else if(judge==0){
			printf("0");
			continue;
		}else{
			printf("-");
			bigint_subtraction(&b,&a,&c);
		}
		/*printf("%d\n",a.cnt);
		for(i=a.cnt-1;i>=0;i--){printf("%d",a.num[i]);}
		printf("\n");
		printf("%d\n",b.cnt);
		for(i=b.cnt-1;i>=0;i--){printf("%d",b.num[i]);}
		printf("\n");*/
		for(i=c.cnt-1;i>=0;i--){
			printf("%d",c.num[i]);
		}
		printf("\n");
	}
	return 0;
} 