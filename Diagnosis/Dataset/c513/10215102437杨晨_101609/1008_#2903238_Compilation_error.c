#include<stdio.h>
#include<string.h>
void tt(char a[],char b[]){
    int c=0;
    char s[100];
    if(strlen(a)>strlen(b)){
        int x=1;
        for(;c<(strlen(a)-strlen(b));c++){
            s[c]='0';
        }
    }
    if(strlen(b)>strlen(a)){
        int x=2;
        for(;c<(strlen(b)-strlen(a));c++){
            s[c]='0';
        }
    }
    s[c]='\0';
    if(x==1) strcat(b,s);
    if(x==2) strcat(a,s);
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
        char m[1000];
        char n[1000];
        int i=0;
        if(a==0){
            m[i++]='0';
        }
        while(a!=0){
            int e;
            e=a%2;
            a=a/2;
            m[i++]=e+'0';
    }
        m[i]='\0';
        int i=0;
        if(b==0){
            n[i++]='0';
        }
        while(b!=0){
            int e;
            e=b%2;
            b=b/2;
            n[i++]=e+'0';
    }
        n[i]='\0';
        tt(m,n);
        for(int j=0;m[j]!='\0';j++){
            if(m[j]!=n[j]) num++;
        }
        q[x++]=num;

	}
	for (int i=0;i<x;i++){
        printf("%d\n",q[i]);
	}
	return 0;
	}
