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
	scanf("%d\n",&T);
	int n=T;
	while((T--)>0){
        char s[1000];
        scanf("%[^\n]",&s);
        int h=0;
        int n=0;
        int m=0;
        while(s[n]!='\0'){
            h=h+tt(s[n]);
            n++;
            m++;
        }
        int x;
        x=8*m;
        int o=sim(x,h);
        h=h/o;
        x=x/o;
        a[p]=h;
        b[p]=x;
        p--;
        }
    int i=0;
    while(i<n){
        printf("%d",a[i]);
        printf("/");
        printf("%d\n",b[i]);
        i++;
    }
	return 0;
	}
