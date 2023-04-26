//one two three #four five #six seven #eight nine #zero
// o n e t w h r f u i v s x g h z 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int RES[7]={-1};
char std[10][6]={"ZERO\0","ONE\0","TWO\0","THREE\0","FOUR\0","FIVE\0",
                "SIX\0","SEVEN\0","EIGHT\0","NINE\0"};
int cmp(const void *a,const void *b)
{
    return (char*)a-(char*)b;
}
int* func(int *NL,int left,int pre)
{
    if(left==0){int *p=RES;return p;}
    else
    {
        int maxflag=0;
        for(int i=0;i<10;i++)
        {
            int flag=0;
            for(int j=0;std[i][j]!='\0';j++) if(NL[s[i][j]-'A']==0){flag=1;maxflag=1;}
            if(flag==0)
            {
                int NNL[26];
                strcpy(NNL,NL);
                for(int j=0;std[i][j]!='\0';j++) NNL[s[i][j]-'A']--;
                RES[pre]=i;
                func(NNL,left-j-1,pre++);
            }
        }
        if(maxflag==0) for(int i=0;i<7;i++) RES[i]=-1;
    }
}
int main()
{
    int count=0;
    scanf("%d",&count);
    for(int n=0;n<count;n++)
    {
        int *NL = (int*)malloc(26*sizeof(int));
        for(int i=0;i<26;i++) NL[i]=0;
        char s[21];
        scanf("%s",s);
        int len=(int)strlen(s);
        qsort(s,len,sizeof(char),cmp);
        int k=0;
        NL[(int)(s[k]-'A')]=1;
        for(int i=1;i<len;i++)
        {
            if(s[i]==s[i-1]) NL[(int)(s[k]-'A')]++;
            else {k++;NL[(int)(s[k]-'A')]++;}
        }
        func(NL,k+1,len);
    }
}