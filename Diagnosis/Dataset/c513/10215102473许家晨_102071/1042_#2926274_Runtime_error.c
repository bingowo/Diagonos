#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
	return *(char*)a-*(char*)b;
}

char char_comb[17]="";
int depth=0;
void comb(char* s,int depth,int k)
{
    if(depth)printf("%s\n",char_comb);
    for(int i=k; s[i]; i++)
    {
        char_comb[depth]=s[i];
        char_comb[depth+1]=0;
        comb(s,depth+1,i+1);
    }
}
int main()
{
    int i,j,T;
    int cnt=0;
    scanf("%d",&T);
    while(T)
    {
        char input[16];
        char character[17]= {'\0'};
        printf("case #%d: \n",cnt);
        scanf("%s",input);
        qsort(input,strlen(input),sizeof(char),cmp);
        char* p1=input;
        character[0]=input[0];
        char* p2=input+1;
        int i=1;
        while(*p2){
        	if(*p1==*p2)p2++;
        	else{
        		*(p1+1)=*p2;
        		character[i]=*p2;
        		p1++;p2++;
        		i++;
			}
		}
		

        int k=0;
        comb(character,depth,k);
        cnt++,T--;
    }
    return 0;
}