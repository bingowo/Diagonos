#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a[100];
	int b['E']={0};
	while(gets(a)){
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
		case'M':{if(a[i]=='O') 
				{b[a[4]]=b[a[7]]; break;}
	             else {b[a[4]]*=b[a[7]];break;	}
	     }
		case'A':{b[a[4]]+=b[a[7]];break;}
		case'S':{b[a[4]]-=b[a[7]];break;}
		case'D':{b[a[4]]/=b[a[7]];	break;}
		case'O':{printf("%d\n",b[a[4]]);break;}
		}
	}
	return 0;
}