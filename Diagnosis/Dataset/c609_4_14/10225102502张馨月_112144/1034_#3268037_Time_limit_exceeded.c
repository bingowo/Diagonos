#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(char table[16],char c)
{
    int count;
    //char table[]={"0123456789abcdef"};
    for(int i=0;i<16;i++){
        count=0;
        if(table[i]==c){
            return 1;
            count =1;
            break;
        }
    }
    if(count==0)
        return 0;
}

int main()
{
     char*p=(char*)malloc(10000*sizeof(char));
     char table[]={"0123456789abcdef"};
    //scanf("%s",&p);
    char c1,c2,c3;
    int count=0;
    int num=0;

    c1=getchar();
    c2=getchar();
    while(c2!='\n')
{
    if(c1=='0'&&c2=='x')
    {
        //printf("%c%c",c1,c2);
        c3=getchar();
        if(c3=='\n')
            break;
        //if(c3=='\n'&&num==0)
        //    printf("-1");
        //    return 0;
        if(find(table,c3)==0)
        {
            c1=getchar();
            c2=getchar();
            continue;
        }
        int i=0;
        while(find(table,c3))
        {
            //printf("%c",c3);

            p[i]=c3;
            i++;
            c3=getchar();
            num++;
        }

        unsigned int ans=0;//d为十进制数
        int j=strlen(p)-1;
        int k;
        for(k=0;k<=j;k++)
        {
            if(p[k]<='9'&&p[k]>='0')
            {
                ans=ans*16+p[k]-'0';
            }
            else if(p[k]<='f'&&p[k]>='a')
            {
                ans=ans*16+10+p[k]-'a';
            }else{break;}
        }

        if(num==0) printf("-1");
        else printf("%u ",ans);
        c1=getchar();
        c2=getchar();

    }else{
        c1=c2;
        c2=getchar();
    }

}
if(num==0) printf("-1");
free(p);
    return 0;
}