//#include <stdio.h>
//#include<stdlib.h>
//
//long long power(int x,int y){
//	long long t=1;
//	int j;
//	for(j=0;j<y;j++)
//		t*=x;
//	return t;
//}
//
//long long num(int i,char* a){
//	int n,j=0;
//	long long sum;
//	for(n=i;a[n]>='0'&&a[n]<='9';n++);
//	while(n>=i){
//		sum+=(a[n]-'0')*power(10,j);
//		j++,n--;
//	}
//	return sum;
//}
//
//int strnumcmp(const void* a,const void* b){
//	int i;
//	long long nums=-1,numt=-1;
//	char *s=(char*)a,*t=(char*)b;
//	for(i=0;s[i]!=0;i++){
//		if(s[i]>='0'&&s[i]<='9'){
//			nums=num(i,s);
//		}
//	for(i=0;t[i]!=0;i++){
//		if(t[i]>='0'&&t[i]<='9'){
//			numt=num(i,t);	
//		}
//	}
//	if(nums+numt>-2&&nums!=numt)
//		return nums-numt;
//	else if(nums==-1&&numt==-1)
//		return strcmp(s,t);
//		else if(s[i]==t[i])continue;
//		else if(t[i]>='0'&&t[i]<='9')return -1;
//		else return s[i]-t[i];
//	}
//	if(s[i]==0)return -1;
//	else return 1;
//}
//
//int main(){
//	int n,i;
//	int a[100][30]={0};
//	for(n=0;(scanf("%s",&a[n])!=EOF);n++);
//	qsort(a,n,sizeof(a[0]),strnumcmp);
//	for(i=0;i<n-1;i++){
//		printf("%s ",a[i]);
//	}
//	printf("%s",a[n-1]);
//	return 0;
//}