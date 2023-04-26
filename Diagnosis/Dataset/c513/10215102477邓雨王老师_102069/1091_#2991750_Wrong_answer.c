//此题中假设a=xn,b=yn,可以得到递推公式x(n+1)=a*x(n)-b*y(n),y(n+1)=a*y(n)+b*x(n) 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a,b;   //a,b分别代表这实部和虚部，因为小于1000，因此用int即可 
typedef struct{
	int a[1000];
	int sign;  //表示大整数的正负 
}pair;
pair* minus();
void print();
int pd(pair* x){
	int i;
	for(i=999;x->a[i]==0;i--);
	if(i==0&&x->a[i]==0) return -1;
	else return i;
} 
int cmp(pair*x,pair*y){
	if(pd(x)>pd(y)) return 1;
	else if(pd(x)<pd(y)) return -1;
	else{
		int i;
		for(i=999;i>=0&&x->a[i]==y->a[i];i--);
		if(i==0&&x->a[i]==y->a[i]) return 1;
		else if(x->a[i]>y->a[i]) return 1;
		else return -1;
	}
}
void read(char s[])   //用来分离复数的实部与虚部 
{
	int i;
	int temp=0;
	long long n=1;
	for(i=0;i<=strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			temp=temp*10+s[i]-'0';
		}
		else if(s[i]=='-'&&i==0){
			if(s[i+1]!='i'){
		    	n=-1;
		    	temp=0;}
			else{
				n=-1;
				temp=1;	
			}
		}
		else if(s[i]=='-'&&i!=0){
			if(s[i+1]=='i'){
				a=temp*n;
				b=-1;
				break;
			}
			else{
				a=temp*n;
				temp=0;
				n=-1;
			}
		}
		else if(s[i]=='+'){
			if(s[i+1]!='i'){
			a=temp*n;
			temp=0;
			n=1;}
			else{
				a=temp*n;
				temp=1;
				n=1;
			}
		}
		else if(s[i]=='i'&&i!=0){
			b=temp*n;
			temp=0;
			n=1;
		}
		else if(s[i]=='i'&&i==0){
			a=0;
			b=1;
		}
		else if(s[i]=='\0'&&temp!=0){
			a=temp*n;
			temp=0;
			n=1;
		}
	}
}
void convert(int p,pair* x){    //把复数的实数与虚数放在pair.a中（倒着放---方便后来做加减法和乘法） 
	if(p<0) {x->sign=-1;p*=-1;}
	int t=0;
	while(p!=0){
		x->a[t]=p%10;
		t++;
		p/=10;
	}
}
pair* mult(pair* x,int a){     //大整数与整形数相乘
    int key=0;
    if(a<0) {x->sign*=-1;a*=-1;key=1;}
	int temp=0,t=0;
	while(temp!=0||t<=pd(x)){
		//printf("%d\n",temp+(x->a[t])*a);
		if((temp+(x->a[t])*a)>=10) {int temp1=x->a[t];x->a[t]=(temp+x->a[t]*a)%10;temp=(temp+temp1*a)/10;}
		else {x->a[t]=temp+a*(x->a[t]);temp=0;}
		//printf("%d\n",temp);
		t++;
	}
	if(key==1) a*=-1;
	return x;
}
pair* plus(pair*x,pair*y){
	if(x->sign*y->sign==1){
		int i,temp=0;
		for(i=0;i<1000;i++){
			if(temp+x->a[i]+y->a[i]>=10) {int temp1=temp+x->a[i]+y->a[i];x->a[i]=temp1%10;temp=temp1/10;}
			else {x->a[i]=temp+x->a[i]+y->a[i];temp=0;}
		}
		return x;  
	}
	else if(x->sign==1&&y->sign==-1){
		y->sign=1;
		minus(x,y);
	}
	else{
		x->sign=1;
		minus(y,x);
	}
}
pair* minus(pair*x,pair*y){
	if(x->sign*y->sign==1){
		if(x->sign==1){
		if(cmp(x,y)==1){   //x,yy为正数且大于y的情况 
			int i=0,temp=0;
			while(i<=pd(x)||temp){
				if(x->a[i]+temp<y->a[i]) {x->a[i]=x->a[i]+temp+10-y->a[i];temp=-1;}
				else{x->a[i]=x->a[i]+temp-y->a[i];temp=0;}
				i++;
			}
			return x;
		}
		else {pair*s=minus(y,x);s->sign=-1;return s;}
	}
	else{  //负数减负数的情况
	    y->sign=1;
	    x->sign=1;
		minus(y,x); 
	}
}
	else{
		if(x->sign==1&&y->sign==-1){
			y->sign*=-1;
			pair*s=plus(x,y);
			return s;
		}
		else{
			y->sign=-1;
			pair*s=plus(x,y);
			s->sign=-1;
			return s;
		}
	}
}
void recur(pair*x,pair*y){
	int i;
	pair x1=*x;
	pair y1=*y;
	pair *temp1=&x1,*temp2=&y1;
	*x=*mult(x,a);
	*y=*mult(y,b);
	*x=*minus(x,y);
	*temp1=*mult(temp1,b);
	*temp2=*mult(temp2,a);
	*y=*plus(temp1,temp2);
}
void print(pair*t){
	int i,p,j;
	for(i=999;t->a[i]==0;i--);  //确定不为0的位置
}
int main(){
	char s[100];
	int chance,i,key=0;
	scanf("%s %d",&s,&chance);
	if(chance==0) {printf("0");return 0;}
	pair x,y;
	x.sign=1,y.sign=1;
	for(i=0;i<1000;i++) x.a[i]=0;
	for(i=0;i<1000;i++) y.a[i]=0;
	read(s);
	pair *x1,*y1;
	x1=&x,y1=&y;  
	convert(a,x1);
	convert(b,y1);
	//printf("%d %d\n",a,b);
	for(i=0;i<chance-1;i++) {recur(x1,y1);}
    if(pd(x1)==-1) {}
    if(x1->sign==-1) printf("-");
    for(i=pd(x1);i>=0;i--) printf("%d",x1->a[i]);
    if(y1->sign==-1) printf("-");
    else printf("+");
    for(i=pd(y1);i>=0;i--) printf("%d",y1->a[i]);
    printf("i");
	return 0; 
}