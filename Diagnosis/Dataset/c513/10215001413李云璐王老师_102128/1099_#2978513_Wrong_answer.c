#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct {char x[10];int n;}p;
p b[36];


int main()
{
    int n;
    scanf("%d",&n);
    char ans[1000]={'\0'};
    for(int i=0;i<n;i++)
    {
        char s[1100];
        char a[1100][10];
        scanf("%s",s);
        char*p=s;int l=0;
        while(*p)
        {
            int m=0;
            while(*p!='/'&&*p!='\0')
            {

                a[l][m]=*p;
                m++;p++;

            }
            a[l][m]='\0';
            l++;
            if(*p=='/'&&*(++p)=='/')
            {
                p--;
                m=0;
                while(*p=='/'&&*p!='\0')
                    {

                        a[l][m]=*p;
                        m++;p++;
                    }
                    a[l][m]='\0';
                    l++;
            }


        }
        for(int d=0;d<l;d++)
            printf("%s\n",a[d]);

        char a2[38][6] = {
        {'-','-','-','-','-'},//0
        {'.','-','-','-','-'},//1
        {'.','.','-','-','-'},//2
        {'.','.','.','-','-'},//3
        {'.','.','.','.','-'},//4
        {'.','.','.','.','.'},//5
        {'-','.','.','.','.'},//6
        {'-','-','.','.','.'},//7
        {'-','-','-','.','.'},//8
        {'-','-','-','-','.'}, //9
        {'.','-'},//A
        {'-','.','.','.'},//B
        {'-','.','-','.'},//C
        {'-','.','.'},//D
        {'.'},//E
        {'.','.','-','.'},//F
        {'-','-','.'},//G
        {'.','.','.','.'},//H
        {'.','.'},//I
        {'.','-','-','-'},//J
        {'-','.','-'},//K
        {'.','-','.','.'},//L
        {'-','-'},//M
        {'-','.'},//N
        {'-','-','-'},//O
        {'.','-','-','.'},//P
        {'-','-','.','-'},//Q
        {'.','-','.'},//R
        {'.','.','.'},//S
        {'-'},//T
        {'.','.','-'},//U
        {'.','.','.','-'},//V
        {'.','-','-'},//W
        {'-','.','.','-'},//X
        {'-','.','-','-'},//Y
        {'-','-','.','.'}, //Z
        {'/','/','/'},//空格
        {'/','/','/','/','/'}//.
};
        for(int k=0;k<l;k++)
        {
            for(int e=0;e<38;e++)
                {if(strcmp(a[k],a2[e])==0)
            {if(e<=9) ans[k]=e+'0';
            if(e>9&&e<=35) ans[k]=e-10+'A';
            if(e==36) ans[k]=' ';
            if(e==37) ans[k]='.';}}
        }
        printf("case #%d:\n",i);
        for(int k=0;k<l;k++)
            printf("%c",ans[k]);









    }
    return 0;
}
