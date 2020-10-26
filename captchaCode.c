

#include<stdio.h>
#include<stdlib.h> // for exit(0) function
#include<windows.h> // for sleep() function
#define MAX 6

int Captcha();
int wait();
char captcha[MAX+1];
int main()
{
    char ch;
    int i;
    srand(time(0));
    printf("\n\n\t------------------------------------");
    printf("\n\t Enter (X) to exit");
    printf("\n\n\t------------------------------------\n");

    while(1)
    {
        if(kbhit()) // true if key press
        {
            printf("\nPress 'X' to Exit :  ");
            scanf(" %c",&ch);

            if(ch=='x' || ch=='X')
                exit(0);
            else
            {
                printf("\n\n\t------------------------------\n");
                printf("\n\t| You are continuing program |\n");
                printf("\n\t------------------------------\n");
            }
        }
        else
           {
              // printf("\nNot hitted");
              if(!Captcha()) // true when entered charecter is other than (X)
                continue;
              printf("\n\t**********************************");
              printf("\n\t[+] Captacha code is --> ");

             for(i=0; i<6; i++)
                {
                    printf("%c",captcha[i]);
                }
              printf("\n\t**********************************\n");
           }
    }
return 0;
} // End of main
int Captcha()
{
    int low=65,upp=90,i,changer,temp;
    for(i=0; i<6; i++)
    {
        temp=rand()%10;
        (temp%2==0)?(changer=0):(changer=32);
        //when rand() is divisible by 2 it will add lower case letter to 'captcha' variable
        if(temp%3==0)
        {
            upp=57;
            low=48;
            changer=0;//when rand() is divisible by 3 it will add numbers to 'captcha' variable
        }
        captcha[i]=(rand() %(upp-low+1))+low+changer;
        //when use rand()%(upp-low) we get a small number if we add it to new 'low' we get required random ascii value
        // upp-low gives the range here 25 and +1 to make it 26 so so 26 alphabets are there.
        changer=0;
        low=65;
        upp=90;
    }
if( !wait())
 return 0;
}

int wait() //To see the time delay for the next new code
{
    int i;
    for (i=1;i<6;i++)
    {
        if(kbhit())
            return 0;
	printf(" [!] New code in %d sec\n",i);
	delay(1000);
       sleep(1);   // belongs to windows.h to make 1 sec delay we are using this.
    }
return 1;
}
