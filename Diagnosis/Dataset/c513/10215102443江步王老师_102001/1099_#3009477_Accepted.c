#include<stdio.h>
#include<string.h>
#define N 1001


char* code[128];

void init(char** code);
void output(char* t);
int main()
{
    
    init(code);
    int t;
    scanf("%d\n",&t);

    for (int i=0;i<t;++i)
    {
        char s[N];
        scanf("%s",s);
        char* p=s;
        char temp[10];
        int num=0;
        int cnt=0;

        printf("case #%d:\n",i);
        while (*p)
        {
            
            if ((*p) == '/')
            {
                temp[num]=0;
                //printf(temp);
                //putchar('\n');
                cnt=0;
                while ((*p) == '/') 
                {
                    cnt++;
                    p++;
                }
                output(temp);
                switch (cnt)
                {
                    case 1:
                        break;
                    case 3:
                        putchar(' ');
                        break;
                    case 5:
                        putchar('.');
                        break;
                }
                num=0;
            }
            
            else
            {
                temp[num++]=*p;
                p++;
            }
        }
        if (num != 0 )
        {
            temp[num]=0;
            output(temp);
            //printf("ok2");
        }
        putchar('\n');
    }
    return 0;
}

void output(char* t)
{
    int j;
    for (j='0';j<='9';++j)
    {
        if (strcmp(code[j],t)==0)
        {
            printf("%c",j);break;
        }
    }
    if (j>'9')
    {
        for (j='A';j<='Z';++j)
        {
            if (strcmp(code[j],t)==0)
            {
                printf("%c",j);break;
            }
        }
    }
    return;
}
void init(char** code)
{
    code['0']="-----";
    code['1']=".----";
    code['2']="..---";
    code['3']="...--";
    code['4']="....-";
    code['5']=".....";
    code['6']="-....";
    code['7']="--...";
    code['8']="---..";
    code['9']="----.";
    code['A']=".-";
    code['B']="-...";
    code['C']="-.-.";
    code['D']="-..";
    code['E']=".";
    code['F']="..-.";
    code['G']="--.";
    code['H']="....";
    code['I']="..";
    code['J']=".---";
    code['K']="-.-";
    code['L']=".-..";
    code['M']="--";
    code['N']="-.";
    code['O']="---";
    code['P']=".--.";
    code['Q']="--.-";
    code['R']=".-.";
    code['S']="...";
    code['T']="-";
    code['U']="..-";
    code['V']="...-";
    code['W']=".--";
    code['X']="-..-";
    code['Y']="-.--";
    code['Z']="--..";
    return;
}