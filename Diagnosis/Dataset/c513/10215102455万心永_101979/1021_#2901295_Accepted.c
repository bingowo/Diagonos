#include<stdio.h>
#include<stdlib.h>
int p[26];
int cmp(const void *a,const void *b);
int main()
{

    
    char alpha[27];
    while(scanf("%s",alpha)!=EOF)
    {
        for(int i=0;i<26;i++)
            p[alpha[i]-'A']=i;
        getchar();
        char a[100][21];
        int count=0,k=0,status=0;
        char c;
        do
        {
            c=getchar( );
            if(c!=' '&&c!='\n') {a[count][k++]=c;status=1;}
            else if(status)
                {a[count][k]='\0';count=count+1;k=0;status=0;}
        }while(c!='\n');
        qsort(a,count,sizeof(a[0]),cmp);
        for (int i=0;i<count;i++)
        {
            if(i!=count-1)  printf("%s ",a[i]);
            else printf("%s\n",a[i]);
        }
    }
    

}
int cmp(const void *a,const void *b)
{
    char *s1,*s2;char ch1,ch2;
    s1=*(char (*)[21])a;s2=*(char (*)[21])b;
    while(*s1&&*s2)
    {
        ch1=(*s1)>='a'?*s1-32:*s1;    
        ch2=(*s2)>='a'?*s2-32:*s2;     
        if(p[ch1-'A']!=p[ch2-'A'])     
                return p[ch1-'A']-p[ch2-'A'];
        else {s1++;s2++;}
    }
    if(*s1==0) return -1;
    else return 1;
}
