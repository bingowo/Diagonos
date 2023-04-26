#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[100010],b[100010];
int c[100010],d[100010],e[100010];
int check(char array[]){
	int i=0;
	for(i=0;;i++) if(*(array+i)==NULL) break;
	return i;
}
int add(int array1[],int array2[],int strlen_array1,int strlen_array2){
	int i,t=0,j=0;
	for(i=0;i<strlen_array1||i<strlen_array2;i++){
		if(i<strlen_array1) t+=array1[i];
		if(i<strlen_array2) t+=array2[i];
		e[i]=t%10;
		t/=10;
	}
	if(t) e[i]=1;
	return i;
}
int main(){
    int i,T,n;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&n);
        if(n<94){
        	long long int ans=0;
        	if(n==0) ans=0;
            else if(n==1||n==2) ans=1;
            else if(n>2){
            long long int a=1,b=1;
            for(int j=n-2;j>0;j--){
                ans=a+b;
                a=b;
                b=ans;
            }
        }
        printf("case #%d:\n",i);
        printf("%lld\n",ans);
		}
        else{
        	for(int j=n-2;j>0;j--){
        		int strlen_a=strlen(a);
        		int strlen_b=strlen(b);
        		int strlen_e=0;
        		for(int i=strlen_a-1;i>-1;i--) c[strlen_a-i-1]=a[i]-'0';
        		for(int i=strlen_b-1;i>-1;i--) d[strlen_b-i-1]=b[i]-'0';
        		strlen_e=add(c,d,strlen_a,strlen_b);
        		int i=0;
        		for(i=strlen_e;;i--) if(e[i]!=0) break;
        		for(int i=strlen_b-1;i>-1;i--)a[i]=d[i];
        		for(int i=strlen_e-1;i>-1;i--)b[i]=e[i];
			}
			printf("case #%d:\n",i);
            for(;i>=0;i--) printf("%d",e[i]);
            printf("%\n");
		}
    }
    return 0;
}
