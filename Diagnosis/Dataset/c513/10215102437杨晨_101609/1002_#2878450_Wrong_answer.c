#include<stdio.h>
#include<math.h>

int num(char x){       //将数据中的字符转化为对应数字
    int d;
    if(x>='0'&&x<='9') d=x-'0';
    if(x>='a'&&x<='z') d=x-'a'+10;
    if(x>='A'&&x<='Z') d=x-'A'+10;
    return d;
    }
int max(int x[]){     //计算一行数据中最大的数
    int m=x[0];
    for(int i=1;x[i]!='\0';i++){
        if(x[i]>=m) m=x[i];
    }
    return m;
    }
int n_10(int a[],int m,int n){
    int y=0;
    for(int i=0;i<=n;i++){
        y=y+a[i]*pow(m,n-i);
    }
    return y;
    }
int main(){
	int T,n;
	n=0;
	scanf("%d",&T);
	long long s[10];
    while(T>0){
        char z[60];
        int a[60];
        int i=0;
        scanf("%s",&z);
        for(i=0;z[i]!='\0';i++){
            a[i]=num(z[i]);
        }
        int b;
        b=max(a)+1;
        s[n]=n_10(a,b,i);
        T--;
        n++;
    }
    for(int c=0;c<=n;c++){
        printf("case #%d:\n",c);
        printf("%lld\n",s[c]);
    }
	return 0;
	}
