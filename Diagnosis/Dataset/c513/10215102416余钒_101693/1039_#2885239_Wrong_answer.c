#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> 
int T,veccnt;
struct vec{
	char name[10];
	long long num[55],cnt;
}mem[50];
char s[10005],tpname[10];
void cal(struct vec A,struct vec* X,int typ){
	if(typ==1){
		for(int i=1;i<=A.cnt;i++)
			X->num[i]=A.num[i];
		X->cnt=A.cnt;
	} 
	else if(typ<5){
		long long val=X->num[1];
		for(int i=1;i<=A.cnt;i++){
			if(typ==2) X->num[i]=A.num[i]+val;
			if(typ==3) X->num[i]=A.num[i]-val;
			if(typ==4) X->num[i]=A.num[i]*val;
		}	
		X->cnt=A.cnt; 
	}else{
		long long val=X->num[X->cnt];
		for(int i=X->cnt-1;i;i--){
			if(typ==5) val=val+X->num[i];
			if(typ==6) val=X->num[i]-val;
			if(typ==7) val=val*X->num[i];
		}
		X->num[1]=val;
		X->cnt=1;
	}
}
struct vec solve(int l,int r){
	struct vec res,tmp;
	int typ=0;
	res.cnt=tmp.cnt=0;
	for(int i=r;i>=l;i--){
//		if(i!=r && l==1){
//			printf("!! %d\n",i);
//			for(int j=1;j<=res.cnt;j++)
//				printf("%lld ",res.num[j]);
//			puts("");
//		}
//		if(l!=1&&i!=r){
//			printf("?? %d\n",i);
//			for(int j=1;j<=mem[1].cnt;j++)
//				printf("%lld ",mem[1].num[j]);
//			puts("");
//		}
		if(s[i]==' ') continue;
		if(s[i]==')'){
			int t=1;
			for(int j=i-1;j>=l;j--){
				if(s[j]==')') t++;
				if(s[j]=='(') t--;
				if(t==0){
					tmp=solve(j+1,i-1);
					i=j;
					break;
				}
			}
			if(typ==0) res=tmp;
			else cal(tmp,&res,typ),typ=0;
		}
		else if(s[i]=='=') typ=1;
		else if(s[i]=='+') typ=2;
		else if(s[i]=='-') typ=3;
		else if(s[i]=='*') typ=4;
		else if(s[i]=='/'){
			i-=2; 
			if(s[i]=='+') typ=5;
			else if(s[i]=='-') typ=6;
			else typ=7;
//			puts("!!"); 
//			for(int j=1;j<=mem[1].cnt;j++) printf("%d ",mem[1].num[j]);
//			puts("");
//			for(int j=1;j<=res.cnt;j++) printf("%d ",res.num[j]);
//			puts("!!"); 
			cal(res,&res,typ);
			typ=0;
		}
		else if(s[i]>='a'&&s[i]<='z'){
			int len=0,match=0;
			while(s[i]>='a'&&s[i]<='z') tpname[++len]=s[i],i--;
			tpname[len+1]='\0';
			for(int i=1;i<=veccnt;i++){
				if(strcmp(tpname+1,mem[i].name+1)==0){
					match=1;
					if(typ==1) cal(res,&mem[i],typ),typ=0;
					else if(typ!=0) cal(mem[i],&res,typ),typ=0;
					else cal(mem[i],&res,1);
//					for(int j=1;j<=mem[1].cnt;j++) printf("%d ",mem[1].num[j]);
//					puts("");
					break;
				}
			}
			if(!match && typ==1){
				veccnt++;
				mem[veccnt].cnt=res.cnt;
				for(int i=1;i<=res.cnt;i++) mem[veccnt].num[i]=res.num[i];
				for(int i=1;i<=len;i++) mem[veccnt].name[i]=tpname[i];
				mem[veccnt].name[len+1]='\0';
				typ=0;
			}
		}
		else{
			//printf("**i = %d\n",i);
			int p=i,cnt=0;
			long long x=0;
			while(p>=l && (s[p]>='0'&&s[p]<='9') || s[p]==' ') p--;
			if(p>0) p+=2;
			//printf("**p = %d\n",p);
			
			for(int j=p;j<=i;j++){
				if(s[j]>='0'&&s[j]<='9') x=x*10+s[j]-'0';
				if(s[j]==' '||j==i) tmp.num[++cnt]=x, x=0;
			}
			
			tmp.cnt=cnt;
			if(typ==0) typ=1;
			cal(tmp,&res,typ),typ=0;
			i=p;
//			printf("%lld\n",res.cnt);
//			for(int i=1;i<=res.cnt;i++)
//				printf("%lld ",res.num[i]);
//			puts("");
		}
	}
	return res;
}
int main(){
	scanf("%d\n",&T);
	veccnt=0;
	while(T--){
		int l;
		gets(s+1);
		l=strlen(s+1);
		struct vec ans=solve(1,l);
		for(int i=1;i<=ans.cnt;i++)
			printf("%lld ",ans.num[i]);
		puts("");
	}
	return 0;
} 
/*
1
a + ( a = 5 ) + a + ( a = 6 )


*/