#include<stdio.h>
#include<math.h>
int main(){
	int T;
	scanf("%d",&T);
	int a[10];
	int p=0;
	while(T>0){
        char s[50];
        scanf("%s",&s);
        int i=0;
        while(s[i]!='\0'){i++;}
        int n=0;
        int num=0;
        int x;
        while(n<=i){
            if(s[n]=='-') x=-1;
            if(s[n]=='0') x=0;
            if(s[n]=='1') x=1;
            num=num+x*pow(3,i-n);
            n++;
        }
        a[p++]=num;
        T--;
	}
	for(int b=0;b<=p;b++){
        printf("case #%d:\n",b);
        printf("%d\n",a[b]);
	}
	return 0;
	}