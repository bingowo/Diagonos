#include <stdio.h>
#include <string.h>
int main()
{
    int L[4]={0,0,0,0};
    char std[7][4]={"IN\0","OUT\0","MOV\0","ADD\0","SUB\0","MUL\0","DIV\0"};
    char s[4];
    while(scanf("%s",s)!=EOF)
    {
        int flag=-1;
        for(int i=0;i<7;i++){
            if(strcmp(std[i],s)==0){flag=i;break;}
        }
        char ns[20],ms[4];
        int num=0,d ='A'+'X';
        if(flag==1){
            scanf("%s",ns);
            printf("%d",L[ns[0]+ns[1]-d]);
        }
        else if(flag==0){
            scanf("%s",ns);
            int len=(int)strlen(ns),begin=0;
            int digit=1;
            for(int i=0;i<len;i++)
            {
            	if(ns[i]==',')
				{
					ns[i]='\0';
					begin=1;
					if(ns[i+1]=='-')
					{
						digit=-1;
						i++;
					}
					continue;
				}
            	if(begin==1) num=num*10+ns[i]-'0';
			}
            L[ns[0]+ns[1]-d]=digit*num;
        }
        else{
            scanf("%s",ns);
            int len=(int)strlen(ns),begin=0,p=0;
            for(int i=0;i<len;i++)
            {
            	if(ns[i]==',') {ns[i]='\0';begin=1;continue;}
            	if(begin==1) ms[p++]=ns[i]; 
			}
            switch(flag)
            {
                case 2: L[ns[0]+ns[1]-d]=L[ms[0]+ms[1]-d];break;
                case 3: L[ns[0]+ns[1]-d]+=L[ms[0]+ms[1]-d];break;
                case 4: L[ns[0]+ns[1]-d]-=L[ms[0]+ms[1]-d];break;
                case 5: L[ns[0]+ns[1]-d]=L[ns[0]+ns[1]-d]*L[ms[0]+ms[1]-d];break;
                case 6: L[ns[0]+ns[1]-d]=L[ns[0]+ns[1]-d]/L[ms[0]+ms[1]-d];break;
            }
        }
    }
    return 0;
}