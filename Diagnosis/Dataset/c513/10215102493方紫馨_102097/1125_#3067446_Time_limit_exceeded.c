#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		char s[20];
		scanf("%s",s);
		
		double f;
		char *p=strchr(s,'[');
		if(p==NULL){
			int i=2;
			f=atof(s);
			while(((int)(i*f)-i*f)!=0){
				i++;
			}
			printf("case #%d:\n",k);
			printf("%d/%d\n",(int)(i*f),i);
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