#include <stdio.h>
#include <string.h>
char *op[] = {"IN","OUT","MOV","XCHG","ADD","SUB","MUL","DIV","MOD","AND","OR","XOR"};
long long save[30] = {0};
int main()
{
	char s[30] = {0};
	while(gets(s)){
		int len = strlen(s);
		int space = 0;
		while(space<len && s[space]!=' ') space++;
		char t[30] = {0};
		strncpy(t,s,space);
		int opt;
		for(int i=0;i<12;i++){
			if(strcmp(t,op[i])==0)
				opt = i;
		}
		int pos1,pos2,pos3,flag = 0;
		long long temp = 0;
		switch(opt)
		{
			case 0:
				pos1 = s[space+1]-'A';
				space = 0;
				while(space<len && s[space]!=',') space++;
				save[pos1] = 0;
				while(space<len-1){
					if(s[space+1]=='-'){
						flag = 1;
						space++;
						continue;
					}
					save[pos1] *= 10;
					space++;
					save[pos1] += s[space] - '0';
				}
				if(flag) save[pos1] *= -1;
				break;
			case 1:
				pos1 = s[space+1]-'A';
				printf("%d\n",save[pos1]);
				break;
			case 2:
				pos1 = s[space+1]-'A';
				space = 0;
				while(space<len && s[space]!=',') space++;
				pos2 = s[space+1]-'A';
				save[pos1] = save[pos2];
				break;
			case 3:
				pos1 = s[space+1]-'A';
				space = 0;
				while(space<len && s[space]!=',') space++;
				pos2 = s[space+1]-'A';
				temp = save[pos1];
				save[pos1] = save[pos2];
				save[pos2] = temp;
				break;
			case 4:
				pos1 = s[space+1]-'A';
				space = 0;
				while(space<len && s[space]!=',') space++;
				pos2 = s[space+1]-'A';
				space++;
				while(space<len && s[space]!=',') space++;
				if(space==len) save[pos1] += save[pos2];
				else{
					pos3 = s[space+1]-'A';
					save[pos1] = save[pos2]+save[pos3];
				}
				break;
			case 5:
				pos1 = s[space+1]-'A';
				space = 0;
				while(space<len && s[space]!=',') space++;
				pos2 = s[space+1]-'A';
				space++;
				while(space<len && s[space]!=',') space++;
				if(space==len) save[pos1] -= save[pos2];
				else{
					pos3 = s[space+1]-'A';
					save[pos1] = save[pos2]-save[pos3];
				}
				break;
			case 6:
				pos1 = s[space+1]-'A';
				space = 0;
				while(space<len && s[space]!=',') space++;
				pos2 = s[space+1]-'A';
				space++;
				while(space<len && s[space]!=',') space++;
				if(space==len) save[pos1] *= save[pos2];
				else{
					pos3 = s[space+1]-'A';
					save[pos1] = save[pos2]*save[pos3];
				}
				break;
			case 7:
				pos1 = s[space+1]-'A';
				space = 0;
				while(space<len && s[space]!=',') space++;
				pos2 = s[space+1]-'A';
				space++;
				while(space<len && s[space]!=',') space++;
				if(space==len) save[pos1] /= save[pos2];
				else{
					pos3 = s[space+1]-'A';
					save[pos1] = save[pos2]/save[pos3];
				}
				break;
			case 8:
				pos1 = s[space+1]-'A';
				space = 0;
				while(space<len && s[space]!=',') space++;
				pos2 = s[space+1]-'A';
				space++;
				while(space<len && s[space]!=',') space++;
				if(space==len) save[pos1] %= save[pos2];
				else{
					pos3 = s[space+1]-'A';
					save[pos1] = save[pos2]%save[pos3];
				}
				break;
			case 9:
				pos1 = s[space+1]-'A';
				space = 0;
				while(space<len && s[space]!=',') space++;
				pos2 = s[space+1]-'A';
				space++;
				while(space<len && s[space]!=',') space++;
				if(space==len) save[pos1] &= save[pos2];
				else{
					pos3 = s[space+1]-'A';
					save[pos1] = (save[pos2]&save[pos3]);
				}
				break;
			case 10:
				pos1 = s[space+1]-'A';
				space = 0;
				while(space<len && s[space]!=',') space++;
				pos2 = s[space+1]-'A';
				space++;
				while(space<len && s[space]!=',') space++;
				if(space==len) save[pos1] |= save[pos2];
				else{
					pos3 = s[space+1]-'A';
					save[pos1] = (save[pos2]|save[pos3]);
				}
				break; 
			case 11:
				pos1 = s[space+1]-'A';
				space = 0;
				while(space<len && s[space]!=',') space++;
				pos2 = s[space+1]-'A';
				space++;
				while(space<len && s[space]!=',') space++;
				if(space==len) save[pos1] ^= save[pos2];
				else{
					pos3 = s[space+1]-'A';
					save[pos1] = (save[pos2]^save[pos3]);
				}
				break;
		}
	}
	return 0;
}