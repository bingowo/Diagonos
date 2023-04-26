#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int T;
    scanf("%d",&T);
    char s[1100];
    char a[100][10]={['0']="-----",['1']=".----",['2']="..---",['3']="...--",['4']="....-",['5']=".....",['6']="-....",['7']="--...",['8']="---..",['9']="----.",['A']=".-",['B']="-...",['C']="-.-.",['D']="-..",['E']=".",['F']="..-.",['G']="--.",['H']="....",['I']="..",['J']=".---",['K']="-.-",['L']=".-..",\
    ['M']="--",['N']="-.",['O']="---",['P']=".--.",['Q']="--.-",['R']=".-.",['S']="...",['T']="-",['U']="..-",['V']="...-",['W']=".--",['X']="-..-",['Y']="-.--",['Z']="--.."};
    for(int cas=0;cas<T;cas++)
    {
        scanf("%s",s);
        char t[10];int k=0;int cnt=0;int flag=0;
        printf("case #%d:\n",cas);
        for(int i=0;i<=strlen(s);i++)
        {
            if(s[i]=='/' || s[i]=='\0')
            {
                if(flag==0)
                {
                     flag=1;
                     t[k++]='\0';
                     for(int m=0;m<100;m++)
                     {
                        if(strcmp(a[m],t)==0) printf("%c",m);
                     }
                     k=0;
                }
                cnt++;
            }
            else if(s[i]!='/')
            {
                t[k++]=s[i];
                flag=0;
                if(cnt==3) printf(" ");
                else if(cnt==5) printf(".");
                cnt=0;
            }

        }
        printf("\n");
    }
    return 0;
}
