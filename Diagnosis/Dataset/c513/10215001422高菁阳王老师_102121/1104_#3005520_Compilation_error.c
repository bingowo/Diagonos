#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a[1000];
	long long b['Z']={0};
	while(gets(a)！=NULL){
		int flag=1;
		switch(a[0]){
		case 'I':{
				int i=6;
				if(a[6]=='-'){
					flag=-1;
					i++;}
					b[a[3]]=0;
					for(;i<strlen(a);i++)
					b[a[3]]=10*b[a[3]]+a[i]-'0';
					b[a[3]]*=flag;break;}
		
		case'M':{
			if(a[2]=='V') {b[a[4]]=b[a[7]]; break;}
	        else if(a[2]=='L'){
	     	      if(strlen(a)>9) {b[a[4]]=b[a[7]]*b[a[10]];break;}
			      else {b[a[4]]*=b[a[7]];break;}}
		    else if(a[2]=='D'){
			      if(strlen(a)>9){b[a[4]]=b[a[7]]%b[a[10]];break;}
			      else {b[a[4]]%=b[a[7]];break;}
		           }
		       }
		
		case'A':if(a[1]=='D'){
			        if(strlen(a)>9) {b[a[4]]=b[a[7]]+b[a[10]];break;}
		 	        else {b[a[4]]+=b[a[7]];break;}}
			    if(a[1]=='N'){
			    	if(strlen(a)>9) {b[a[4]]=b[a[7]]&b[a[10]];break;}
			    	else {b[a[4]]=b[a[4]]&b[a[7]];break;} }
		
		case'S': if(strlen(a)>9){b[a[4]]=b[a[7]]-b[a[10]];break;}
		         else {b[a[4]]-=b[a[7]];break;}
		
		case'D': if(strlen(a)>9){b[a[4]]=b[a[7]]/b[a[10]];break;}
		        else {b[a[4]]/=b[a[7]];	break;}
		
		case'O':if(a[1]=='U'){printf("%lld\n",b[a[4]]);break;}
		        if(a[1]=='R'){if(strlen(a)>9){b[a[3]]=b[a[6]]|b[a[9]];break;}
		                      else{b[a[3]]=b[a[3]]|b[a[6]];break;}}
		                      
		case'X':if(a[1]=='O'){
		            if(strlen(a)>9){b[a[4]]=b[a[7]]^b[a[10]];break;} }
		            else{b[a[4]]=b[a[4]]^b[a[7]];break;}
		        if(a[1]=='C'){
		        	long long  t;
		        	t=b[a[5]];
		        	b[a[5]]=b[a[8]];
		        	b[a[8]]=t;break;
				}
	    default:break;
	}
}
	return 0;
}