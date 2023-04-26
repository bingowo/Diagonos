#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
typedef struct{
	int sign,length;
	char s[121];
}NUM;
//升序 
int cmp(const void*p1,const void*p2){
	NUM* a = (NUM*)p1;
	NUM* b = (NUM*)p2;
	if(a->sign!=b->sign)
		return a->sign - b->sign;
	if(a->sign==1){
		if(a->length!=b->length)
			return a->length-b->length;
		else{
			int i = 120-a->length;
			while(i<=120&&a->s[i]==b->s[i]) i++;
			return a->s[i]-b->s[i];
		}
	}
	if(a->sign==-1){
		if(a->length!=b->length)
			return -a->length+b->length;
		else{
			int i = 120-a->length+1;
			while(i<=120&&a->s[i]==b->s[i]) i++;
			return -a->s[i]+b->s[i];
		}
	}
}

void minus(NUM* a,NUM* b,int d[]){
	if(a->sign>0&&b->sign>0){
		int r = 0;
		for(int i=120;i>120-a->length;i--){
			if(b->s[i]==0)
				b->s[i] = '0';
			d[i+1] = a->s[i] - b->s[i] - r;
			r = 0;
			if(d[i+1]<0){
				d[i+1] += 10;
				r = 1;
			}		
		}
	}
	if(a->sign<0&&b->sign<0){
		int r = 0;
		for(int i=120;i>120-a->length+1;i--){
			if(a->s[i]==0)
				a->s[i] = '0';
			d[i+1] = b->s[i] - a->s[i] - r;
			r = 0;
			if(d[i+1]<0){
				d[i+1] += 10;
				r = 1;
			}		
		}
	}
	if(a->sign>0&&b->sign<0){
		int r = 0;
		int i=120;
		for(;i>120-a->length||i>120-b->length+1;i--){
			if(a->s[i]==0||a->s[i]=='-')
				a->s[i] = '0';
			d[i+1] = b->s[i]-'0' + a->s[i]-'0' + r;
			r = 0;
			if(d[i+1]>=10){
				d[i+1] -= 10;
				r = 1;
			}		
		}
		if(r==1)
			d[i+1] = 1;
	}
	
}

int main()
{
	int n;
	scanf("%d",&n);
	char num[121];
	NUM cas[50];
	for(int i=0;i<n;i++){
		for(int k=0;k<121;k++)
			cas[i].s[k] = '\0';
		scanf("%s",num);		
		cas[i].length = strlen(num);
		if(num[0]=='-')
			cas[i].sign = -1;
		else
			cas[i].sign = 1;
		for(int j = strlen(num)-1,d = 120;j>=0;d--,j--){
			cas[i].s[d] = num[j];
		}		
	}	
	qsort(cas,n,sizeof(NUM),cmp);
	/*for(int i=0;i<n;i++){
		int idx = 0;
		while(idx<=120&&cas[i].s[idx]=='\0')			
			idx++;
		for(;idx<=120;idx++)
			printf("%c",cas[i].s[idx]);
		printf("\n");
	}*/
	int d[122] = {0};
	minus(cas+n-1,cas,d);
	int i=0;
	while(i<=121&&d[i]==0){		
		i++;
	}
	for(;i<=121;i++)
		printf("%d",d[i]);	
	return 0; 
 } 
