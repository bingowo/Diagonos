#include<stdio.h>
#include<string.h> 
#include<stdlib.h>

int main()
{
	char s[100]={0};
	int regs[200]={0};
	while(gets(s))
	{
		
		int len=strlen(s);
		char ist[100]={0},reg1[100]={0},reg2[100]={0},reg3[100]={0};
		int j1=0,j2=0,j3=0,j4=0,i=0;
		
		
			while(s[i]!=' '&&s[i]!='\0')//instruction
			{
				ist[j1++]=s[i];
				i++;
			}
		//	printf("ist:%s\n",ist);
			i++;
			while(s[i]!=','&&s[i]!='\0')//reg1
			{
				reg1[j2++]=s[i];
				i++;
			}
		//	printf("reg1:%s\n",reg1);
		
			i++;
			while(s[i]!=','&&s[i]!='\0')//reg2
			{
				reg2[j3++]=s[i];
				i++;
			}
		//	printf("reg2:%s\n",reg2);
			i++;
			while(s[i]!='\0')//reg3
			{
				reg3[j4++]=s[i];
				i++;
			}
		//	printf("reg3:%s\n",reg3);
		
		int flg=1;
		if(!strcmp(ist,"IN"))//reg1=寄存器，reg2=number 
		{
			int num=0;
			int k=0;
			if(reg2[k]=='-')flg=-1,k++;//一定要考虑数据范围正负问题！！！ 
			while(reg2[k]!='\0')
			{
				num*=10;
				num+=(reg2[k]-'0');
				k++;
			}	
			regs[reg1[0]]=num*flg;//AX=number
			//printf("TES:%d\n",regs[reg1[0]]);
		//	printf("num:%d\n",num);
		}
		if(!strcmp(ist,"MOV"))//每个寄存器里装的是一个数值 
		{
			regs[reg1[0]]=regs[reg2[0]];
		}
		if(!strcmp(ist,"XCHG"))
		{
			int temp=0;
			temp=regs[reg1[0]];
			regs[reg1[0]]=regs[reg2[0]];
			regs[reg2[0]]=temp;
		}
		if(!strcmp(ist,"ADD"))
		{
			if(strlen(reg3)>0)//3个寄存器形式 
			{
				regs[reg1[0]]=regs[reg2[0]]+regs[reg3[0]];
			} 
			else
			regs[reg1[0]]+=regs[reg2[0]];
		}
		if(!strcmp(ist,"SUB"))
		{
			if(strlen(reg3)>0)//3个寄存器形式 
			{
				regs[reg1[0]]=regs[reg2[0]]-regs[reg3[0]];
			}
			else
			regs[reg1[0]]-=regs[reg2[0]];
		}
		if(!strcmp(ist,"MUL"))
		{
			if(strlen(reg3)>0)//3个寄存器形式 
			{
				regs[reg1[0]]=regs[reg2[0]]*regs[reg3[0]];
			}
			else
			regs[reg1[0]]*=regs[reg2[0]];
		}
		if(!strcmp(ist,"DIV"))
		{
			if(strlen(reg3)>0)//3个寄存器形式 
			{
				regs[reg1[0]]=regs[reg2[0]]/regs[reg3[0]];
			}
			else
			regs[reg1[0]]/=regs[reg2[0]];
		}
		if(!strcmp(ist,"MOD"))
		{
			if(strlen(reg3)>0)//3个寄存器形式 
			{
				regs[reg1[0]]=regs[reg2[0]]%regs[reg3[0]];
			}
			else
			regs[reg1[0]]%=regs[reg2[0]];
		}
		if(!strcmp(ist,"AND"))
		{
			if(strlen(reg3)>0)//3个寄存器形式 
			{
				regs[reg1[0]]=regs[reg2[0]]&regs[reg3[0]];
			}
			else
			regs[reg1[0]]&=regs[reg2[0]];
		}
		if(!strcmp(ist,"OR"))
		{
			if(strlen(reg3)>0)//3个寄存器形式 
			{
				regs[reg1[0]]=regs[reg2[0]]|regs[reg3[0]];
			}
			else
			regs[reg1[0]]|=regs[reg2[0]];
		}
		if(!strcmp(ist,"XOR"))
		{
			if(strlen(reg3)>0)//3个寄存器形式 
			{
				regs[reg1[0]]=regs[reg2[0]]^regs[reg3[0]];
			}
			else
			regs[reg1[0]]^=regs[reg2[0]];
		}
		if(!strcmp(ist,"OUT"))
		{
			printf("%d\n",regs[reg1[0]]);
		}
	 }
	 return 0; 
}