#include<stdio.h>
#include<stdlib.h>

char st[1234567];
int f[123456];
int len=0;
int anslen=0;
int ansi=0;

int main(){
    scanf("%s",st);
    for (int i=0;i<=150;i++)
        f[i]=-1;
	for (int i=0;i<strlen(st);i++){
        if (f[st[i]]==-1){
            len++;
            f[st[i]]=i;
            if (anslen<len){
                anslen=len;
                ansi=i-len+1;
            }
        }
        else {
            len=i-f[st[i]];
            f[st[i]]=i;
        }
	}
	for (int i=ansi;i<ansi+anslen;i++){
        printf("%c",st[i]);
	}
	printf("\n");
	return 0;
}
