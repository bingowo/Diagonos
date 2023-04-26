#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char father[10],mother[10],child[10];
        scanf("%s %s %s",father,mother,child);
        if(strcmp("?",child)==0)
        {
            printf("%s %s ",father,mother);
            char a[5],b[5];
            int ans[5];
            for(int i=0;i<5;i++) ans[i]=0;
            //A,AB,B,O,1,2,3,4
            int k=0;
            if(father[0]=='O')
            {
                a[k++]='O';
            }
            else if(father[0]=='B')
            {
                a[k++]='B';a[k++]='O';
            }
            else if(father[0]=='A')
            {
                if(father[1]=='B')
                {
                    a[k++]='A';a[k++]='B';
                }
                else
                {
                    a[k++]='A';a[k++]='O';
                }
            }
            a[k++]='\0';
            k=0;
            if(mother[0]=='O')
            {
                b[k++]='O';
            }
            else if(mother[0]=='B')
            {
                b[k++]='B';b[k++]='O';
            }
            else if(mother[0]=='A')
            {
                if(mother[1]=='B')
                {
                    b[k++]='A';b[k++]='B';
                }
                else
                {
                    b[k++]='A';b[k++]='O';
                }
            }
            b[k++]='\0';
            for(int i=0;i<strlen(a);i++)
            {
                for(int j=0;j<strlen(b);j++)
                {
                    if(a[i]=='O' && b[j]=='O') ans[4]=1;
                    else if((a[i]=='O' && b[j]=='A')||(a[i]=='A' && b[j]=='O')||(a[i]=='A' && b[j]=='A')) ans[1]=1;
                    else if((a[i]=='O' && b[j]=='B')||(a[i]=='B' && b[j]=='O')||(a[i]=='B' && b[j]=='B')) ans[3]=1;
                    else if((a[i]=='A' && b[j]=='B')||(a[i]=='B' && b[j]=='A')) ans[2]=1;
                }
            }
            int cnt=0;
            for(int i=1;i<=4;i++)
            {
                if(ans[i]==1) cnt++;
            }
            int flag=0;
            if(father[strlen(father)-1]=='-' && mother[strlen(mother)-1]=='-')
            {
                flag=1;
            }
            else flag=2;
            if(cnt!=1)
            {
                int t=0;
                printf("{");
                if(ans[1]==1)
                {
                    t++;
                    if(flag==1)
                    {
                        printf("A-");
                    }
                    else printf("A+,A-");
                    if(t!=cnt) printf(",");
                }
                if(ans[2]==1)
                {
                    t++;
                    if(flag==1)
                    {
                        printf("AB-");
                    }
                    else printf("AB+,AB-");
                    if(t!=cnt) printf(",");
                }
                if(ans[3]==1)
                {
                    t++;
                    if(flag==1)
                    {
                        printf("B-");
                    }
                    else printf("B+,B-");
                    if(t!=cnt) printf(",");
                }
                if(ans[4]==1)
                {
                    t++;
                    if(flag==1)
                    {
                        printf("O-");
                    }
                    else printf("O+,O-");
                    if(t!=cnt) printf(",");
                }
                printf("}");
            }
            else
            {
                if(ans[1]==1)
                {
                    if(flag==1) printf("A-");
                    else
                    {
                        printf("{A+,A-}");
                    }
                }
                if(ans[2]==1)
                {
                    if(flag==1) printf("AB-");
                    else
                    {
                        printf("{AB+,AB-}");
                    }
                }
                if(ans[3]==1)
                {
                    if(flag==1) printf("B-");
                    else
                    {
                        printf("{B+,B-}");
                    }
                }
                if(ans[4]==1)
                {
                    if(flag==1) printf("O-");
                    else
                    {
                        printf("{O+,O-}");
                    }
                }
            }
            printf("\n");
        }
        else if(strcmp(father,"?")==0)
        {
            int a[5];
            for(int i=0;i<5;i++)
            {
                a[i]=0;
            }
            if(child[0]=='A')
            {
                if(child[1]!='B')
                {
                    if(mother[0]=='A' && mother[1]!='B')
                    {
                        a[1]=1;a[2]=1;a[3]=1;a[4]=1;
                    }
                    else if(mother[0]=='B')
                    {
                        a[1]=1;a[2]=1;
                    }
                    else if(mother[0]=='A' && mother[1]=='B')
                    {
                         a[1]=1;a[2]=1;a[3]=1;a[4]=1;
                    }
                    else if(mother[0]=='O')
                    {
                        a[1]=1;a[2]=1;
                    }
                }
                else
                {
                    if(mother[0]=='A' && mother[1]!='B')
                    {
                        a[2]=1;a[3]=1;
                    }
                    else if(mother[0]=='B')
                    {
                        a[1]=1;a[2]=1;
                    }
                    else if(mother[0]=='A' && mother[1]=='B')
                    {
                         a[1]=1;a[2]=1;a[3]=1;
                    }
                }
            }
            else if(child[0]=='B')
            {
                if(mother[0]=='A' && mother[1]!='B')
                {
                    a[2]=1;a[3]=1;
                }
                else if(mother[0]=='B')
                {
                    a[1]=1;a[2]=1;a[3]=1;a[4]=1;
                }
                else if(mother[0]=='A' && mother[1]=='B')
                {
                    a[1]=1;a[2]=1;a[3]=1;a[4]=1;
                }
                else if(mother[0]=='O')
                {
                    a[2]=1;a[3]=1;
                }
            }
            else if(child[0]=='O')
            {
                if(mother[0]=='A' && mother[1]!='B')
                {
                    a[1]=1;a[3]=1;a[4]=1;
                }
                else if(mother[0]=='B')
                {
                    a[1]=1;a[3]=1;a[4]=1;
                }
                else if(mother[0]=='O')
                {
                    a[1]=1;a[3]=1;a[4]=1;
                }
            }
            int cnt=0;
            for(int i=1;i<=4;i++)
            {
                if(a[i]==1) cnt++;
            }
            if(cnt==0) printf("impossible ");
            else
            {
                int flag=1;
                if(child[strlen(child)-1]=='-') flag=2;
                else if(child[strlen(child)-1]=='+')
                {
                    if(mother[strlen(mother)-1]=='+') flag=2;
                    else flag=1;
                }
                int t=0;
                if(cnt!=1)
                {
                    printf("{");
                    if(a[1]==1)
                    {
                        t++;
                        if(flag==1) printf("A+");
                        else printf("A+,A-");
                        if(t!=cnt) printf(",");
                    }
                    if(a[2]==1)
                    {
                        t++;
                        if(flag==1) printf("AB+");
                        else printf("AB+,AB-");
                        if(t!=cnt) printf(",");
                    }
                    if(a[3]==1)
                    {
                        t++;
                        if(flag==1) printf("B+");
                        else printf("B+,B-");
                        if(t!=cnt) printf(",");
                    }
                    if(a[4]==1)
                    {
                        t++;
                        if(flag==1) printf("O+");
                        else printf("O+,O-");
                        if(t!=cnt) printf(",");
                    }
                    printf("} ");
                }
                else
                {
                    if(a[1]==1)
                    {
                        if(flag==1) printf("A+");
                        else printf("{A+,A-}");
                    }
                    if(a[2]==1)
                    {
                        if(flag==1) printf("AB+");
                        else printf("{AB+,AB-}");
                    }
                    if(a[3]==1)
                    {
                        if(flag==1) printf("B+");
                        else printf("{B+,B-}");
                    }
                    if(a[4]==1)
                    {
                        if(flag==1) printf("O+");
                        else printf("{O+,O-}");
                    }
                    printf(" ");
                }
            }
            printf("%s %s\n",mother,child);
        }
        else if(strcmp(mother,"?")==0)
        {
            printf("%s ",father);
            int a[5];
            for(int i=0;i<5;i++)
            {
                a[i]=0;
            }
            if(child[0]=='A')
            {
                if(child[1]!='B')
                {
                    if(father[0]=='A' && father[1]!='B')
                    {
                        a[1]=1;a[2]=1;a[3]=1;a[4]=1;
                    }
                    else if(father[0]=='B')
                    {
                        a[1]=1;a[2]=1;
                    }
                    else if(father[0]=='A' && father[1]=='B')
                    {
                         a[1]=1;a[2]=1;a[3]=1;a[4]=1;
                    }
                    else if(father[0]=='O')
                    {
                        a[1]=1;a[2]=1;
                    }
                }
                else
                {
                    if(father[0]=='A' && father[1]!='B')
                    {
                        a[2]=1;a[3]=1;
                    }
                    else if(father[0]=='B')
                    {
                        a[1]=1;a[2]=1;
                    }
                    else if(father[0]=='A' && father[1]=='B')
                    {
                         a[1]=1;a[2]=1;a[3]=1;
                    }
                }
            }
            else if(child[0]=='B')
            {
                if(father[0]=='A' && father[1]!='B')
                {
                    a[2]=1;a[3]=1;
                }
                else if(father[0]=='B')
                {
                    a[1]=1;a[2]=1;a[3]=1;a[4]=1;
                }
                else if(father[0]=='A' && father[1]=='B')
                {
                    a[1]=1;a[2]=1;a[3]=1;a[4]=1;
                }
                else if(father[0]=='O')
                {
                    a[2]=1;a[3]=1;
                }
            }
            else if(child[0]=='O')
            {
                if(father[0]=='A' && father[1]!='B')
                {
                    a[1]=1;a[3]=1;a[4]=1;
                }
                else if(father[0]=='B')
                {
                    a[1]=1;a[3]=1;a[4]=1;
                }
                else if(father[0]=='O')
                {
                    a[1]=1;a[3]=1;a[4]=1;
                }
            }
            int cnt=0;
            for(int i=0;i<=4;i++)
            {
                if(a[i]==1) cnt++;
            }
            if(cnt==0) printf("impossible ");
            else
            {
                int flag=1;
                if(child[strlen(child)-1]=='-') flag=2;
                else if(child[strlen(child)-1]=='+')
                {
                    if(father[strlen(father)-1]=='+') flag=2;
                    else flag=1;
                }
                int t=0;
                if(cnt!=1)
                {
                    printf("{");
                    if(a[1]==1)
                    {
                        t++;
                        if(flag==1) printf("A+");
                        else printf("A+,A-");
                        if(t!=cnt) printf(",");
                    }
                    if(a[2]==1)
                    {
                        t++;
                        if(flag==1) printf("AB+");
                        else printf("AB+,AB-");
                        if(t!=cnt) printf(",");
                    }
                    if(a[3]==1)
                    {
                        t++;
                        if(flag==1) printf("B+");
                        else printf("B+,B-");
                        if(t!=cnt) printf(",");
                    }
                    if(a[4]==1)
                    {
                        t++;
                        if(flag==1) printf("O+");
                        else printf("O+,O-");
                        if(t!=cnt) printf(",");
                    }
                    printf("} ");
                }
                else
                {
                    if(a[1]==1)
                    {
                        if(flag==1) printf("A+");
                        else printf("{A+,A-}");
                    }
                    if(a[2]==1)
                    {
                        if(flag==1) printf("AB+");
                        else printf("{AB+,AB-}");
                    }
                    if(a[3]==1)
                    {
                        if(flag==1) printf("B+");
                        else printf("{B+,B-}");
                    }
                    if(a[4]==1)
                    {
                        if(flag==1) printf("O+");
                        else printf("{O+,O-}");
                    }
                    printf(" ");
                }
            }
            printf("%s\n",child);
        }
    }
    return 0;
}

