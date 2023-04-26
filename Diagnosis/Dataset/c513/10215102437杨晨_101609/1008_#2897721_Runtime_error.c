#include<stdio.h>
#include<string.h>

int main(){
	int T;
	scanf("%d",&T);
	int q[100];
	int x=0;
	while((T--)>0){
        int a,b;
        int num=0;
        scanf("%d %d",&a,&b);
        char m[1000];
        char n[1000];
        int i=1000;
        while(a!=0){
            int e;
            e=a%2;
            a=a/2;
            m[i--]=e+'0';
    }
        int t=1000;
        while(b!=0){
            int e;
            e=b%2;
            b=b/2;
            n[t--]=e+'0';
    }
        while(strlen(m)>strlen(n)){
              n[t--]='0';
              }
        while(strlen(n)>strlen(m)){
              m[i--]='0';
              }
        for(int j=1000;m[j]!='\0';j--){
            if(m[j]==n[j]) num++;
        }
        q[x++]=num;

	}
	for (int i=0;i<x;i++){
        printf("%d\n",q[i]);
	}
	return 0;
	}

