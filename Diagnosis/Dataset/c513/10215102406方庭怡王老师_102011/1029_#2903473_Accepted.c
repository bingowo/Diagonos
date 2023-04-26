#include<string.h> 
#include<ctype.h> 
int main() 
{ 
    char str[10][200];
    int i,j; 
    int t; 
    int k,m,temp; 
    int index[200];
    scanf("%d",&t); 
    gets(str[0]); 
    for(i=0;i<t;i++) 
    for(i=0;i<t;i++) 
    { 
        gets(str[i]);
        for(j=k=0;j<strlen(str[i]);j++) 
            if(str[i][j]>='A'&&str[i][j]<='Z')
            { 
                index[k]=j;
                k++; 
            } 
        for(j=0;j<k-1;j++)
            for(m=j+1;m<k;m++) 
            { 
                if(str[i][index[j]]>str[i][index[m]]) 
                { 
                    temp=str[i][index[m]]; 
                    str[i][index[m]]=str[i][index[j]]; 
                    str[i][index[j]]=temp; 
                } 
            } 
        printf("case #%d:\n%s\n",i,str[i]); 
    } 
    return 0; 
}