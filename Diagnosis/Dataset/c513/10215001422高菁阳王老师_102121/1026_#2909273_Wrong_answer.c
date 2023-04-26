#include <stdlib.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}
int main(int argc, char *argv[]) {
	int n,m,j=0;
	long int sum=0;
	scanf("%d\n",&n);
	int arr[10001];
	char s[20001];
   gets(s);
   int len=strlen(s);
   for(int i=0;i<len;i++){
	   if(s[i]==' ') continue;
   	arr[j]=s[i]-'0';
   	j++;
   }
   qsort(arr,j+1,sizeof(int),cmp);
   for(m=0;m<j;m+=2){
   	sum+=arr[m+1]-arr[m];
   }
   printf("%ld",sum);
	return 0;
}