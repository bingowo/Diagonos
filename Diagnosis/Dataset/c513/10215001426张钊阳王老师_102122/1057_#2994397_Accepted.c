#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char w[1500];
    memset(w,'\0',1500);
    int i=0,l=0,flag=0;
    char c;
    while(c=getchar())
    {
        if(c=='\n') break;
        if(flag==0) {w[i]=c;flag++;continue;}
        write(w,c,l);
        l++;
    }
    for(int z=0;z<l+1;z++)
    {
        if(w[z]>='a'&&w[z]<='z') w[z]=w[z]-32;
    }

    printf("%s",w);
    return 0;
}


void write(char *s,char a1,int l)
{
    char s1[1500];
    char s2[1500];
    char a[2];
    a[0]=a1;a[1]='\0';
    strcpy(s1,s);
    strcpy(s2,a);
    strcat(s1,a);
    strcat(s2,s);

    if(strcmp(s1,s2)>=0){
        s[l+1]=a1;
    }
    else if(strcmp(s1,s2)<0)
    {
        for(int z=l+1;z>0;z--)
        {
            s[z]=s[z-1];
        }
        s[0]=a1;
    }
}


