#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *p1, const void *p2){
    return *(char*)p1 - *(char*)p2;
}

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int i = 0; i < T; i++){
        char d[10],m[10],c[10],rhout[3];
        scanf("%s%s%s",d,m,c);

        if(!strcmp(c,"?")){//child
            //type cmp
            if(d[0] == 'A'){
                if(d[1] == 'B'){
                    switch m[0]{
                        case 'A':
                            if(m[1] == 'B') strcpy(c,"ABAB");
                            else strcpy(c,"AAB");
                            break;
                        case 'B':
                            strcpy(c,"AAB");
                            break;
                        default:
                            strcpy(c,"ABO");
                            break;
                    }
                }

                else{
                    switch m[0]{
                        case 'A':
                            if(m[1] == 'B') strcpy(c,"AAB");
                            else strcpy(c,"AA");
                            break;
                        case 'B':
                            strcpy(c,"AA");
                            break;
                        default:
                            strcpy(c,"AO");
                            break;
                    }
                }
            }
            else if(d[0] == 'B'){
                switch m[0]{
                        case 'A':
                            if(m[1] == 'B') strcpy(c,"BAB");
                            else strcpy(c,"AB");
                            break;
                        case 'B':
                            strcpy(c,"AB");
                            break;
                        default:
                            strcpy(c,"BO");
                            break;
                    }
            }
            else{
                switch m[0]{
                        case 'A':
                            if(m[1] == 'B') strcpy(c,"OAB");
                            else strcpy(c,"AO");
                            break;
                        case 'B':
                            strcpy(c,"AO");
                            break;
                        default:
                            strcpy(c,"OO");
                            break;
                    }
            }


            //rh cmp(-/else)
            char *rh = d+strlen(d)-1;
            if(*rh == '-'){
                *rh = '\0';
                rh = m+strlen(m)-1;
                if(*rh == '+') strcpy(rhout,"+-");
                else strcpy(rhout,"--");
                *rh = '\0';
            }
            else{
                *rh = '\0';
                rh = m+strlen(m)-1;
                if(*rh == '+') strcpy(rhout,"++");
                else strcpy(rhout,"+-");
                *rh = '\0';
            }

            printf("%s %s {",d,m);//ABAB,AAB,ABO,AA,AO,BAB,AB,BO,OAB,OO
            if(!strcmp(c,"ABAB")){
                if(strcmp(rhout,"--")) printf("A-,AB-,B-}\n");
                else printf("A+,A-,AB+,AB-,B+,B-}\n");
            }
        }

        else{//parent
            if(!strcmp(d,"?")) strcmp(d,m); //operate d
            //type cmp
            if(d[0] == 'A'){
                if(d[1] == 'B'){
                    switch c[0]{
                        case 'A':
                            if(c[1] == 'B') strcpy(m,"ABAB");
                            else strcpy(c,"ABA");
                            break;
                        case 'B':
                            strcpy(c,"ABB");
                            break;
                        default:
                            strcpy(c,"ABO");
                            break;
                    }
                }

                else{
                    switch m[0]{
                        case 'A':
                            if(m[1] == 'B') strcpy(c,"AAB");
                            else strcpy(c,"AA");
                            break;
                        case 'B':
                            strcpy(c,"AA");
                            break;
                        default:
                            strcpy(c,"AO");
                            break;
                    }
                }
            }
            else if(d[0] == 'B'){
                switch m[0]{
                        case 'A':
                            if(m[1] == 'B') strcpy(c,"BAB");
                            else strcpy(c,"BA");
                            break;
                        case 'B':
                            strcpy(c,"BA");
                            break;
                        default:
                            strcpy(c,"BO");
                            break;
                    }
            }
            else{
                switch m[0]{
                        case 'A':
                            if(m[1] == 'B') strcpy(c,"OAB");
                            else strcpy(c,"OA");
                            break;
                        case 'B':
                            strcpy(c,"OA");
                            break;
                        default:
                            strcpy(c,"OO");
                            break;
                    }
            }


        }
    }

    return 0;
}
/*AB++(AB+)，AO++(A+)，AB+-(AB+)，AO+-(A+)，BO++(B+)，OO++(O+)，BO+-(B+)，OO+-(O+)，AB- -(AB-)，AO- -(A-)，BO- -(B-)，OO- -(O-)*/
