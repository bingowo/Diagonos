#include <stdio.h>
#include <string.h>

int main()
{
	int t,w;
	scanf("%d",&t);
	for(w=0;w<t;w++)
	{
		char s[100][10];
	
		strcpy(s['A'],".-");
		strcpy(s['B'],"-...");
		strcpy(s['C'],"-.-.");strcpy(s['9'],"----.");
		strcpy(s['D'],"-..");strcpy(s['8'],"---..");
		strcpy(s['E'],".");strcpy(s['7'],"--...");
		strcpy(s['F'],"..-.");strcpy(s['6'],"-....");
		strcpy(s['G'],"--.");strcpy(s['5'],".....");
		strcpy(s['H'],"....");strcpy(s['4'],"....-");
		strcpy(s['I'],"..");strcpy(s['3'],"...--");
		strcpy(s['J'],".---");strcpy(s['2'],"..---");
		strcpy(s['K'],"-.-");strcpy(s['1'],".----");
		strcpy(s['L'],".-..");strcpy(s['0'],"-----");
		strcpy(s['M'],"--");strcpy(s['Z'],"--..");
		strcpy(s['N'],"-.");strcpy(s['Y'],"-.--");
		strcpy(s['O'],"---");strcpy(s['X'],"-..-");
		strcpy(s['P'],".--.");strcpy(s['W'],".--");
		strcpy(s['Q'],"--.-");strcpy(s['V'],"...-");
		strcpy(s['R'],".-.");strcpy(s['U'],"..-");
		strcpy(s['S'],"...");strcpy(s['T'],"-");
		char get[1001][10];
		memset(get,'\0',sizeof(get));//清空数组 
		char f[1001][10],c;
		memset(f,'\0',sizeof(f));
		int h=0,l=0,h1=0,l2=0;
		fflush(stdin);
		scanf("%c",&c);
		while(c!='\n')
		{
			
			while(c!='/'&&c!='\n')
			{
				get[h][l++]=c;
				scanf("%c",&c);
				
			}
			
			h++;
			l=0;
			while(c=='/'&&c!='\n')
			{
				f[h1][l2++]=c;
				scanf("%c",&c);
			}
			h1++;
			l2=0;
		}
		printf("%c\n",get[4][3]);
		printf("case #%d:\n",w);
		
		int j=0;
		for(j;j<h;j++)
		{
			int k=0;
			for(k;k<100;k++)
			{
	
				if(strcmp(get[j],s[k])==0)
				{
		
					printf("%c",k);
				}
			}
			if(strlen(f[j])==1) continue;
			else if(strlen(f[j])==3) printf(" ");
			else if(strlen(f[j])==5) printf(".");	
		}
		
		printf("\n");
	
	}
	return 0;
}