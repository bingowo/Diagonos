#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int GCD(int m,int n)
{
    int i=1,x; //x即代表最大公约数
    if(m%n==0){  //若成立，则说明m>=n,且n是m的一个约数
        return n;
    }
    return GCD(n,m%n);
}
int pd(int n){
	if(sqrt(n)==(int)sqrt(n)) return 1;
	else return -1;
}
void readpoly(char *p, int* co)   //用来读取数字 
{  while (*p)
   {  int sign=1,c=0,d=0;
      if (*p=='+' ) p++; 
      else if (*p=='-') sign=-1,p++;
      while (isdigit(*p)) {  c=c*10+*p-'0'; p++;}
      if (*p!='x') { co[0]=c*sign; return; } else p++;
      if (c==0) c=1;
      if (*p=='^') p++;
      while (isdigit(*p)) {  d=d*10+*p-'0'; p++;}
      if (d==0) d=1;
      co[d]=c*sign;
    }
}
int main(){
	char s[100];
	int co[100]={0},i;
	while(scanf("%s",s)!=EOF){
		readpoly(s,co);
		for(i=100-1;co[i]==0;i--);
        if(co[1]*co[1]-4*co[0]*co[2]<0||(pd(co[1]*co[1]-4*co[0]*co[2]))==-1) printf("No Answer!");
        else{
        	int m=sqrt(co[1]*co[1]-4*co[0]*co[2]);
        	int x1,y1,x2,y2;
        	//printf("%d %d %d\n",co[0],co[1],co[2]);
        	x1=2*co[2],x2=2*co[2],y1=co[1]+m,y2=co[1]-m;
        	//printf("%d %d %d %d\n",x1,y1,x2,y2);
        	int g1=GCD(y1,x1),g2=GCD(y2,x2);
        	x1=x1/g1,x2=x2/g2,y1=y1/g1,y2=y2/g2;
        	//printf("%d %d %d %d\n",x1,y1,x2,y2);
			if(x1<0) x1*=-1,y1*=-1;
			if(x2<0) x2*=-1,y2*=-1;
        	if(x1<x2) printf("%d %d %d %d",x1,y1,x2,y2);
        	else if(x1==x2){
        		if(y1<y2)  printf("%d %d %d %d",x1,y1,x2,y2);
        		else printf("%d %d %d %d",x1,y2,x2,y1);
			}
			else printf("%d %d %d %d",x2,y2,x1,y1); 
		}
	}
}
