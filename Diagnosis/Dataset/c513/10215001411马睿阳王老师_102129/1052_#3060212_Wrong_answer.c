#include<stdio.h>
#include<string.h>

typedef struct
{
    char ch;int num;
}alph;

int cmp(const void*a,const void*b)
{
    int c=*(int*)a;
    int d=*(int*)b;
    if(c<d) return -1;
    else return 1;
}

int main()
{
    int n,i,j,k,l;
    int code[1007];
    char s[1007];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        alph t[26]={'A',0,'B',0,'C',0,'D',0,'E',0,'F',0,'G',0,'H',0,'I',0,'J',0,'K',0,'L',0,'M',0,'O',0,'P',0,'Q',0,'R',0,'S',0,'T',0,'U',0,'V',0,'W',0,'X',0,'Y',0,'Z',0};
        scanf("%s",s);
        int len=strlen(s);
        for(j=0;j<len;j++)
        {
            for(k=0;k<26;k++)
            {
                if(s[j]==t[k].ch)
                {
                     t[k].num++;;
                     break;//不要忘记break
                }
            }
        }
        k=0;
        if(t[25].num>0)
        {
            if(t[4].num>=t[25].num&&t[14].num>=t[25].num&&t[17].num>=t[25].num)
            {
                for(k=0;k<t[25].num;k++) code[k]=0;
                t[4].num-=t[25].num;
                t[14].num-=t[25].num;
                t[17].num-=t[25].num;
            }
        }
        if(t[23].num>0)
        {
            if(t[8].num>=t[23].num&&t[18].num>=t[23].num)
            {
                if(k) for(l=0;l<t[23].num;l++,k++) code[k]=6;
                else for(k=0;k<t[23].num;k++) code[k]=6;
                t[8].num-=t[23].num;
                t[18].num-=t[23].num;
            }
        }
    }

}
