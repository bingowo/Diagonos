
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int RES[7]={-1};
char std[10][6]={"ZERO\0","ONE\0","TWO\0","THREE\0","FOUR\0","FIVE\0",
                "SIX\0","SEVEN\0","EIGHT\0","NINE\0"};
int cmp(const void *a,const void *b)
{
    return (int)(*(char*)a-*(char*)b);
}
void func(int *NL,int left,int pre)
{
    if(left==0) return;
    else
    {
        int maxflag=0;
        for(int i=0;i<10;i++)
        {
            int flag=0;
            for(int j=0;std[i][j]!='\0';j++) if(NL[std[i][j]-'A']==0){flag=1;maxflag=1;}
            if(flag==0)
            {
                int NNL[26];
                int j=0;
                for(int k=0;k<26;k++) NNL[k]=NL[k];
                for(j=0;std[i][j]!='\0';j++) NNL[std[i][j]-'A']--;
                RES[pre]=i;
                func(NNL,left-j,pre++);
            }
        }
        if(maxflag==0) for(int i=0;i<7;i++){RES[i]=-1;return;}
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
        NL[(int)(s[0]-'A')]=1;
        for(int i=1;i<len;i++)
        {
            if(s[i]==s[i-1]) NL[(int)(s[i-1]-'A')]++;
            else {NL[(int)(s[i]-'A')]++;}
        }
        func(NL,len,0);
        int m=0;
        while(RES[m]!=-1) printf("%d ",RES[m++]);
        printf("\n");
        free(NL);
    }
    return 0;
}