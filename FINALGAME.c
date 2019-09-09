#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

int v,map[25][20];
int ycheck[4];
int n=0;
char shape;
int score=0;


void Zblock(int *x1,int *x2,int *x3,int *x4,int *y1,int *y2,int *y3,int *y4)
{
    shape='Z';
    //printf("\n Z\n");
    srand(time(NULL)+2);
    v=rand()%2;

    if(v==0)
    //vertical
    {*x1=10;*x2=10;*x3=8;*x4=8;
    *y1=0;*y2=1;*y3=1;*y4=2;

    ycheck[0]=0;ycheck[1]=1;ycheck[2]=0;ycheck[3]=1;
    n=2;}


    else if(v==1)
    //horizontal
    {*x1=8;*x2=10;*x3=10;*x4=12;
    *y1=0;*y2=0;*y3=1;*y4=1;

    ycheck[0]=1;ycheck[1]=0;ycheck[2]=1;ycheck[3]=1;
    n=3;}


};

void Lblock(int *x1,int *x2,int *x3,int *x4,int *y1,int *y2,int *y3,int *y4)
{
    shape='L';
    //printf("\n L\n");
    srand(time(NULL)+3);
    v=rand()%4;

    if(v==0)

    //vertical
    {*x1=8;*x2=8;*x3=8;*x4=10;
    *y1=0;*y2=1;*y3=2;*y4=2;

    ycheck[0]=0;ycheck[1]=0;ycheck[2]=1;ycheck[3]=1;
    n=2;}

    else if(v==2)
    //vertical2
    {*x1=10;*x2=10;*x3=10;*x4=8;
    *y1=2;*y2=1;*y3=0;*y4=0;

    ycheck[0]=1;ycheck[1]=0;ycheck[2]=0;ycheck[3]=1;
    n=2;}

    else if(v==3)
    //horizontal
    {*x1=12;*x2=10;*x3=8;*x4=8;
    *y1=0;*y2=0;*y3=0;*y4=1;

    ycheck[0]=1;ycheck[1]=1;ycheck[2]=0;ycheck[3]=1;
    n=3;}

    else if(v==1)
    //horizontal2
    {*x1=8;*x2=10;*x3=12;*x4=12;
    *y1=1;*y2=1;*y3=1;*y4=0;

    ycheck[0]=1;ycheck[1]=1;ycheck[2]=1;ycheck[3]=0;
    n=3;}
};

void Iblock(int *x1,int *x2,int *x3,int *x4,int *y1,int *y2,int *y3,int *y4)
{
    shape='I';
    //printf("\n I\n");
    srand(time(NULL)+4);
    v=rand()%2;
    if(v==0)
    //vertical
    {*x1=8;*x2=8;*x3=8;*x4=8;
    *y1=0;*y2=1;*y3=2;*y4=3;

    ycheck[0]=0;ycheck[1]=0;ycheck[2]=0;ycheck[3]=1;
    n=1;}
    else if(v==1)
    //horizontal
    {*x1=6;*x2=8;*x3=10;*x4=12;
    *y1=0;*y2=0;*y3=0;*y4=0;

    ycheck[0]=1;ycheck[1]=1;ycheck[2]=1;ycheck[3]=1;
    n=4;}
};

void Sblock(int *x1,int *x2,int *x3,int *x4,int *y1,int *y2,int *y3,int *y4)
{
    v=0;
    shape='S';
    //printf("\n S\n");
    *x1=8;*x2=10;*x3=8;*x4=10;
    *y1=0;*y2=0;*y3=1;*y4=1;
    n=2;

    ycheck[0]=0;ycheck[1]=0;ycheck[2]=1;ycheck[3]=1;
};

void Tblock(int *x1,int *x2,int *x3,int *x4,int *y1,int *y2,int *y3,int *y4)
{
    shape='T';
    //printf("\n T\n");
    srand(time(NULL)+5);
    v=rand()%4;
    if(v==0)
    //vertical
    {*x1=10;*x2=10;*x3=10;*x4=12;
    *y1=0;*y2=2;*y3=1;*y4=1;

    ycheck[0]=0;ycheck[1]=1;ycheck[2]=0;ycheck[3]=1;
    n=2;}
    else if(v==2)
    //vertical2
    {*x1=10;*x2=10;*x3=10;*x4=8;
    *y1=2;*y2=0;*y3=1;*y4=1;

    ycheck[0]=1;ycheck[1]=0;ycheck[2]=0;ycheck[3]=1;
    n=2;}
    else if(v==1)
    //horizontal
    {*x1=8;*x2=12;*x3=10;*x4=10;
    *y1=1;*y2=1;*y3=1;*y4=0;

    ycheck[0]=1;ycheck[1]=1;ycheck[2]=1;ycheck[3]=0;
    n=3;}
    else if(v==3)
    //horizontal2
    {*x1=12;*x2=8;*x3=10;*x4=10;
    *y1=0;*y2=0;*y3=0;*y4=1;

    ycheck[0]=1;ycheck[1]=1;ycheck[2]=0;ycheck[3]=1;
    n=3;}
};


left();
right();
rotate();
drop(int *x1,int *x2,int *x3,int *x4,int *y1,int *y2,int *y3,int *y4)
{
    (*y1)++;(*y2)++;(*y3)++;(*y4)++;

    map[*y1-1][*x1]=0;map[*y1-1][*x1+1]=0;
    map[*y2-1][*x2]=0;map[*y2-1][*x2+1]=0;
    map[*y3-1][*x3]=0;map[*y3-1][*x3+1]=0;
    map[*y4-1][*x4]=0;map[*y4-1][*x4+1]=0;
};
draw();

int main()
{
    int x1,x2,x3,x4,y1,y2,y3,y4,xa,ya,xb,yb,xc,yc,temp,over=0,HS[5];
    int keep,rndm1,a,move,i,j,k,l,c=1,rndm,spawn=1,count=1,posbot,poslft,posrit,check,check2,square,cnt,var=0,z;
    char next,name[20],PN[5][20];


    printf("\n\n\n    [][][][][]   [][][][][]    [][][][][]    [][][][]      [][][][][]       [][]      \n");
          printf("        []       []                []        []     []         []          []   []        \n");
          printf("        []       [][][]            []        []     []         []            []           \n");
          printf("        []       []                []        [][][][]          []         []   []        \n");
          printf("        []       [][][][][]        []        []     []     [][][][][]       [][]             \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

          printf("                                      PRESS ENTER                                                                \n\n\n\n\n\n");

          printf("                                    up arrow- rotate                   \n");
          printf("                                    down arrow- drop                     \n");
          printf("                                 right arrow- move right               \n");
          printf("                                  left arrow- move left                      \n");

    z=getche();


    srand(time(NULL));
    rndm=rand()%5;
    //rndm=4;


    while(1)
    {
        if(spawn)
        {
            for(i=5;i<=24;i++)
            {
                square=0;
                for(j=0;j<=19;j++)
                {
                    if(map[i][j]==1)
                    {
                        square++;
                    }
                }
                if(square==20)
                {
                    score=score+10;
                    for(k=i;k>0;k--)
                    {
                        for(l=0;l<=19;l++)
                        {
                            //Sleep(20);
                            map[k][l]=map[k-1][l];
                        }
                    }
                }
            }

            for(i=0;i<=19;i++)
            {
                if(map[4][i]>=1)
                {
                    over=1;
                    break;
                }
            }
            if(over)
            {
                break;
            }

            if(var!=0)
            {rndm=rndm1;}
            spawn=0;
            if(rndm==0)
            {
                Zblock(&x1,&x2,&x3,&x4,&y1,&y2,&y3,&y4);
            }
            else if(rndm==1)
            {
                Lblock(&x1,&x2,&x3,&x4,&y1,&y2,&y3,&y4);
            }
            else if(rndm==2)
            {
                Iblock(&x1,&x2,&x3,&x4,&y1,&y2,&y3,&y4);
            }
            else if(rndm==3)
            {
                Sblock(&x1,&x2,&x3,&x4,&y1,&y2,&y3,&y4);
            }
            else if(rndm==4)
            {
                Tblock(&x1,&x2,&x3,&x4,&y1,&y2,&y3,&y4);
            }

            keep=rndm;
            srand(time(NULL));
            rndm1=keep;
            while(rndm1==keep)
            {
                rndm1=rand()%5;
            }


        }

        move=0;
        if(kbhit())
        {
            move=getche();
        }

        if(move==27)
        {
            system("cls");
            printf("\n\n\n\n\n\n                         P                                       PAUSED                 \n\n\n\n");
            printf("                              press any key to continue                        \n\n\n\n");
            z=getche();
        }
        poslft=19;
        if(x1<poslft){poslft=x1;}
        if(x2<poslft){poslft=x2;}
        if(x3<poslft){poslft=x3;}
        if(x4<poslft){poslft=x4;}

        if(move==75)
        {
            if(!(x1<=0||x2<=0||x3<=0||x4<=0))
            {
                if(!(map[y1][poslft-1]>0||map[y2][poslft-1]>0||map[y3][poslft-1]>0||map[y4][poslft-1]>0))
                {
                    x1--;x2--;x3--;x4--;
                    x1--;x2--;x3--;x4--;
                    map[y1][x1+2]=0;map[y1][x1+3]=0;
                    map[y2][x2+2]=0;map[y2][x2+3]=0;
                    map[y3][x3+2]=0;map[y3][x3+3]=0;
                    map[y4][x4+2]=0;map[y4][x4+3]=0;
                }

            }

        }
        map[y1][x1]=c;map[y1][x1+1]=c;
        map[y2][x2]=c;map[y2][x2+1]=c;
        map[y3][x3]=c;map[y3][x3+1]=c;
        map[y4][x4]=c;map[y4][x4+1]=c;

        posrit=0;
        if(x1>posrit){posrit=x1;}
        if(x2>posrit){posrit=x2;}
        if(x3>posrit){posrit=x3;}
        if(x4>posrit){posrit=x4;}

        if(move==77)
        {

            if(!(x1>=18||x2>=18||x3>=18||x4>=18))
            {
                if(!(map[y1][posrit+2]>0||map[y2][posrit+2]>0||map[y3][posrit+2]>0||map[y4][posrit+2]>0))
                {
                    x1++;x2++;x3++;x4++;
                    x1++;x2++;x3++;x4++;
                    map[y1][x1-2]=0;map[y1][x1-1]=0;
                    map[y2][x2-2]=0;map[y2][x2-1]=0;
                    map[y3][x3-2]=0;map[y3][x3-1]=0;
                    map[y4][x4-2]=0;map[y4][x4-1]=0;
                }
            }
        }
        map[y1][x1]=c;map[y1][x1+1]=c;
        map[y2][x2]=c;map[y2][x2+1]=c;
        map[y3][x3]=c;map[y3][x3+1]=c;
        map[y4][x4]=c;map[y4][x4+1]=c;


        cnt=0;
        if(move==72&&shape!='S')
        {
            map[y1][x1]=0;map[y1][x1+1]=0;
            map[y2][x2]=0;map[y2][x2+1]=0;
            map[y3][x3]=0;map[y3][x3+1]=0;
            map[y4][x4]=0;map[y4][x4+1]=0;

            xa=(x1-x3)/2;
            ya=y1-y3;
            temp=xa;
            xa=ya;
            ya=temp*(-1);
            if(map[ya+y3][xa*2+x3]==0)
            {
                if((ya+y3)<=24&&(xa*2+x3)<=18&&(xa*2+x3)>=0)
                {
                   cnt++;
                }
            }

            xb=(x2-x3)/2;
            yb=y2-y3;
            temp=xb;
            xb=yb;
            yb=temp*(-1);
            if(map[yb+y3][xb*2+x3]==0)
            {
                if((yb+y3)<=24&&(xb*2+x3)<=18&&(xb*2+x3)>=0)
                {
                   cnt++;
                }
            }

            xc=(x4-x3)/2;
            yc=y4-y3;
            temp=xc;
            xc=yc;
            yc=temp*(-1);
            if(map[yc+y3][xc*2+x3]==0)
            {
                if((yc+y3)<=24&&(xc*2+x3)<=18&&(xc*2+x3)>=0)
                {
                   cnt++;
                }
            }
            //printf("\n%d\n",cnt);
        }
        if(cnt==3)
        {
            map[y1][x1]=0;map[y1][x1+1]=0;
            x1=xa*2+x3;
            y1=ya+y3;

            map[y2][x2]=0;map[y2][x2+1]=0;
            x2=xb*2+x3;
            y2=yb+y3;

            map[y4][x4]=0;map[y4][x4+1]=0;
            x4=xc*2+x3;
            y4=yc+y3;
            cnt=0;

            if(v<3)
            {
                v++;
            }
            else{v=0;}
        }



        map[y1][x1]=c;map[y1][x1+1]=c;
        map[y2][x2]=c;map[y2][x2+1]=c;
        map[y3][x3]=c;map[y3][x3+1]=c;
        map[y4][x4]=c;map[y4][x4+1]=c;

        if(shape=='I')
        {
            //printf("we did it :D");
            switch(v)
            {
                case 0:
                ycheck[0]=0;ycheck[1]=0;ycheck[2]=0;ycheck[3]=1;
                n=1;
                break;

                case 1:
                ycheck[0]=1;ycheck[1]=1;ycheck[2]=1;ycheck[3]=1;
                n=4;
                break;

                case 2:
                ycheck[0]=1;ycheck[1]=0;ycheck[2]=0;ycheck[3]=0;
                n=1;
                break;

                case 3:
                ycheck[0]=1;ycheck[1]=1;ycheck[2]=1;ycheck[3]=1;
                n=4;
                break;
            }
        }

        if(shape=='Z')
        {
            switch(v)
            {
                case 0:
                ycheck[0]=0;ycheck[1]=1;ycheck[2]=0;ycheck[3]=1;
                n=2;
                break;

                case 1:
                ycheck[0]=1;ycheck[1]=0;ycheck[2]=1;ycheck[3]=1;
                n=3;
                break;

                case 2:
                ycheck[0]=1;ycheck[1]=0;ycheck[2]=1;ycheck[3]=0;
                n=2;
                break;

                case 3:
                ycheck[0]=1;ycheck[1]=1;ycheck[2]=0;ycheck[3]=1;
                n=3;
                break;
            }
        }


        if(shape=='L')
        {
            switch(v)
            {
                case 0:
                ycheck[0]=0;ycheck[1]=0;ycheck[2]=1;ycheck[3]=1;
                n=2;
                break;

                case 1:
                ycheck[0]=1;ycheck[1]=1;ycheck[2]=1;ycheck[3]=0;
                n=3;
                break;

                case 2:
                ycheck[0]=1;ycheck[1]=0;ycheck[2]=0;ycheck[3]=1;
                n=2;
                break;

                case 3:
                ycheck[0]=1;ycheck[1]=1;ycheck[2]=0;ycheck[3]=1;
                n=3;
                break;
            }
        }

        if(shape=='T')
        {
            switch(v)
            {
                case 0:
                ycheck[0]=0;ycheck[1]=1;ycheck[2]=0;ycheck[3]=1;
                n=2;
                break;

                case 1:
                ycheck[0]=1;ycheck[1]=1;ycheck[2]=1;ycheck[3]=0;
                n=3;
                break;

                case 2:
                ycheck[0]=1;ycheck[1]=0;ycheck[2]=0;ycheck[3]=1;
                n=2;
                break;

                case 3:
                ycheck[0]=1;ycheck[1]=1;ycheck[2]=0;ycheck[3]=1;
                n=3;
                break;
            }
        }


        printf("\n\n\n                              ");
        for(i=0;i<24;i++)
        {
            printf("%c",205);
        }
        printf("\n");

        for(i=5;i<25;i++)
        {
            printf("                              %c ",186);
            for(j=0;j<20;j++)
            {
                if(map[i][j]==0)
                {
                    printf("%c",' ');
                }
                if(map[i][j]==1)
                {
                    printf("%c",178);
                }
            }
            printf("%c\n",186);
        }

        printf("                              ");
        for(i=0;i<24;i++)
        {
            printf("%c",205);
        }
        printf("\n");

        for(i=0;i<4;i++)
        {
            if(ycheck[i]==1)
            {

            }
        }

        posbot=0;
        if(y1>posbot){posbot=y1;}
        if(y2>posbot){posbot=y2;}
        if(y3>posbot){posbot=y3;}
        if(y4>posbot){posbot=y4;}

        check=0;
        if(ycheck[0]==1)
        {
            if(map[y1+1][x1]==0)
            {
                check++;
            }
        }
        if(ycheck[1]==1)
        {
            if(map[y2+1][x2]==0)
            {
                check++;
            }
        }
        if(ycheck[2]==1)
        {
            if(map[y3+1][x3]==0)
            {
                check++;
            }
        }
        if(ycheck[3]==1)
        {
            if(map[y4+1][x4]==0)
            {
                check++;
            }
        }
        check2=0;
        if(y1==posbot)
        {
            check2++;
        }
        if(y2==posbot)
        {
            check2++;
        }
        if(y3==posbot)
        {
            check2++;
        }
        if(y4==posbot)
        {
            check2++;
        }

        if(move==80)
        {
            if(!(y1==24||y2==24||y3==24||y4==24))
            {
                if(check==n)
                {
                    drop(&x1,&x2,&x3,&x4,&y1,&y2,&y3,&y4);
                }
                else{spawn=1;}
            }
            else{spawn=1;}
        }
        map[y1][x1]=c;map[y1][x1+1]=c;
        map[y2][x2]=c;map[y2][x2+1]=c;
        map[y3][x3]=c;map[y3][x3+1]=c;
        map[y4][x4]=c;map[y4][x4+1]=c;

        if(count%5==0)
        {
            if(!(y1==24||y2==24||y3==24||y4==24))
            {
                if(check==n)
                {
                    drop(&x1,&x2,&x3,&x4,&y1,&y2,&y3,&y4);
                }
                else{spawn=1;}
            }
            else{spawn=1;}
        }

        if(rndm1==0)
        {
            next='Z';
        }
        if(rndm1==1)
        {
            next='L';
        }
        if(rndm1==2)
        {
            next='I';
        }
        if(rndm1==3)
        {
            next='S';
        }
        if(rndm1==4)
        {
            next='T';
        }

        printf("\n                              ");
        printf("score=%d          next:%c",score,next);

        Sleep(30);
        system("cls");
        count++;
        var++;
    }

    FILE *f1;
    f1=fopen("highscores.txt","r");
    fscanf(f1,"%s %d %s %d %s %d %s %d %s %d",&PN[0],&HS[0],&PN[1],&HS[1],&PN[2],&HS[2],&PN[3],&HS[3],&PN[4],&HS[4]);

    if(score>HS[4])
    {
        printf("                              ^_^ HIGHSCORE!!! ^_^\n\n                              Enter your name!!: \n                              ");
        scanf("%s",&PN[4]);

        fclose(f1);
        remove(f1);
        HS[4]=score;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4-i;j++)
            {
                if(HS[j]<HS[j+1])
                {
                    temp=HS[j+1];
                    HS[j+1]=HS[j];
                    HS[j]=temp;

                    strcpy(name,PN[j+1]);
                    strcpy(PN[j+1],PN[j]);
                    strcpy(PN[j],name);
                }

            }
        }
        f1=fopen("highscores.txt","w");
        fprintf(f1,"%s %d %s %d %s %d %s %d %s %d",PN[0],HS[0],PN[1],HS[1],PN[2],HS[2],PN[3],HS[3],PN[4],HS[4]);
    }

    printf("\n\n\n\n\n                              GAME OVER\n\n\n                              HIGHSCORES:\n\n\n                              %s %d\n                              %s %d\n                              %s %d\n                              %s %d\n                              %s %d\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",PN[0],HS[0],PN[1],HS[1],PN[2],HS[2],PN[3],HS[3],PN[4],HS[4]);
    fclose(f1);

}




