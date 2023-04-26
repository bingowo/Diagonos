#include<stdio.h>
void tt(int a,int b[100]){
    int i=100;
    int e;
    while(a!=0){
        e=a%2;
        a=a/2;
        b[i--]=e;
    }
    }
int main(){
	int T;
	scanf("%d",&T);
	int q[100];
	int x=0;
	while((T--)>0){
        int a,b;
        int num=0;
        scanf("%d %d",&a,&b);
        int m[1000];
        int n[1000];
        tt(a,m[1000]);
        tt(b,n[1000]);
        for(int i=100;i>=0;i--){
            if(m[i]==n[i]) num++;
        }
        q[x++]=num;

	}
	for (int i=0;i<x;i++){
        printf("%d\n",q[i]);
	}
	return 0;
	}
