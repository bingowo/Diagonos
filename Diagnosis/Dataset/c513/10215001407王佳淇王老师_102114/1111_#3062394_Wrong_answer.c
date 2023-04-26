#include<stdio.h>
#include<string.h>
#include<ctype.h>

void readpoly(char*p,int*co){
//	memset(co,0,10*sizeof(int));
	while(*p){
		int sign=1,c=0,d=0;
		if(*p=='+') p++;
		else if(*p=='-') {sign=-1;p++;}
		while(isdigit(*p)){c=c*10+*p-'0';p++;}
			if(*p!='x'){co[0]=c*sign;return;}
			else p++;
			if(c==0) c=1;
			if(*p=='^') p++;
			while(isdigit(*p)){d=d*10+*p-'0';p++;}	
			if(d==0) d=1;
			co[d]=c*sign;	
	}
}



int main(){
	char str[100];
	while(gets(str)!=NULL&&str[0]!='\0')
{   int co[10]={0};
	readpoly(str+5,co); 
	char im[41][41];
	int flag[41][41]={0};
	for(int y=0;y<41;y++)
	{
		for(int x=0;x<41;x++){
			int x1=x-20,y1=20-y;
			if(y1==co[3]*x1*x1*x1+co[2]*x1*x1+co[1]*x1+co[0]) {
			im[y][x]='*'; }
			else{
				if(x1==0&&y1==0) im[y][x]='+';
				else if(x1==0&&y1!=0&&y!=0) im[y][x]='|';
				else if(x1!=0&&y1==0&&x!=40) im[y][x]='-';
				else if(x1==0&&y==0) im[y][x]='^';
				else if(y1==0&&x==40) im[y][x]='>';
				else im[y][x]='.';
			} 	
		}
	}
	for(int y=0;y<41;y++)
	{
		for(int x=0;x<41;x++){
	printf("%c",im[y][x]);}
       if(y<40)printf("\n");
	   }
	printf("\n");

}
	
return 0;	
} 