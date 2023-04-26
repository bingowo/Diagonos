#include<stdio.h>
#include<string.h>
void itob(int n,char s[100],int b)
{
int i=0,j,d,sign;
char c;
do
{ d = n%b; //d表示每次的余数 
if(d<0){
	d=-b+d;
	n=(n-d)/b; 
    if(d<10) s[i]=d+'0';
    else s[i]=d-10+'A';
} 
else{
	n=(n-d)/b;
	if(d<10) s[i]=d+'0';
    else s[i]=d-10+'A';
}
i++;
}while(n!=0);
s[i]='\0';
for(i=0,j=strlen(s)-1;i<j;i++,j--) //反转
c=s[i],s[i]=s[j],s[j]=c;
}
int main(){
	int n,R;
	char s[1000];
	scanf("%d %d",&n,&R);
	itob(n,s,R);
	printf("%s",s);
}