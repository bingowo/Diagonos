#include <stdio.h>
int a,b;
struct num{
  int L[100];
  int flag;
};
void func(struct num a){
	int zero=0;
	if(a.flag==-1) printf("-");
	for(zero=0;a.L[zero]==0;)zero++;
	for(int i=zero;i<100;i++) printf("%d",a.L[i]);
	printf("\n");
}
void Input()
{
    a=0; b=0;
    int val=0,f=1; 
    char s[100];
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++)
    {
    	if(s[i]=='-') f=-1;
    	else if(s[i]<='9'&&s[i]>='0') val=val*10+s[i]-'0';
    	else if(s[i]=='i') b= val==0?f:f*val;
    	if(val!=0 && (s[i+1]=='-'||s[i+1]=='+')) {a=f*val;val=0;f=1;} 
	}
}
void Output(struct num N1,struct num N2)
{
	int zero1=0,zero2=0;
    for(zero1=0;N1.L[zero1]==0 && zero1<100;)zero1++ ;
	for(zero2=0;N2.L[zero2]==0 && zero2<100;)zero2++ ;
	if(zero1!=100 && zero2!=100){
		if(N1.flag==-1) printf("-");
		for(int i=zero1;i<100;i++) printf("%d",N1.L[i]);
		if(N2.flag==1) printf("+");
		else printf("-");
		if(zero2!=99 || N2.L[99]!=1){
			for(int i=zero2;i<100;i++) printf("%d",N2.L[i]);
		}
		printf("i");
	} else if(zero1==100 && zero2!=100) {
		if(N2.flag==-1) printf("-");
		if(zero2!=99 || N2.L[99]!=1){
			for(int i=zero2;i<100;i++) printf("%d",N2.L[i]);
		}
		printf("i");
	} else if(zero1!=100 && zero2==100) {
		if(N1.flag==-1) printf("-");
		for(int i=zero1;i<100;i++) printf("%d",N1.L[i]);
	} else {
		printf("0");
	}
	printf("%d %d",zero1,zero2);
}
int absCompare(struct num n1,struct num n2)
{
	for(int i=0;i<100;i++){
		if(n1.L[i]>n2.L[i]) return 1;
		else if(n1.L[i]<n2.L[i]) return -1;
	}
	return 0;
}
struct num mul(struct num n,int c)
{
	struct num res; 
	int temp=0,left=0;
    if(c*n.flag<0) res.flag=-1;
    else res.flag=1;
    if(c<0) c=-c;
    for(int i=99;i>=0;i--) res.L[i] = n.L[i]*c;
    for(int i=99;i>=0;i--){
    	temp = res.L[i]+left;
    	res.L[i] = temp%10;
    	left = temp/10;
	}
	return res;
}
struct num add(struct num n1,struct num n2)
{
	struct num res;
    if(n1.flag==1 && n2.flag==-1){
		if(absCompare(n1,n2)==1){
    		res.flag = 1;
    		for(int i=99;i>=0;i--)
	    	{
	   			if(n1.L[i]>=n2.L[i]) res.L[i] = n1.L[i]-n2.L[i];
	   			else {
	   				res.L[i] = 10+n1.L[i]-n2.L[i];
	   				n1.L[i-1]--;
				}
			}
		} else {
			res.flag = -1;
			for(int i=99;i>=0;i--)
	    	{
	   			if(n2.L[i]>=n1.L[i]) res.L[i] = n2.L[i]-n1.L[i];
	   			else {
	   				res.L[i] = 10+n2.L[i]-n1.L[i];
	   				n2.L[i-1]--;
				}
			}
		}
	} else if(n1.flag==-1 && n2.flag==1) {
		n1.flag=1; n2.flag=-1;
		res = add(n1,n2);
		res.flag*=-1; 
	} else {
    	int temp=0,left=0;
    	res.flag = n1.flag;
    	for(int i=99;i>=0;i--)
    	{
   			temp = n1.L[i]+n2.L[i]+left;
    		res.L[i] = temp%10;
    		left = temp/10;
		}
	}
	return res;
}
struct num sub(struct num n1,struct num n2)
{
	struct num res;
    if(n1.flag==1 && n2.flag==1){
    	if(absCompare(n1,n2)==1){
    		res.flag = 1;
    		for(int i=99;i>=0;i--)
	    	{
	   			if(n1.L[i]>=n2.L[i]) res.L[i] = n1.L[i]-n2.L[i];
	   			else {
	   				res.L[i] = 10+n1.L[i]-n2.L[i];
	   				n1.L[i-1]--;
				}
			}
		} else {
			res.flag = -1;
			for(int i=99;i>=0;i--)
	    	{
	   			if(n2.L[i]>=n1.L[i]) res.L[i] = n2.L[i]-n1.L[i];
	   			else {
	   				res.L[i] = 10+n2.L[i]-n1.L[i];
	   				n2.L[i-1]--;
				}
			}
		}
	} else if(n1.flag==-1 && n2.flag==-1) {
		n1.flag=1; n2.flag=1;
		res = sub(n1,n2);
		res.flag*=-1;
	} else if(n1.flag==1 && n2.flag==-1) {
		n2.flag=1;
		res = add(n1,n2);
	} else {
		n1.flag=1;
		res = add(n1,n2);
		res.flag*=-1;
	}
 	return res;
}
struct num toNum(int n)
{
    struct num N;
    if(n>=0) N.flag=1;
    else {N.flag=-1; n=-n;}
    for(int i=0;i<100;i++) N.L[i]=0; 
    for(int i=99;n!=0;i--){
    	N.L[i] = n%10;
    	n = n/10;
	}
	return N;
}

int main()
{
    Input();
    int k=0;
    scanf("%d",&k);
    struct num N1,N2,temp1,temp2;
	int N3,N4;
    N1 = toNum(a);N2 = toNum(b);
    N3 = a; N4 = b;
    for(int i=0;i<k-1;i++){
        temp1 = sub(mul(N1,N3),mul(N2,N4));
        temp2 = add(mul(N1,N4),mul(N2,N3));
        N1 = temp1;
        N2 = temp2; 
    }
    if(k==0) printf("1");
    else Output(N1,N2);
    return 0;
}