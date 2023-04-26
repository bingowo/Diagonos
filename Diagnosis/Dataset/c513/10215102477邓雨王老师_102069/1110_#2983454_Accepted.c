#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void solve(char s[]){
	int i,j=0;
	int m=0,n=0,m1=0,n1=0;  //m用来存储未知数的系数，n用来存储常数 
	char temp[10];
	char *p1=s,*p2=s;
	char c;
	for(i=0;s[i]!='=';i++); //用i来存储=的位置
	while(j<=i){
		if(s[j]=='+'&&j==0){
			j++;
			p1++,p2++; 
	    }
	    else if(s[j]=='+'&&j!=0&&(s[j-1]<'a'||s[j-1]>'z')){ //当遇到加号且前面不是未知数时（即前面是常数） 
	    	memmove(temp,p1,p2-p1);
	    	temp[p2-p1]='\0';
	    	//printf("%s\n",temp);
	    	n=n+atoi(temp);
	    	j++;
	    	p2=s+j,p1=s+j;
		}
		else if(s[j]<='z'&&s[j]>='a'){     //遇到未知数的情况 
			c=s[j];
			if(j==0) {m=1;j++;p1++;p2++;}   //放在首位的情况 
			else if(s[j-1]=='-') {m-=1;j++;p2++;p1=p2;}   //-x的情况
			else if(s[j-1]=='+') {m+=1;j++;p1++;p2++;} 
			else{
				memmove(temp,p1,p2-p1);
				temp[p2-p1]='\0';
				//printf("%s\n",temp);
				m=m+atoi(temp);
				j++;
				p2=s+j,p1=s+j; 
			} 
		}
		else if(s[j]=='='&&(s[j-1]>'z'||s[j-1]<'a')){
			memmove(temp,p1,p2-p1);
			temp[p2-p1]='\0';
			n=n+atoi(temp);
			j++;
		}
		else{    //包含-和常数的情况
		    if(s[j]=='-'&&p1!=p2){   //遇到符号且不在首位且前面不为未知数的情况 
		    	memmove(temp,p1,p2-p1);
			    temp[p2-p1]='\0';
			    n=n+atoi(temp);
			    j++;
			    p1=p2;
			    p2++; 
			}
			else{
				p2++;
				j++;
			}
		}
    }
    s[strlen(s)]='=';
    s[strlen(s)+1]='\0';
    p1=s+j,p2=p1;
    j=i+1;
    while(j<=strlen(s)){
		if(s[j]=='+'&&j==i+1){
			j++;
			p1++,p2++; 
	    }
	    else if(s[j]=='+'&&j!=i+1&&(s[j-1]<'a'||s[j-1]>'z')){ //当遇到加号且前面不是未知数时（即前面是常数） 
	    	memmove(temp,p1,p2-p1);
	    	temp[p2-p1]='\0';
	    	//printf("%s\n",temp);
	    	n1=n1+atoi(temp);
	    	j++;
	    	p2=s+j,p1=s+j;
		}
		else if(s[j]<='z'&&s[j]>='a'){     //遇到未知数的情况 
			c=s[j];
			if(j==i+1) {m1=1;j++;p1++;p2++;}   //放在首位的情况 
			else if(s[j-1]=='-') {m1-=1;j++;p2++;p1=p2;}   //-x的情况
			else if(s[j-1]=='+') {m1+=1;j++;p1++;p2++;} 
			else{
				memmove(temp,p1,p2-p1);
				temp[p2-p1]='\0';
				//printf("%s\n",temp);
				m1=m1+atoi(temp);
				j++;
				p2=s+j,p1=s+j; 
			} 
		}
		else if(j==strlen(s)&&(s[j-1]>'z'||s[j-1]<'a')){
			memmove(temp,p1,p2-p1);
			temp[p2-p1]='\0';
			n1=n1+atoi(temp);
			j++;
		}
		else{    //包含-和常数的情况
		    if(s[j]=='-'&&p1!=p2){   //遇到符号且不在首位且前面不为未知数的情况 
		    	memmove(temp,p1,p2-p1);
			    temp[p2-p1]='\0';
			    n1=n1+atoi(temp);
			    j++;
			    p1=p2;
			    p2++; 
			}
			else{
				p2++;
				j++;
			}
		}
    }
    if(n-n1==0) printf("%c=0.000",c);
    else printf("%c=%.3lf",c,(double)(n-n1)/(double)(m1-m));
} 
int main(){
	char s[101];
	scanf("%s",&s);
	solve(s);
}