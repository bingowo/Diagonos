#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void itob(int n,char s[],int b)
{
int i=0,j,d,sign;
char c;
if((sign=n)<0) n=-n; //记录符号
do
{ d = n%b;
if(d<10) s[i] = d+'0';
else s[i] = d-10+'A';
i++;
n/=b;
}while(n>0);
if(sign<0) s[i++]='-';
s[i]='\0';
for(i=0,j=strlen(s)-1;i<j;i++,j--) //反转
c=s[i],s[i]=s[j],s[j]=c;
}
void PrintBit(char s[], int length)
{
    int len = strlen(s);
    if(len < length){
    	int i; 
        for(i = 0; i < (length - len); i ++){
            printf("0");
        }
    }
    printf("%s", s);
}
int main(){
    char s[10000];
    scanf("%s",&s);
    printf("0001");
    char c[100];
    itob(strlen(s),c,2);
    PrintBit(c,10);
    int len=strlen(s);
    int mode=len%3;
    int shang=(len-mode)/3;
    int i;
    for(i=0;i<shang;i++){
        char p[100];
        int t=0;
        t=t+(s[3*i]-'0')*100+(s[3*i+1]-'0')*10+s[3*i+2]-'0';
        itob(t,p,2);
        PrintBit(p,10);
    }
    if(mode==1){
        char t[100];
        int l=s[strlen(s)-1]-'0';
        itob(l,t,2);
        PrintBit(t,4);
    }
    else if(mode==2){
        char t[100];
        int k=(s[strlen(s)-1]-'0')+(s[strlen(s)-2]-'0')*10;
        itob(k,t,2);
        PrintBit(t,7);
    }
        
    }
    
    
