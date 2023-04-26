#include <iostream>
#include <sstream> 
#include<string>
#include<string.h>
using namespace std;
void solve(){
	int m,k,r,p,i,res;
	cin>>m;
	int m1=m;
	char c=getchar();
	string s;
	getline(cin,s);	
	istringstream sin{s};
	string word,s1;
	int num=0;
	int num1=0;
	char s2[2000][2000];
	int s3[200];
	while(sin>>word){
		s1+=word;
		s1+=" ";		
	}
	int j=0;
	for(i=0;i<s1.length();i++){
		if(s1[i]!=' '){
			s2[num1][j]=s1[i];
			j++;
		}
		else{
			s2[num1][j]='\0';
			s3[num1]=j;
			num1++;
			j=0;
		}
	}
	s[num1]='\0';
	num=0;
	for(i=0;i<=num1;i++){
		if(s3[i]<=m1-num){
			m1=m1-s3[i];
			num+=1;
		}else{
		    if(m1%num==0){
		        k=m1/num;
		        p=m1/num;
		        res=-1;
		    }else if((m+1)%num==0){
		        k=(m+1)/num-1;
		        p=(m+1)/num;
		        res=1;
		    }else if((m-1)%num==0){
		        k=(m-1)/num;
		        p=(m-1)/num+1;
		        res=0;
		    }
			if(i-num==0){
				for(j=i-num;j<i;j++){
					printf("%s",s2[j]);								
				}	
			}else{
				for(j=i-num+1;j<i;j++){
					printf("%s",s2[j]);								
				}	
			}
					
			printf("\n");
			printf("%s",s2[j]);
			num=1;
			m1=m-s3[i];
		}
	}
	if(num1!=0) printf(" ");
	printf("%s",s2[num1-1]);
	printf("\n");
}
int main(int argc,char**argv)
{  int i,t;  std::cin >> t; std::cin.get();
   for (i=0;i<t;i++)
   { std::cout << "case #" << i << ":" << std::endl;  solve(); }
   return 0;
}