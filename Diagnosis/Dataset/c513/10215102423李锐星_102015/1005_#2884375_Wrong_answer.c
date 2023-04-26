#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d",&T);
	int i,numbers,len,digit,j,temp;
	char Octal[55],demical[155];
	for (i=0;i<T;i++){
		scanf("%s",Octal);
		numbers=0;
		len=strlen(Octal)-1;
		for (;len!=1;--len){
			digit=Octal[len]-'0';
			j=0;
			do{
				if (j<numbers)
				{
					temp=digit*10+demical[j]-'0';
				}
				else{
					temp=digit*10;
				}
				demical[j++]=temp/8+'0';
				digit=temp%8;
			}while(digit!=0||j<numbers);
			numbers=j;
		}
		demical[numbers]='\0';
		printf("0.");
		for (j=0;j<strlen(demical);j++){
			printf("%c",demical[j]);
		}
		printf("\n");
	}
	return 0;
}