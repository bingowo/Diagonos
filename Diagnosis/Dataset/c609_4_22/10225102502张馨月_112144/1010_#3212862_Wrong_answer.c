#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void itob(int n,char s[100],int r)
{
    const char table[]={"0123456789ABCDEF"};


    int k=0;
    do{
        if(n%r>0||n%r==0)
            {s[k]=table[n%r];
            n=n/r;
            k++;
            }
        else{
            if(n<0)
            {
                s[k]=table[n-(n/r+1)*r];
                n=n/r+1;
                k++; //!重要
            }
            else{
                s[k]=table[n%r];
            n=n/r;
            k++;
            }
        }

    }while(n!=0);


    s[k]='\0';

    int i,j;
    char t;
    j=strlen(s)-1;
    for(i=0;i<j;i++,j--)
    {
      t=s[i];
      s[i]=s[j];
      s[j]=t;
    }

}
int main()
{
    int N,FR;
    scanf("%d %d",&N,&FR);


    char s[100];
    itob(N,s,FR);
    printf("%s\n",s);


    return 0;
}