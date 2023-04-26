#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
long long int GCD(long long int x,long long int y){
	long long int t=1;
	while(t!=0){
		t=x%y;
		x=y;
		y=t;
	}
	return x;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		char s[20]={0};
		scanf("%s",s);
		
		double f;
		char *p=strchr(s,'[');
		if(p==NULL){
			long long int i=10,z=pow(10,strlen(s)-2);
			f=atof(s);
			f*=z;
			long long int d=GCD(f,z);
			printf("case #%d:\n",k);
			printf("%lld/%lld\n",(long long int)(f/d),z/d);
		}else{
			char dle[20]={0},cir[20]={0};
			int a=0,b=0,c=0;
			p++;
			while(p!=strchr(s,']')){
				cir[a++]=*p;
				p++;
			}
			for(b=0;s[b]!='[';b++){
				dle[b]=s[b];
			}
			while(b<16){
				dle[b++]=cir[c++];
				if(c==a)
					c=0;
			}
			f=atof(dle);
			int i=2;
			int n=(int)(i*f+0.5);
			while(((int)(i*f+0.5)-i*f)>1e-10||((int)(i*f+0.5)-i*f)<-1e-12){
				i++;
				n=(int)(i*f+0.5);
			}
			
			printf("case #%d:\n",k);
			printf("%d/%d\n",n,i);
		}
		
	} 
	return 0;
 } 