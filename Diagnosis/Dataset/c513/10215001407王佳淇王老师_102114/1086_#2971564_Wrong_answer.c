#include<stdio.h>
#include<string.h>
#define L 500
int CMP(int buf1[],int buf2[]){
int cmp = memcmp(buf1,buf2,sizeof(buf1)<=sizeof(buf2) ? sizeof(buf1)/sizeof(int) : sizeof(buf2)/sizeof(int));
if( 0 == cmp)
{
	if(sizeof(buf1)==sizeof(buf2));
	else if(sizeof(buf1) < sizeof(buf2))
		cmp = -1;
	else
		cmp = 1;
}
	return cmp;
}



int C[2*L+1]={0},D[2*L+1]={0},E[2*L+1]={0};
void Input(int a[])   //input a float number
{
    char s[L+1];
    scanf("%s",s);    
    int i=0,j,k;
    while(s[i] && s[i]!='.') i++; //定位小数点
    for(j=i-1,k=L;j>=0;j--,k--) 
       a[k] = s[j]-'0';  //整数部分
    for(j=i+1,k=L+1;j<strlen(s);j++,k++) 
         a[k] = s[j]-'0';   //小数部分
}

int minus(int a[],int b[],int N)  
 {int i,flag=1;
 if(CMP(a,b)<0) {
 	for(int k=0;k<2*L+1;k++) C[k]=b[k];
 	for(int k=0;k<2*L+1;k++) D[k]=a[k];
 	flag=-1;
 } 
 else{
    for(int k=0;k<2*L+1;k++) C[k]=a[k];
 	for(int k=0;k<2*L+1;k++) D[k]=b[k];
 }
 for(i=2*L;i>L+N;i--){
 	if(C[i]<D[i]){C[i-1]--;C[i]+=10;}
 	E[i]=C[i]-D[i]; 	
 }
 if(E[i+1]>='5') E[i]++;
    for(i=L+N;i>0;i--){
    	if(C[i]<D[i]){C[i-1]--;C[i]+=10;}
 	      E[i]=C[i]-D[i]; 		
	}
	return flag;	
	}
    
	/// 
void output(int a[],int N)
{
    int i=0;
    while(i<=L && a[i]=='0') i++;  //跳过前置0
    if(i>L) printf("0");   //整数部分为0
    else
    {
        while(i<=L) printf("%c",a[i++]); //整数部分
		              
    }
     printf(".");
    while(i<=L+N) printf("%c",a[i++]);//小数部分
		                     
}
int main(){
     int A[2*L+1]={0}, B[2*L+1]={0},N;
	 Input(A);
	 Input(B);
	 scanf("%d",&N);
	 int f=minus(A,B,N); 
	 if(f==-1) printf("-");
	 output(E,N);
}