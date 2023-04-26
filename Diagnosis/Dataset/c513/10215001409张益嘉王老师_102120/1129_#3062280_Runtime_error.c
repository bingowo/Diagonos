#include <stdio.h>
#include <stdlib.h>


int numis(char*n)
{
    int len=strlen(n),i,re=0;
    for(i=0;i<len;i++)
    {
        re*=10;
        re+=n[i]-'0';
    }
   // printf("co=%d\n",re);
    return re;
}


int main()
{
    char* s;
    char* smid;
    char* re=malloc(sizeof(char)*100000);
    re[0]=0;
    s=malloc(sizeof(char)*10000);
    smid=malloc(sizeof(char)*10000);
    scanf("%s",s);
    int len=strlen(s),i,co,j=0,st=0;
    char nmid[5];
    for(i=0;i<len;i++)
    {
        co=1;
        if((s[i]<'0')||(s[i]>'9'))
        {
            int k=0;
            for(;i<len;i++)
            {
                if((s[i]>='0')&&(s[i]<='9')) break;
                else smid[k++]=s[i];
            }
            smid[k]=0;
        }
        if((s[i]>='0')&&(s[i]<='9'))
        {
            int k=0;
            for(;i<len;i++)
            {
                if((s[i]<'0')||(s[i]>'9')) break;
                else nmid[k++]=s[i];
            }
            nmid[k]=0;
            //printf("n=%s\n",nmid);
            co=numis(nmid);
            i--;
        }
       //else printf("wrong\n");
       //printf("co2=%d\n",co);
       for(j=0;j<co;j++)
       {
           strcat(re,smid);
       }

    }
    free(s);
    free(smid);
    printf("%s",re);


}
