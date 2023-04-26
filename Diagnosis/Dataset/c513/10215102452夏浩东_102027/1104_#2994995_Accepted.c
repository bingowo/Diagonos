#include <stdio.h>
#include <string.h>
int main()
{
    char order[5];
    char std[12][5]={"IN\0","OUT\0","MOV\0","XCHG\0","ADD\0","SUB\0","MUL\0",
        "DIV\0","MOD\0","AND\0","OR\0","XOR\0"};
    int L[26];
    for(int i=0;i<26;i++) L[i]=0;
    while(scanf("%s",order)!=EOF)
    {
        int ord=-1,num=0,index[3]={-1,-1,-1};
        char ns[50];
        for(int i=0;i<12;i++) if(strcmp(order,std[i])==0){ord=i;break;}
        scanf("%s",ns);
        int len=(int)strlen(ns);
        
        if(ord==0){
            int fushu=1;
            for(int i=0;i<len;i++)
            {
                if(ns[i]==',') continue;
                else if(ns[i]=='-') fushu=-1;
                else if(ns[i+1]=='X') index[0]=ns[i]-'A';
                else if(ns[i]<='9' && ns[i]>='0') num=num*10+ns[i]-'0';
            }
            num=num*fushu;
            L[index[0]]=num;
        }else{
            int k=0;
            for(int i=0;i<len;i++)
            {
                if(ns[i]==',') {k++;continue;}
                else if(ns[i+1]=='X') index[k]=ns[i]-'A';
            }
            int temp=L[index[0]];
            switch(ord){
                case 1: printf("%d\n",L[index[0]]);break;
                case 2: L[index[0]]=L[index[1]];break;
                case 3:
                    L[index[0]]=L[index[1]];
                    L[index[1]]=temp;
                    break;
                case 4:
                    if(k==2) L[index[0]]=L[index[1]]+L[index[2]];
                    else L[index[0]]=L[index[0]]+L[index[1]];
                    break;
                case 5:
                    if(k==2) L[index[0]]=L[index[1]]-L[index[2]];
                    else L[index[0]]=L[index[0]]-L[index[1]];
                    break;
                case 6:
                    if(k==2) L[index[0]]=L[index[1]]*L[index[2]];
                    else L[index[0]]=L[index[0]]*L[index[1]];
                    break;
                case 7:
                    if(k==2) L[index[0]]=L[index[1]]/L[index[2]];
                    else L[index[0]]=L[index[0]]/L[index[1]];
                    break;
                case 8:
                    if(k==2) L[index[0]]=L[index[1]]%L[index[2]];
                    else L[index[0]]=L[index[0]]%L[index[1]];
                    break;
                case 9:
                    if(k==2) L[index[0]]=L[index[1]]&L[index[2]];
                    else L[index[0]]=L[index[0]]&L[index[1]];
                    break;
                case 10:
                    if(k==2) L[index[0]]=L[index[1]]|L[index[2]];
                    else L[index[0]]=L[index[0]]|L[index[1]];
                    break;
                case 11:
                    if(k==2) L[index[0]]=L[index[1]]^L[index[2]];
                    else L[index[0]]=L[index[0]]^L[index[1]];
                    break;
            }
        }
    }
    return 0;
}