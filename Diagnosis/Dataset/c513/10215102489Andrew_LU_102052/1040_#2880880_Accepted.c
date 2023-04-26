#include<stdio.h>
#include<string.h>
int main(){
	int i;
	char f[2][15],m[15],c[15];
	scanf("%s%s%s",f[0],f[1],c);
	for(i=0;i<=1;i++){
		if(f[i][0]=='?'){
			if(f[1-i][0]=='A' && f[1-i][1]!='B'){
				if(c[0]=='A' && c[1]!='B'){//     AA AO AA AO
					strcpy(f[i],"{A,AB,B,O}");
				}
				if(c[0]=='A' && c[1]=='B'){ //    Ao AA   B  
					strcpy(f[i],"{AB,B}");
				}
				if(c[0]=='B'){
					strcpy(f[i],"{AB,B}");
				}
				if(c[0]=='O'){
					strcpy(f[i],"{A,B,O}");
				}
			}
			if(f[1-i][0]=='A' && f[1-i][1]=='B'){
				if(c[0]=='A' && c[1]!='B'){//     AA AO AA AO
					strcpy(f[i],"{A,AB,B,O}");
				}
				if(c[0]=='A' && c[1]=='B'){ //    Ao AA   B  
					strcpy(f[i],"{A,AB,B}");
				}
				if(c[0]=='B'){
					strcpy(f[i],"{A,AB,B,O}");
				}
				if(c[0]=='O'){
					strcpy(f[i],"impossible");
				}
			}
			if(f[1-i][0]=='B'){
				if(c[0]=='A' && c[1]!='B'){//     AA AO AA AO
					strcpy(f[i],"{A,AB}");
				}
				if(c[0]=='A' && c[1]=='B'){ //    Ao AA   B  
					strcpy(f[i],"{A,AB}");
				}
				if(c[0]=='B'){
					strcpy(f[i],"{A,AB,B,O}");
				}
				if(c[0]=='O'){
					strcpy(f[i],"{A,B,O}");
				}
			}
			if(f[1-i][0]=='O'){
				if(c[0]=='A' && c[1]!='B'){ //     AA AO AA AO
					strcpy(f[i],"{A,AB}");
				}
				if(c[0]=='A' && c[1]=='B'){ //    Ao AA   B  
					strcpy(f[i],"impossible");
				}
				if(c[0]=='B'){
					strcpy(f[i],"{AB,B}");
				}
				if(c[0]=='O'){
					strcpy(f[i],"{A,B,O}");
				}
			}
			if(f[i][0]=='?') strcpy(f[i],"impossible");
		}
	}
	if(c[0]=='?'){
		for(i=0;i<=1;i++){
			if(f[i][0]=='O' && f[1-i][0]=='O')
			 strcpy(c,"{O}");
			if(f[i][0]=='A' && f[1-i][0]=='O' && f[i][1]!='B'){
				strcpy(c,"{A,O}");
			}
			if(f[i][0]=='A' && f[1-i][0]=='A' && f[i][1]!='B' && f[1-i][1]!='B') {
				strcpy(c,"{A,O}");
			}
			if(f[i][0]=='A' && f[1-i][0]=='B' && f[i][1]!='B')
			 strcpy(c,"{A,AB,B,O}");
			if(f[i][0]=='A' && f[1-i][0]=='A' && f[i][1]!='B' && f[1-i][1]=='B'){
				strcpy(c,"{A,AB,B}");
			}
			if(f[i][0]=='B' && f[1-i][0]=='O'){
				strcpy(c,"{B,O}");
			}
			if(f[i][0]=='B' && f[1-i][0]=='B'){
				strcpy(c,"{B,O}");
			}
			if(f[i][0]=='B' && f[1-i][0]=='O'){
				strcpy(c,"{B,O}");
			}
			if(f[i][0]=='B' && f[1-i][0]=='A' && f[1-i][1]=='B'){
				strcpy(c,"{A,AB,B}");
			}
			//printf("f=%c%c,m=%c\n",f[i][0],f[i][1],f[1][0]);
			if(f[i][0]=='A' && f[1-i][0]=='O' && f[i][1]=='B'){
			//	printf("?"); 
				strcpy(c,"{A,B}");
			}
			if(f[i][0]=='A' && f[1-i][0]=='A' && f[i][1]=='B' && f[1-i][1]=='B') {
				strcpy(c,"{A,AB,B}");
			}
		}
	}
	printf("%s %s %s",f[0],f[1],c);
}