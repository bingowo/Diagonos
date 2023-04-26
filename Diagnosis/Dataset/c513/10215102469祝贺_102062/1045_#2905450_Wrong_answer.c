#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	char s[105];
	char part[100];
	int size[100];
	int sp;
}st;
int number;
int cmp(const void*a,const void*b){
	long long n1=*((long long *)a),n2=*((long long*)b);
	return n1-n2<0?-1:1;
}
long long f(st* b){
	int len=b[0].sp;long long ans=0, mid[len];
	for(int i=0;i<len;i++){
		long long temp[number];
		for(int j=0;j<number;j++) temp[j]=b[j].size[i];
		qsort(temp,number,sizeof(temp[0]),cmp);
		mid[i]=temp[number/2];
	}
	
	for(int i=0;i<len;i++){
		for(int j=0;j<number;j++){
			long long t=b[j].size[i]-mid[i]<0?-b[j].size[i]+mid[i]:b[j].size[i]-mid[i];
			ans+=t;
		}
	}
	return ans;
}
int main(){
	long long ret=-2;
	scanf("%d",&number);
	st str[number];
	for(int i=0;i<number;i++){
		scanf("%s",&str[i]);str[i].sp=0;
		for(int j=0;j<strlen(str[i].s);j++){
			if(str[i].sp==0){
				str[i].size[str[i].sp]=0;
				str[i].part[str[i].sp++]=str[i].s[j];
			} 
			else if(str[i].part[str[i].sp-1]==str[i].s[j]);
			else{
				str[i].size[str[i].sp]=0;
				str[i].part[str[i].sp++]=str[i].s[j];
				if(i!=0 && (str[i].sp>str[i-1].sp || str[i].part[str[i].sp-1]!=str[i-1].part[str[i].sp-1])){
					ret=-1;break;
				}
			}
			str[i].size[str[i].sp-1]++;
		}
		if(ret==-1)break;
	}
	if(ret==-1){
		printf("-1");;
	}
	else{
	    long long temp=f(str);
	    if(temp<ret || ret==-2)ret=temp;
	    printf("%lld",ret);
	}
	
	return 0;
}