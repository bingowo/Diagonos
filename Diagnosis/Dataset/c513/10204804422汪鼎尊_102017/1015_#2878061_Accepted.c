#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int primes[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113};

int main()
{
	int input1[30],input2[30];
	int i=0,j=0,len=0;
	int cases,c;
	char ch;
	scanf("%d",&cases);
	
	for(c=0;c<cases;c++)
	{
		memset(input1,0,30*sizeof(int));
		memset(input2,0,30*sizeof(int));
		while(1){
			scanf("%d",&j);
			for(i=29;i>0;i--)input1[i]=input1[i-1];
			input1[0]=j;
			i++;
			scanf("%c",&ch);
			if(ch==' ')break;
		}
		i=0;
		while(1){
			scanf("%d",&j);
			for(i=29;i>0;i--)input2[i]=input2[i-1];
			input2[0]=j;
			i++;
			scanf("%c",&ch);
			if(ch=='\n'||ch=='\0')break;
		}
		for(i=0;i<29;i++)input1[i]=input1[i]+input2[i];
		for(i=0;i<29;i++)if(input1[i]>=primes[i])
		{
			input1[i]=input1[i]-primes[i];
			input1[i+1]++;
		}
		
		printf("case #%d:\n",c);//printf("%d %d %d\n",input1[0],input1[1],input1[2]);
		for(i=29;input1[i]==0;i--);
		for(;i>=1;i--)printf("%d,",input1[i]);
		printf("%d",input1[0]);
		if(c!=cases-1)putchar('\n');
	}
	
	
	
	
	//for(len--;len>=0;len--)putchar(result[len]);
	return 0;
}