#include<stdio.h> 
#include<string.h>
int wh(char s[]){          //返回小数点的位置 
	int i;
	for(i=0;s[i]!='.'&&i<strlen(s);i++);  //需要兼顾所输入的数不含小数点的情况 
	return i;
}
int pd(char s[],char c[]){ //判断两个数的大小，1代表A更大，-1表示B更大，0表示两者相等 
	if(wh(s)>wh(c)) return 1;
	else if(wh(s)==wh(c)) return strcmp(s,c);
	else return -1; 
}
char* minus(char s[],char c[],char s1[],char c1[],int N){  //此处默认s所代表的值比c大,N表示精确的位数 
	int i,j,t=1;
	for(i=1;i<strlen(s)+1;i++) s1[i]=s[i-1];   //最前面预留一个位置，以免遇到 .99按小数点后第二位四舍五入的情况
	if(wh(s)==strlen(s)) s1[i]='.' ;
	for(i=wh(s1)-wh(c);i<strlen(c)+wh(s1)-wh(c);i++) c1[i]=c[i-wh(s1)+wh(c)];
	if(wh(c)==strlen(c)) c1[i]='.'; 
	int x=strlen(s1)-1,y=strlen(c1)-1;
	while(x>=0&&y>=0){
		if(s1[x]<c1[y]){    //由于小数点是对齐的，因此在x，y位置不可能是小数点 
			s1[x]=s1[x]+':'-c1[y];
			while(s1[x-t]=='0'&&s1[x-t]!='.'){
				s1[x-t]='9';
				t++;
			}
			if(s1[x-t]=='.') s1[x-t-1]-=1;
			else s1[x-t]-=1;
			t=1;
			x--,y--;
		}
		else if(s1[x]=='.'&&c1[y]=='.') x--,y--;   //因为小数点对齐，因此可直接跳过 
		else{             //当s1[x]和c1[y]都是数值时 
			s1[x]=s1[x]-c1[y]+'0';
			x--,y--;
		} 
	}
	int p=wh(s1)+N;
	if(s1[p]<='4') s1[p]=s1[p];    //四舍五入 
	else{
		    while(s1[p-t]=='9'||s1[p-t]=='.'){   //用p-t来表示要更加直观，用p--来表示并不明确 
		    	if(s1[p-t]=='.') t++;
		    	if(s1[p-t]=='9'){
		    		s1[p-t]='0';
		    		t++;
				}
			}
			s1[p]='0';
			s1[p-t]+=1;
			t=1;
        }
    s1[p+1]='\0';
    for(i=0;s1[i]=='0';i++);
    if(s1[i]=='.') i-=1;
	return s1+i; 
}
int main(){
	char s[510],c[510];
	char s1[510],c1[510];
	memset(s1,'0',510);
	memset(c1,'0',510); 
	int N;
	scanf("%s %s %d",s,c,&N);
	if(pd(s,c)>=0) printf("%s",minus(s,c,s1,c1,N));
	else printf("-%s",minus(c,s,s1,c1,N));
	return 0;
}