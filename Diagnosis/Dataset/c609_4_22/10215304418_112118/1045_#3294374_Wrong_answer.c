#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char c;
	int f=0;
	while ((c=getchar())!=EOF){
		x:
		if (f==0){
			if (c=='\'') {
				f=1;
				printf("%c",c);
			}
			else if (c=='/'){
				char cc;
				cc=getchar();
				if (cc=='*'){
					f=2;
				}
				else if (cc=='/'){
					f=3;
				}
				else{
                    printf("%c%c",c,cc);
				}
			}
			else if (c=='\"'){
				f=4;
				printf("%c",c);
			}
			else {
				printf("%c",c);
			}
		}
		else if (f==1){
			if (c=='\\'){
				char cc;
				cc=getchar();
                printf("%c%c",c,cc);
			}
			else if (c=='\''){
				printf("%c",c);
				f=0;
			}
			else printf("%c",c);
		}
		else if (f==2){
			if (c=='*'){
				char cc;
				cc=getchar();
				if (cc=='/'){
					f=0;
				}
				else {
					c=cc;
					goto x;
				}
			}
		}
		else if (f==3){
			if (c=='\n'){
				f=0;
				printf("%c",c);
			}
		}
		else if (f==4){
			if (c=='\\'){
				char cc;
				cc=getchar();
                printf("%c%c",c,cc);
			}
			else if (c=='\"'){
				f=0;
				printf("%c",c);
			}
			else {
				printf("%c",c);
			}
		}
		printf("%d",f);
	}
	return 0;
}
