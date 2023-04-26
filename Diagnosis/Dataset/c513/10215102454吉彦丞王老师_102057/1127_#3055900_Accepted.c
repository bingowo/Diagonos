#include<stdio.h>
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int min(int a,int b){
	if(a>b){
		return b;
	}
	else{
		return a;
	}
}
int gongbei(int a,int b){
    int c=a*b;
    int d=max(a,b);
    int re;
    for(int i=d;i<=c;i++){
        if(i%a==0&&i%b==0){
            re=i;
            break;
        }
    }
    return re;
}
int gongyue(int a,int b){
	int c=min(a,b);
	int re=1;
	for(int i=c;i>=2;i--){
		if(a%i==0&&b%i==0){
			re=i;
			break;
		}
	}
	return re;
}
int main()
{
    int number;
    scanf("%d",&number);
    int a[number];
    int b[number];
    char s[number];
    for(int i=0;i<number;i++){
        scanf("%d%c%d",&a[i],&s[i],&b[i]);
    }
    int t=b[0];
    for(int i=1;i<number;i++){
        t=gongbei(t,b[i]);
    }
    int d[number];
    for(int i=0;i<number;i++){
        d[i]=t/b[i];
    }
    int m=0;
    for(int i=0;i<number;i++){
        m=m+d[i]*a[i];
    }
    int x=gongyue(m,t);
    printf("%d/%d",m/x,t/x);
    return 0;
}