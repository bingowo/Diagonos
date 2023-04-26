#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int s[4][4][4] ={1,0,0,1, 1,1,1,1, 1,1,1,0, 1,0,0,1,
                        1,1,1,1,  0,1,0,1, 1,1,1,0 ,0,1,0,1
                        ,1,1,1,0, 1,1,1,0,  1,1,1,0, 1,1,0,0,
                         1,0,0,1, 0,1,0,1,  1,1,0,0, 0,0,0,1};
const char blood[4][4] = {"A","B","AB","O"};
int read()
{
    char s[10];
    scanf("%s",s);
    if(strcmp(s,"A")==0)return 0;
    else if(strcmp(s,"B")==0)return 1;
    else if(strcmp(s,"AB")==0)return 2;
    else if(strcmp(s,"O")==0)return 3;
    else return -1;
}
void print(int p1,int p2,int flag)
{
    if(flag)//儿子不知道的状况
    {
        printf("{");
        for(int a =0;a<4;a++)
        {
            if(s[p1][p2][a])printf("%s,",blood[a]);
        }
        printf("\b}");

    }
    else
    {
        int flag = 1;//判断有无该血型
        printf("{");
        for(int z= 0;z < 4;z++)
        {
            if(s[p1][z][p2])
            {
                printf("%s,",blood[z]);
                flag = 0;
            }
        }
        if(flag)printf("\bimpossible ");
        else printf("\b} ");



    }
}
int main()
{
int a,b,c;//依次为爸爸妈妈儿子
a = read();
b = read();
c = read();
if(a == -1)
{
    print(b,c,0);
}
else printf("%s ",blood[a]);
if(b == -1)
{
 print(a,c,0);
}
else printf("%s ",blood[b]);

if(c == -1)
{
        print(a,b,1);
}
else
{
printf("%s ",blood[c]);
}
return 0;

}
