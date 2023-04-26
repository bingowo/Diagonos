#include<stdio.h>
#include<string.h>
int main(){
    char s[80];
    scanf("%s",s);
    int l=strlen(s);
    int t1=0;
    int t2=0;
    int m=0;
    char c;
    for(int i=0;i<l;i++){
        if(s[i]=='='){
            m=i;
        }
        if(s[i]>='a'&&s[i]<='z'){
        	c=s[i];
		}
    }
    for(int i=0;i<m;i++){
        if(s[i]>='a'&&s[i]<='z'){
            int x=i;
            if(x==0){
                t1+=1;
            }
            else if(s[x-1]=='+'){
                t1+=1;
            }
            else if(s[x-1]=='-'){
                t1-=1;
            }
            else{
                int j=x-1;
                int link=0;
                while(s[j]>='0'&&s[j]<='9'&&j>0){
                    j--;
                }
                if(j==0){
                    for(int k=0;k<x;k++){
                        link=(link+(s[k]-'0'))*10;
                    }
                }
                else if(s[j]=='+'){
                    for(int k=j+1;k<x;k++){
                        link=(link+(s[k]-'0'))*10;
                    }
                }
                else if(s[j]=='-'){
                    for(int k=j+1;k<x;k++){
                        link=(link+(s[k]-'0'))*10;
                    }
                    link=-link;
                }
                t1+=link/10;
            }
        }
        else if((s[i]>='0'&&s[i]<='9')&&(s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='=')){
            int y=i;
            if(y==0){
                t2-=s[0]-'0';
            }
            else if(s[y-1]=='+'){
                t2-=s[y]-'0';
            }
            else if(s[y-1]=='-'){
                t2+=s[y]-'0';
            }
            else{
                int j=y;
                int link=0;
                while(s[j]>='0'&& s[j]<='9'&&j>0){
                    j--;
                }
                if(j==0){
                    for(int k=0;k<=y;k++){
                        link=(link+(s[k]-'0'))*10;
                    }
                }
                else if(s[j]=='+'){
                    for(int k=j+1;k<=y;k++){
                        link=(link+(s[k]-'0'))*10;
                    }
                }
                else if(s[j]=='-'){
                    for(int k=j+1;k<=y;k++){
                        link=(link+(s[k]-'0'))*10;
                    }
                    link=-link;
                }
                t2-=link/10;
            }
        }
    }
	for(int i=m+1;i<l;i++){
		if(s[i]>='a'&&s[i]<='z'){
            int x=i;
            if(x==m+1){
                t1-=1;
            }
            else if(s[x-1]=='+'){
                t1-=1;
            }
            else if(s[x-1]=='-'){
                t1+=1;
            }
            else{
                int j=x-1;
                int link=0;
                while(s[j]>='0'&&s[j]<='9'&&j>0){
                    j--;
                }
                if(j==m+1){
                    for(int k=m+1;k<x;k++){
                        link=(link+(s[k]-'0'))*10;
                    }
                }
                else if(s[j]=='+'){
                    for(int k=j+1;k<x;k++){
                        link=(link+(s[k]-'0'))*10;
                    }
                }
                else if(s[j]=='-'){
                    for(int k=j+1;k<x;k++){
                        link=(link+(s[k]-'0'))*10;
                    }
                    link=-link;
                }
                t1-=link/10;
            }
        }
        else if((s[i]>='0'&&s[i]<='9')&&(s[i+1]=='+'||s[i+1]=='-'||i==l-1)){
            int y=i;
            if(y==m+1){
                t2+=s[m+1]-'0';
            }
            else if(s[y-1]=='+'){
                t2+=s[y]-'0';
            }
            else if(s[y-1]=='-'){
                t2-=s[y]-'0';
            }
            else{
                int j=y;
                int link=0;
                while(s[j]>='0'&& s[j]<='9'&&j>m+1){
                    j--;
                }
                if(j==m+1){
                    for(int k=m+1;k<=y;k++){
                        link=(link+(s[k]-'0'))*10;
                    }
                }
                else if(s[j]=='+'){
                    for(int k=j+1;k<=y;k++){
                        link=(link+(s[k]-'0'))*10;
                    }
                }
                else if(s[j]=='-'){
                    for(int k=j+1;k<=y;k++){
                        link=(link+(s[k]-'0'))*10;
                    }
                    link=-link;
                }
                t2+=link/10;
            }
        }
	}
	double re=t2*1.0/t1;
	printf("%c=%.3f",c,re);
	return 0;               
}