#include <stdio.h>
#include <stdlib.h>

#define out 0
#define parenthese 3
#define bracket 2
#define brace 1

int main()
{
    short T=0;
    scanf("%hd",&T);getchar();
    for(int i=0;i<T;i++)
    {
        char *sequence;
        short state[3]={0},iselegant=1,len=0,cnt=0;
        sequence=(char*)malloc(101);
        sequence=fgets(sequence,105,stdin);
        if(!sequence) printf("error");
        len=strlen(sequence)-1;
        for(int j=0;j<len;j++)
        {
            switch(*(sequence+j))
            {
                case '(':
                    if(state[0]==brace||state[0]==parenthese) iselegant=0;
                    else
                    {
                        if(!state[0])
                        {
                            state[1]=cnt++;
                            state[2]=parenthese;
                        }
                        else if(state[2]==parenthese) cnt++;
                        state[0]=parenthese;
                    }
                    break;
                case '[':
                    if(state[0]==parenthese||state[0]==bracket) iselegant=0;
                    else
                    {
                        if(!state[0])
                        {
                            state[1]=cnt++;
                            state[2]=bracket;
                        }
                        else if(state[2]==bracket) cnt++;
                        state[0]=bracket;
                    }
                    break;
                case '{':
                    if(state[0]==brace||state[0]==bracket) iselegant=0;
                    else
                    {
                        if(!state[0])
                        {
                            state[1]=cnt++;
                            state[2]=brace;
                        }
                        else if(state[2]==brace) cnt++;
                        state[0]=brace;
                    }
                    break;
                case ')':
                    if(state[2]==parenthese) cnt--;
                    if(state[0]!=parenthese) iselegant=0;
                    else if(cnt==0)state[0]=out;
                    else state[0]=bracket;
                    break;
                case ']':
                    if(state[2]==bracket) cnt--;
                    if(state[0]!=bracket) iselegant=0;
                    else if(cnt==0)state[0]=out;
                    else state[0]=brace;
                    break;
                case '}':
                    if(state[2]==brace) cnt--;
                    if(state[0]!=brace) iselegant=0;
                    else if(cnt==0)state[0]=out;
                    else state[0]=parenthese;
                    break;
                default:
                    printf("wrong input");
            }

        }
        if(!iselegant||cnt)
            printf("No\n");
        else printf("Yes\n");
    }
}

