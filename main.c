#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>


static int i=0;
int n;
int move=0;
COORD c = {0, 0};
void login(int score,char a);
void reg(void);
void flush(void);
void game1(void);
void game2(void);
void gameMenu(void);
void display_border(void);
void exitProgram(void);
void mainMenu(void);


struct web
{

char name[30],pass[30];
    
int scoreGame1;
    
int scoreGame2;

int data;
}
    

w[100];

int main()
    {
    mainMenu();
    return 0;
    }
void mainMenu()
{
    system("cls");
    printf("\n\n\n\n\n\t\t\t\tWELCOME TO THE MAIN MENU");
    printf("\n\t\t\t\t------- -- --- --------");
    printf("\n\n\n\n\t\t\tPress Enter to proceed....");
    
    if(getch())
        system("cls");
    
    XY:
    printf("\n\n\n\t\t\t1. LOGIN\t\t2. REGISTER\t\t3. ENTER GAME MENU\t\t4. EXIT");
    printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1: system("cls");
            login(-1,'#');
            break;
        case 2: system("cls");
            reg();
            break;
        case 3: system("cls");
            gameMenu();
            break;
        case 4: system("cls");
            exitProgram();
            break;
        default: printf("\n\n\t\t\t\tNO MATCH FOUND");
            printf("\n\n\t\t\tPress Enter to re-Enter the choice");
            if(getch())
            {
            system("cls");
            goto XY;
            }
    }
}
void exitProgram()
{
    system("cls");
    printf ("\n\n\t\t\t\tHAVE A NICE DAY :)");
    exit(0);
}
void gameMenu()
{
    printf ("\n\n\n\n\t\t\t\tWELCOME TO THE GAME MENU");
    printf ("\n\t\t\t\t------- -- --- ---- ----");
    AB:
    printf ("\n\n1 . FETCH THE BALL GAME");
    printf ("\n\n2 . NUMBER GUESSING GAME");
    printf ("\n\n3 . EXIT");
    printf ("\n\n\t\t\t\tENTER YOUR CHOICE : ");
    scanf ("%d",&n);
    switch(n)
    {
        case 1: system("cls");
            game1();
            break;
        case 2: system("cls");
            game2();
            break;
        case 3: system("cls");
            exitProgram();
            break;
        default: system("cls");
            printf ("\n\n\t\t\t\tNO MATCH FOUND");
            printf ("\n\n\t\t\tPress Enter to re-Enter your choice");
            if (getch())
            {
                system("cls");
                goto AB;
            }
    }
}
void reg()
    {
    FILE *fp;
    char c,checker[30]; 
    int z=0;
    int j=0,i;
    struct web buf[100];
    fp=fopen("Web_reg.txt","r");
    if (fp==NULL)
    {
        printf("\n\n\t\t\t\tDATABASE DOES NOT EXIST ...");
        printf ("\n\n\t\t\t\tCREATING DATABASE.............");
        Sleep(2000);
        flush();
    }
    while(!feof(fp))
    {
        fread(&buf[j],sizeof(struct web),1,fp);
        j++;
    }
    fclose(fp);

    printf("\n\n\t\t\t\t\t\tREGISTER PORTAL");
    printf("\n\t\t\t\t\t\t-------- ------");
    
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",checker);
        for (i=0;i<100;i++)
            {
            if(strcmp(checker,buf[i].name)==0)
                {
                printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
                getch();
                system("cls");
                fclose(fp);
                reg();
                }
            }
        for (j=0;j<100;j++)
        {
            
            if (buf[j].data!=1)
            {
            
            strcpy(buf[j].name,checker);
            buf[j].data=1;
            break;
            }
            else 
            {
                continue;
            }
        }

            
    printf("\n\n\t\t\t\t  SET PASSWORD: ");
    while((c=getch())!=13)
    {
        buf[j].pass[z++]=c;
        printf("%c",'*');
    }
        
    printf("\n\n\tPress enter if you agree with Username and Password");
        if((c=getch())==13)
        {
            fp=fopen("Web_reg.txt","w");
            system("cls");
            for (i=0;i<100;i++)
            {
                fwrite(&buf[i],sizeof(struct web),1,fp);
            }
            fclose(fp);
            printf("\n\n\t\tYou are successfully registered");
            printf("\n\n\t\tWant to login ?\n\n\t\t  ");
            printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
            scanf("%d",&n);
            switch(n)
            {
                case 1: system("cls");
                        login(-1,'#');
                        break;
                case 2: system("cls");
                        printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");
                        break;
            }
        }
         getch();
    }
       
void login(int score,char a)
        {
        FILE *fp;
        char c,name[30],pass[30]; 
        int z=0,j=0,k,i;
        int ind=-1;
        int checku,checkp;
        struct web w[100];
        fp=fopen("Web_reg.txt","r");
        if (fp==NULL)
        {
            printf ("\nDatabase not found or it's corrupted redirecting to register page .... .....");
            Sleep(3000);
            system("cls");
            reg();
        }
        while(!feof(fp))
        {
            fread(&w[j],sizeof(struct web),1,fp);
            j++;
        }
        fclose(fp);
        ZZ:
        printf("\n\n\t\t\t\t\t\tLOG IN PORTAL");
        printf("\n\t\t\t\t\t\t--- -- ------");
        for(i=0;i<100;i++)
        {
            printf("\n\n\t\t\t\t  ENTER USERNAME : ");
            scanf("%s",name);
            printf("\n\n\t\t\t\t  ENTER PASSWORD : ");
            while((c=getch())!=13)
            {
            pass[z++]=c;
            printf("%c",'*');
            }
            pass[z]='\0';
        for (k=0;k<100;k++)
            {
            if (strcmp(name,w[k].name)==0&&strcmp(pass,w[k].pass)==0)
            {
                ind=k;
                break;

            }
            }
            if (ind==-1)
            {
                printf ("\n\nWrong username/password");
                Sleep(2000);
                system("cls");
                goto ZZ;
            }
            
                if (score>=0&&a!='#')
                {
                    system("cls");
                    printf ("\n\n\t\t\tSTORING DATA ... ...");
                    printf ("\n\n\t\t\tONLY HIGHEST SCORES WILL BE SAVED!!!");
                    Sleep(1000);
                    if (a=='a')
                    {
                        if (w[ind].scoreGame1<score)
                        {
                            printf ("\n\t\t\t\tDATA SAVED SUCCESSFULLY !");
                            w[ind].scoreGame1=score;
                            fclose(fp);
                            fp=fopen("Web_reg.txt","w");
                            for (j=0;j<100;j++)
                            {
                                fwrite (&w[j],sizeof(w[j]),1,fp);
                            }
                            fclose(fp);
                            Sleep(2000);
                            mainMenu();
                        }
                        else 
                        {
                            printf ("\n\nYOUR PREVIOUS SCORE WAS HIGHER THAN THIS BETTER LUCK NEXT TIME !!");
                            Sleep(2000);
                            system("cls");
                            mainMenu();
                        }
                    }
                    else if (a=='b')
                    {
                        if (w[ind].scoreGame2<score)
                        {
                            printf ("\n\t\t\t\tDATA SAVED SUCCESSFULLY !");
                            w[ind].scoreGame2=score;
                            fclose(fp);
                            fp=fopen("Web_reg.txt","w");
                            for (j=0;j<100;j++)
                            {
                                fwrite (&w[j],sizeof(w[j]),1,fp);
                            }
                            fclose(fp);
                            Sleep(2000);
                            mainMenu();
                        }
                        else 
                        {
                            printf ("\n\nYOUR PREVIOUS SCORE WAS HIGHER THAN THIS BETTER LUCK NEXT TIME !!");
                            Sleep(2000);
                            system("cls");
                            mainMenu();
                        }
                    }
                    

                }
                else
                {
                    system("cls");
                    printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
                    printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY");
                    printf ("\n\n\n\t\t\tYOUR USERNAME : %s",w[ind].name);
                    printf ("\n\n\n\t\t\tYOUR GAME SCORES ARE ");
                    printf ("\n\t\t\t---- ---- ------ --- ");
                    printf ("\n\n\t\t\t1. GAME1 = %d ",w[ind].scoreGame1);
                    printf ("\n\n\t\t\t1. GAME2 = %d ",w[ind].scoreGame2);
                    printf ("\n\n\t\tPress Enter to continue .... ");
                    getch();
                    mainMenu();
                    break;
                }
            break;
        }
        getch();
        }
void setxy (int x, int y)
{
 c.X = x; 
 c.Y = y;  
 FILE *file1;
 file1 = fopen ("Moves.txt","w");
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
 putw(move,file1);
 fclose (file1);
}
void game1()
{
    int choice;
    int batx=15,baty=13, ballx=25, bally=7;
    int x=25, y=10, ch1, ch2, b;
  
    setxy(14,1);
    printf("...Find The Ball...") ;
    display_border();
 
    setxy(batx, baty);
    printf("===");
 
    setxy(ballx, bally);
    printf("%c",2);
 
    ch1 = getch(); 
    ch2 = 0;

  
    if (ch1 == 0xE0) 
    {  
        while(ch2=getch())
        {
            if(ch2 == 'X') exit(0);
            if(ch2 == 75)
            {
                if(batx>11) 
                {
                    move++; 
                    setxy(--batx,baty);
                    printf("===");     
                    setxy(batx+3,baty);
                    printf(" ");
                }
            }
    if(ch2 == 77) 
    {
        if(batx<37)
        {
            move++;
            setxy(++batx,baty);
            printf("===");
            setxy(batx-1,baty);
     
            printf(" ");
        }
    }   
    if(ch2 == 72) 
    {
        if(baty>6)
        {
            move++;
            setxy(batx,--baty);
            printf("===");
            setxy(batx,baty+1);
            printf("   ");
        } 
    }
    if(ch2 == 80) 
    {
        if(baty<14)
        {
            move++;
            setxy(batx,++baty);
            printf("===");
            setxy(batx,baty-1);
            printf("   ");
        } 
    }
    if(batx==ballx-1 && baty==bally)
    {
        setxy(ballx-9,bally+4);
        printf("...Congratulations...");
        setxy(ballx-9,bally+5);
        printf("  ...Ball Found..");
        setxy(ballx-9,bally+6);
        printf("   ...Game Over..");
        printf ("\n\n\n\n\nMoves : %d",move);
        printf ("\n\nYOUR SCORE : %d",1000/move);
        printf ("\n\n\n\n");
        BC:
        printf ("\n\n\t\t\t\t1 . STORE YOUR SCORE \n\n\t\t\t\t2 . GO TO LOGIN PAGE \n\n\t\t\t\t3 . EXIT");
        printf ("\n\n\t\t\t\tENTER YOUR CHOICE : ");
        scanf ("%d",&choice);
        switch(choice)
        {
        case 1: system("cls");
            login(1000/move,'a');
            break;
        case 2: system("cls");
            gameMenu();
            break;
        case 3: system("cls");
            exitProgram();
            break;
        default: system("cls");
            printf ("\n\n\t\t\t\tNO MATCH FOUND");
            printf ("\n\n\t\t\tPress Enter to re-Enter your choice");
            if (getch())
            {
                system("cls");
                goto BC;
            }
        }
        getch();
        exit(0);
    }    
    
    }
    }
    
    getch();
    
    
}
void display_border()
{
 int i, j;
 
 setxy(10,5); 
 for(j=0; j<30; j++)
  printf("%c", 223);
 
 
 setxy(10,15);
 for(j=0; j<=30; j++)
  printf("%c", 223);
 
 
 for(j=0; j<10; j++)
 {
  setxy(10,5+j);
  printf("%c",219);
  
  setxy(40,5+j);
  printf("%c",219);
 }
 printf("\n");
}
void game2()
{
    int N;
    printf ("\n\n\t\t\t\tGUESSING GAME ");
    printf ("\n\t\t\t\t-------- ----");
    printf ("\n\n\t\t\t\tEnter a value for the N for the interval (1-N) : ");
    scanf ("%d",&N);
    int number, guess, numberofguess = 0;

    int choice ;
  
    number = rand() % N;
  
    printf("Guess a number between 1 and %d\n",N);
    do {
  
        if (numberofguess > 20) {
            printf ("\n\nNumber of guesses exceeded");
            printf("\nYou Lose!\n");
            break;
        }
        scanf("%d", &guess);
        if (guess > number)
  
        {
            printf("Lower number please!\n");
            numberofguess++;
        }
        else if (number > guess)
  
        {
            printf("Higher number please!\n");
            numberofguess++;
        }
        else
            printf("You guessed the number in %d attempts!\n",numberofguess);
  
    } while (guess != number);
    printf ("\nYOUR SCORE IS : %d",(1000/numberofguess+1));
    CD:
        printf ("\n\n\t\t\t\t1 . STORE YOUR SCORE \n\n\t\t\t\t2 . GO TO LOGIN PAGE \n\n\t\t\t\t3 . EXIT");
        printf ("\n\n\t\t\t\tENTER YOUR CHOICE : ");
        scanf ("%d",&choice);
        switch(choice)
        {
        case 1: system("cls");
            login((1000/numberofguess+1),'b');
            break;
        case 2: system("cls");
            gameMenu();
            break;
        case 3: system("cls");
            exitProgram();
            break;
        default: system("cls");
            printf ("\n\n\t\t\t\tNO MATCH FOUND");
            printf ("\n\n\t\t\tPress Enter to re-Enter your choice");
            if (getch())
            {
                system("cls");
                goto CD;
            }
        }
        getch();
        exit(0);

}
void flush()
{
    struct web temp[100];
    FILE *fp;
    int i;
    fp=fopen("Web_reg.txt","w");
    for (i=0;i<100;i++)
    {
        fwrite(&temp[i],sizeof(struct web),1,fp);
    }
    fclose(fp);
    reg();
}
