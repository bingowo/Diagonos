#include<string.h>
#include<stdio.h>
int dic[52];
void readstr(char *s,int *res)
{
    while(*s)
    {
        if(*s>='a')
        {
            if(res[*s-'a'+26]==0)res[*s-'a'+26]=1;
            s++;
        }
        else
        {
            if(res[*s-'A']==0)res[*s-'A']=1;
            s++;
        }
    }
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
    char alpha[52]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int i,j,T;
    int cnt=0;
    scanf("%d",&T);
    while(T)
    {
        char input[16];
        char character[16]= {'\0'};
        printf("case #%d: \n",cnt);
        for(i=0; i<52; i++)
        {
            dic[i]=0;
        }
        scanf("%s",input);
        readstr(input,dic);
        for(i=0,j=0; i<52; i++)
        {
            if(dic[i]==1)
            {
                character[j++]=alpha[i];
            }
        }
        int len=strlen(character);
       
		int k=0;
            comb(character,depth,k);
        
        cnt++,T--;
    }
    return 0;
}