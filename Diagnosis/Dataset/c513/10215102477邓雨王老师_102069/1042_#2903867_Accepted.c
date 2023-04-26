#include<stdio.h>
#include<string.h>
int cmp(const void*a,const void*b){
	char *x,*y;
	x=(char*)a;
	y=(char*)b;
	return strcmp(x,y);
}
void sort(char s[],char c[]){      //对字符串进行去重 
	int i;
	int length=strlen(s);
	int j=0;
	for(i=0;i<length;i++){
		int m=s[i];
		if(strchr(s,m)==&s[i]) c[j++]=s[i];
	}
	c[j]='\0';
}
void cal(char s[],char c[][20]){
	int length=strlen(s);
	int sum=1,i=0;
	for(i=0;i<strlen(s);i++){
		sum=sum*2;
	}
	sum=sum-1;
	for(i=0;i<=sum-1;i++){
		int temp=i+1;
		int t=0,j=0;
		while(temp>0){
		    if(temp%2==1){
			    c[i][j]=s[t];
			    j++;
			    temp=temp/2;
			    t++;
		}
		    else{
		    	t++;
		    	temp=temp/2;
			}
		    c[i][j]='\0';
	}
} 
}
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		char s[20];
		scanf("%s",&s);
		char c[20];   //c是去重后的数组 
		sort(s,c);
		qsort(c,strlen(c),sizeof(c[0]),cmp);
		int sum=1;
		int j;
	    for(j=0;j<strlen(c);j++){
	    	sum=sum*2;
	}
	    sum=sum-1;
		char c1[sum][20];
		cal(c,c1);
		qsort(c1,sum,sizeof(c1[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<sum;j++){
			printf("%s\n",c1[j]);
		}
	}
}