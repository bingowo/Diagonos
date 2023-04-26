#include<stdio.h>
#include<string.h>
int tt(char a){
    int m[10];
    int i=0;
    int num=0;
    while(a!=0){
        int e;
        e=a%2;
        a=a/2;
        m[i++]=e;
            }
    for(int x=0;x<8;x++){
        if(m[x]==1) num++;
    }
    return num;
    }
int sim(int m,int n)
{
    if(m%n==0) return n;
    else return sim(n,m%n);
}
int main(){
	int T;
	int a[10];
	int b[10];
	int p=0;
	scanf("%d",&T);
	int n=T;
	while((T--)>0){
        int i=0;
        char s[1000];
        while((s[i]=getchar())!=EOF) i++;
        int h=0;
        int n=0;
        int m=0;
        while(s[n]!='\0'){
            h=h+tt(s[n]);
            n++;
            m++;
        }
        int x;
        x=8*m-h;
        h=h/sim(x,h);
        x=x/sim(x,h);
        a[p]=h;
        b[p]=x;
        p--;
        }
    int o=0;
    while(o<n){
        printf("%d",a[o]);
        printf("/");
        printf("%d/n",b[o]);
        o++;
    }
	return 0;
	}