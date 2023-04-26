#include<stdio.h>
#include<string.h>
typedef struct{
	char ch;
	char str[8];
}MAP;

MAP map[38]= {
	{' ',"/"},{'.',"///"},
	{'0',"-----"},{'1',".----"},{'2',"..---"},{'3', "...--"},{'4',"....-"},
	{'5',"....."},{'6',"-...."},{'7',"--..."},{'8',"---.."},{'9',"-----."},
	{'A',".-"},{'B',"-..."},{'C',"-.-."},{'D',"-.."},{'E',"."},{'F',"..-."},
	{'G',"--."},{'H',"...."},{'I',".."},{'J',".---"},{'K',"-.-"},{'L',".-.."},
	{'M',"--"},{'N',"-."},{'O',"---"},{'P',".--."},{'Q',"--.-"},{'R',".-."},
	{'S',"..."},{'T',"-"},{'U',"..-"},{'V',"...-"},{'W',".--"},{'X',"-..-"},
	{'Y',"-.--"},{'Z',"--.."}
};
	
int match(char a[]){
	for(int i=0;i<38;i++){
		if(strcmp(map[i].str,a)==0)
			return map[i].ch;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
	printf("case #%d:\n",k);
	char s[1010];
	scanf("%s",s);	
	char ch[8];
	int type=0;
	int a = 0;
	int ret;
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='.'||s[i]=='-'){
			type = 0;ch[a++] = s[i];
			continue;
		}			
		if(type==0&&s[i]=='/'){
			ch[a] = '\0';
			a = 0;
			printf("%c",match(ch));
			type = 1;continue;			
		}
		if(type==1&&s[i]=='/'){
			if(s[i+1]!='/'){
				type=0;
				ch[a] = '\0';
				a = 0;
				printf("%c",match(ch));
				continue;
			}else
				ch[a++] = s[i];
		}		
	}
	ch[a] = '\0';
	printf("%c\n",match(ch));
}
	 
	return 0;
}