#include<stdio.h>
int main()
{
    while(1)
    {
        char id[50];
        scanf("%s",&id);
        int i=0;
        int flag=0;     //int
        while(id[i]!='\000')
        {
            if(id[i]=='.')  
            {
                flag=1;     //double
                break;
            }
            i++;
        }
        if(flag==0)     //int处理
        {
            int zf=0;
            int int_id=0;
            for(i=0;id[i]!='\000';i++)
            {
                if(id[i]=='-')  
                {
                    zf=1;
                    continue;
                }                
                int_id=int_id*10+id[i]-48;
            }
            if(zf==1)    int_id=-int_id;
            int bin[32];
            if(int_id==0)   //0处理
            {
                printf("00 00 00 00\n");
                continue;
            }
            else if(int_id>0)   //正数处理
            {
                for(int j=0;j<32;j++)   bin[j]=0;
                int j=0;
                while (int_id!=0)
                {
                    bin[j]=int_id%2;
                    int_id=int_id/2;
                    j++;
                }
            }
            else    //负数处理
            {
                for(int j=0;j<32;j++)   bin[j]=1;
                int_id=-int_id;
                int j=0;
                while (int_id!=0)
                {
                    bin[j]=int_id%2;
                    if(bin[j]==0)   bin[j]=1;
                    else    bin[j]=0;
                    int_id=int_id/2;
                    j++;
                }
                for(j=0;bin[j]==1;j++) bin[j]=0;
                bin[j]=1;
            }
            char mem[8];
            int k=0;
            for(int j=0;j<32;j=j+8)
            {
                mem[k]=bin[j+4]+bin[j+5]*2+bin[j+6]*4+bin[j+7]*8;
                mem[k+1]=bin[j]+bin[j+1]*2+bin[j+2]*4+bin[j+3]*8;
                k=k+2;
            }
            for(int j=0;j<8;j++)
            {
                if(mem[j]>=0 && mem[j]<=9)  mem[j]=mem[j]+48;
                else    mem[j]=mem[j]+87;
            }            
            for(int j=0;j<6;j=j+2)
            {
                printf("%c%c ",mem[j],mem[j+1]);
            }
            printf("%c%c\n",mem[6],mem[7]);
        }   
        else        //double处理
        {            
            char z[10],x[10];
            int i=0;
            while(id[i]!='.')   
            {
                z[i]=id[i];
                i++;
            }
            i++;
            while(id[i]!='\000')   
            {
                x[i]=id[i];
                i++;
            }

            //整数部分处理
            
        }     
    }
    return 0;
}