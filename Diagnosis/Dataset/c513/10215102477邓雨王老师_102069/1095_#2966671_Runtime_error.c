#include<stdio.h>
#include<string.h>
char* pd(char s[]){    //用来给负数取正 
	return s+1; 
}

char* minus(char s[],char c[]){ //此函数默认s代表的数值比c大
	int len1=strlen(s);
	int len2=strlen(c);
	int i,j,temp=0,t=1;
	i=len1-1;j=len2-1;
	while(i>=0&&j>=0){
		if(s[i]<c[j]){
			s[i]=s[i]+':'-c[j];   //":在ascii码表中排在9的后面一格"
			while(s[i-t]=='0'){
				s[i-t]='9';
				t++;
			}
			s[i-t]-=1;
			t=1;
			i--;
		}
		else{
			s[i]=s[i]-c[j]+'0';
			i--;
		}
		if(j==0&&i!=0){j=0;c[j]='0';}
		else j--;
	}
	for(i=0;s[i]=='0';i++);
	return s+i; 
} 
char* plus(char s[],char c[],char s1[],char c1[]){   //这里已经假定
	int i,j,t=1;
	if(strlen(s)>strlen(c)){
	for(i=1;i<strlen(s)+1;i++) s1[i]=s[i-1];   //最前面预留一个位置,以防止最高位进位 
	for(i=1+strlen(s)-strlen(c);i<strlen(s)+1;i++) c1[i]=c[i-1+strlen(c)-strlen(s)];}
	else{
			for(i=1;i<strlen(c)+1;i++) c1[i]=c[i-1];   //最前面预留一个位置,以防止最高位进位 
	        for(i=1+strlen(c)-strlen(s);i<strlen(c)+1;i++) s1[i]=s[i-1+strlen(s)-strlen(c)];}
	int x=strlen(s1)-1,y=strlen(c1)-1;
	int max=(strlen(s)>strlen(c))?strlen(s):strlen(c);
	while(x>=0&&y>=0){
		if(s1[x]+c1[y]-'0'>'9'){   //'.'在ascii码表中值为46，排在'0'前面，因此无需考虑'.'+'数字'>'9'的情况 
			s1[x]=s1[x]+c1[y]-':';
			while(s1[x-t]=='9'){
			    s1[x-t]='0';
			    t++;
				
			}
			s1[x-t]+=1;
			x--,y--;
			t=1;
		}
		else{
			s1[x]=s1[x]+c1[y]-'0';
			x--,y--;
		}
	}
	s1[max+1]='\0';
	if(s1[0]=='0') return s1+1; 
	else return s1;
} 
int main(){
	int k=0;
	char t[1000];
	char s[1000];
	scanf("0x%s",&s);
	int i;
    for(i=0;i<strlen(s);i++)  //16进制转转为2进制
    {
        int d;
        if(s[i]>='A') d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned int flag=0x8;
        while(flag)
        {
            if(d&flag) t[k++]='1';
            else t[k++]='0';
            flag=flag>>1;
        }
    }   //数组s存放16进制(去掉0x)，数组t存放转换后的2进制
    long long int qr=0,qi=0;
    long long int a,b;
    for(i=0;i<k;i++)   //计算复数整数
    {
        int r=t[i]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
    }
    if(qi==0)     //输出，没有虚部
    {
        printf("%lld\n",qr);
    }
    else       //输出，有虚部
    {
        if(qr!=0)  //有实部
        {
            printf("%lld",qr);
            if(qi>0) printf("+");
        }
        if(qi==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else {printf("%lld",qi);printf("i\n");}
    }
}