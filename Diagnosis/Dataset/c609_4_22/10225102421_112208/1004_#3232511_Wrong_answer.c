#include<stdio.h>
#include<string.h>
int main()
{
    int old,now;
    char str[100];
    scanf("%d %s %d",&old,str,&now);

    int ten=0;
    int n=1;
    int temp=0;
    int cont=0;
    int x=1;
    for (int i=strlen(str)-1;i>=0;i--)
    {
        if (str[i]>='0' && str[i]<='9')
            temp=str[i]-'0';
        else if (str[i] >='A' && str[i]<='Z')
            temp=str[i]-'A'+10;
        else if (str[i] >='a' && str[i]<='z')
            temp=str[i]-'a'+10;
        else
        {
            x=-1;
            break;
        }
        ten+= temp*n;
        n*=old;
    }
    while(ten)
    {
        temp=ten%now;
        ten /=now;
        if (temp>=10)
            str[cont]=temp-10+'A';
        else
            str[cont]=temp+'0';
        cont++;
    }
    if (x==-1)
        printf("-");
    for (int i=cont-1;i>=0;i--)
        printf("%c",str[i]);
}
