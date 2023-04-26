#include<stdio.h>
#include<string.h>
int main()
{
	int a=0,b=0,c=0,d=0;
	char cmd[5];
	char R1[5],R2[5];
	while(scanf("%s",cmd)!=EOF){
		//IN
		if(strcmp(cmd,"IN")==0){			
			scanf("%2s,",R1);
			if(strcmp(R1,"AX")==0)
				scanf("%d",&a);
			else if(strcmp(R1,"BX")==0)
				scanf("%d",&b);
			else if(strcmp(R1,"CX")==0)
				scanf("%d",&c);
			else if(strcmp(R1,"DX")==0)
				scanf("%d",&d);	
		}
		//MOV
		if(strcmp(cmd,"MOV")==0){			
			scanf("%2s,%2s",R1,R2);
			if(strcmp(R1,"AX")==0){
				if(strcmp(R2,"BX")==0)
					a=b;
				else if(strcmp(R2,"CX")==0)
					a=c;
				else if(strcmp(R2,"DX")==0)
					a=d;
			}
			else if(strcmp(R1,"BX")==0){
				if(strcmp(R2,"AX")==0)
					b=a;
				else if(strcmp(R2,"CX")==0)
					b=c;
				else if(strcmp(R2,"DX")==0)
					b=d;
			}
			else if(strcmp(R1,"CX")==0){
				if(strcmp(R2,"AX")==0)
					c=a;
				else if(strcmp(R2,"BX")==0)
					c=b;
				else if(strcmp(R2,"DX")==0)
					c=d;
			}
		}
		//ADD
		else if(strcmp(cmd,"ADD")==0){			
			scanf("%2s,%2s",R1,R2);
			if(strcmp(R1,"AX")==0){
				if(strcmp(R2,"BX")==0)
					a+=b;
				else if(strcmp(R2,"CX")==0)
					a+=c;
				else if(strcmp(R2,"DX")==0)
					a+=d;				
			}
			else if(strcmp(R1,"BX")==0){
				if(strcmp(R2,"AX")==0)
					b+=a;
				else if(strcmp(R2,"CX")==0)
					b+=c;
				else if(strcmp(R2,"DX")==0)
					b+=d;
			}
			else if(strcmp(R1,"CX")==0){
				if(strcmp(R2,"AX")==0)
					c+=a;
				else if(strcmp(R2,"BX")==0)
					c+=b;
				else if(strcmp(R2,"DX")==0)
					c+=d;
			}
			else if(strcmp(R1,"DX")==0){
				if(strcmp(R2,"AX")==0)
					d+=a;
				else if(strcmp(R2,"BX")==0)
					d+=b;
				else if(strcmp(R2,"CX")==0)
					d+=c;
			}
		}
		//SUB
		else if(strcmp(cmd,"SUB")==0){			
			scanf("%2s,%2s",R1,R2);
			if(strcmp(R1,"AX")==0){
				if(strcmp(R2,"BX")==0)
					a-=b;
				else if(strcmp(R2,"CX")==0)
					a-=c;
				else if(strcmp(R2,"DX")==0)
					a-=d;				
			}
			else if(strcmp(R1,"BX")==0){
				if(strcmp(R2,"AX")==0)
					b-=a;
				else if(strcmp(R2,"CX")==0)
					b-=c;
				else if(strcmp(R2,"DX")==0)
					b-=d;
			}
			else if(strcmp(R1,"CX")==0){
				if(strcmp(R2,"AX")==0)
					c-=a;
				else if(strcmp(R2,"BX")==0)
					c-=b;
				else if(strcmp(R2,"DX")==0)
					c-=d;
			}
			else if(strcmp(R1,"DX")==0){
				if(strcmp(R2,"AX")==0)
					d-=a;
				else if(strcmp(R2,"BX")==0)
					d-=b;
				else if(strcmp(R2,"CX")==0)
					d-=c;
			}
		}
		//MUL
		else if(strcmp(cmd,"MUL")==0){			
			scanf("%2s,%2s",R1,R2);
			if(strcmp(R1,"AX")==0){
				if(strcmp(R2,"BX")==0)
					a*=b;
				else if(strcmp(R2,"CX")==0)
					a*=c;
				else if(strcmp(R2,"DX")==0)
					a*=d;				
			}
			else if(strcmp(R1,"BX")==0){
				if(strcmp(R2,"AX")==0)
					b*=a;
				else if(strcmp(R2,"CX")==0)
					b*=c;
				else if(strcmp(R2,"DX")==0)
					b*=d;
			}
			else if(strcmp(R1,"CX")==0){
				if(strcmp(R2,"AX")==0)
					c*=a;
				else if(strcmp(R2,"BX")==0)
					c*=b;
				else if(strcmp(R2,"DX")==0)
					c*=d;
			}
			else if(strcmp(R1,"DX")==0){
				if(strcmp(R2,"AX")==0)
					d*=a;
				else if(strcmp(R2,"BX")==0)
					d*=b;
				else if(strcmp(R2,"CX")==0)
					d*=c;
			}
		}
		//DIV
		else if(strcmp(cmd,"DIV")==0){			
			scanf("%2s,%2s",R1,R2);
			if(strcmp(R1,"AX")==0){
				if(strcmp(R2,"BX")==0)
					a/=b;
				else if(strcmp(R2,"CX")==0)
					a/=c;
				else if(strcmp(R2,"DX")==0)
					a/=d;				
			}
			else if(strcmp(R1,"BX")==0){
				if(strcmp(R2,"AX")==0)
					b/=a;
				else if(strcmp(R2,"CX")==0)
					b/=c;
				else if(strcmp(R2,"DX")==0)
					b/=d;
			}
			else if(strcmp(R1,"CX")==0){
				if(strcmp(R2,"AX")==0)
					c/=a;
				else if(strcmp(R2,"BX")==0)
					c/=b;
				else if(strcmp(R2,"DX")==0)
					c/=d;
			}
			else if(strcmp(R1,"DX")==0){
				if(strcmp(R2,"AX")==0)
					d/=a;
				else if(strcmp(R2,"BX")==0)
					d/=b;
				else if(strcmp(R2,"CX")==0)
					d/=c;
			}
		}
		//OUT
		else if(strcmp(cmd,"OUT")==0){			
			scanf("%2s,",R1);
			if(strcmp(R1,"AX")==0)
				printf("%d\n",a);
			else if(strcmp(R1,"BX")==0)
				printf("%d\n",b);
			else if(strcmp(R1,"CX")==0)
				printf("%d\n",c);
			else if(strcmp(R1,"DX")==0)
				printf("%d\n",d);	
		}
		
	} 
	
	return 0;
}