#include <stdio.h>
#include <stdlib.h>
#include <string.h> // comparing string from external .txt file

int main()
{
    int age,number,choice,choice01,choice02,choice03,sum=0;
    char name[50];
    FILE* fptr; /* naming of file (it is file pointer )*/

    printf("Enter your name ");
    scanf("%49s", name);

    printf("Enter your age ");
    scanf("%d", &age);

    printf("Enter your number ");
    scanf("%d", &number);

    char seats[4][5][7]={{"A1-$40","A2-$40","A3-$40","A4-$40","A5-$40"},{"B1-$35","B2-$35","B3-$35","B4-$35","B5-$35"},{"C1-$30","C2-$30","C3-$30","C4-$30","C5-$30"},{"D1-$25","D2-$25","D3-$25","D4-$25","D5-$25"}}; /* format is for strings array {char A[number of strings][number of characters] } */
     homepage: // go to function

     printf("What Do you want to do ? \n Book Ticket Press->1 \n Cancel Ticket Press->2 \n  Exit Press->3 \n");
     scanf("%d", &choice);
    
    switch (choice)
    {
        case 1:
        {
            char sseats[3];
            char savedseat[3];
            int booked=0;
            int i,j;
            int cf; // case-1
            trynew01:
            printf("\n");
            printf("\n");

            for (i=0;i<4;i++)
            {
              for(j=0;j<5;j++)
              {
                printf("%s\t",seats[i][j]);
              }
              printf("\n");
            }

            printf("\n");
            printf("\n");
            printf("Enter the seats you want to book ");
            scanf("%2s",sseats);

            fptr= fopen ("memory.txt","r");
            if (fptr!= NULL)
            {
               while (fscanf(fptr,"%2s",savedseat) == 1) /*1 beacause when one line succeds reading , all reading is saved in savedseat */
               {
                 if(strcmp(sseats,savedseat) ==0) /*0 bacuse to compare both strings one in .txt file and one in seatselected , comapring savedseat and sseats*/
                 {
                   booked = 1;
                   break;

                 }
                }
                fclose(fptr);
            }

                if (booked==1)
                {
                    printf("\n");
                    printf("That seat is already booked. \n ");
                }

                else 
                {
                    printf("That seat is available. \n ");
                     printf("Want to proceed further? \n Press-1 to confirm \n Press-2 to exit \n ");
                     scanf("%d",&cf);

                     if(cf == 1) // to confirm ticket
                     {
                        fptr = fopen("memory.txt","a"); // opening in writing mode (like it writes in ending of text )
                        if (fptr!= NULL)
                        {
                            int bill;
                            fprintf(fptr,"%s\n",sseats);
                            fclose(fptr);
                            if (strcmp(sseats, "A1") == 0 || strcmp(sseats, "A2") == 0 || strcmp(sseats, "A3") == 0 || strcmp(sseats, "A4") == 0 || strcmp(sseats, "A5") == 0 )
                            {
                              sum+=40;
                            }
                            else if (strcmp(sseats, "B1") == 0 || strcmp(sseats, "B2") == 0 || strcmp(sseats, "B3") == 0 || strcmp(sseats, "B4") == 0 ||strcmp(sseats, "B5") == 0)
                            {
                                sum+=35;
                            }
                            else if (strcmp(sseats, "C1") == 0 || strcmp(sseats, "C2") == 0 || strcmp(sseats, "C3") == 0 || strcmp(sseats, "C4") == 0 || strcmp(sseats, "C5") == 0 )
                            {
                                bill+=30;
                            }
                            else
                            {
                                bill+=25;
                            }
                            bill=sum;
                            printf("\n");
                            printf(" Your Total Bill--> %d",bill);             /* left from here */
                            printf("\t Seat booked. thank you !! \n");

                            printf("\n");
                        }
                     }
                }
                            printf(" what do you want to do \n Press-1 to homepage || Press-2 to exit booking site || Press-3 to book other ticket \n ");
                             scanf("%d",&choice01);

                            switch(choice01)
                            {
                             case 1:
                             {
                               goto homepage;
                                 break;
                             }
                              case 2:
                             {
                              goto exitpage;
                              break;
                             }
                             case 3:
                             {
                                goto trynew01;
                                break;
                             }
                             }
               break; 
         }
         case 2:
         {
            char savedseat01[3];
            char cticket[3];
            int booked01=0;

            trynew:
            printf("\n Enter which seat you want to cancel -->\n ");
            scanf("%2s",cticket);

            fptr = fopen("memory.txt", "r");
            if (fptr != NULL)
            {
              while (fscanf(fptr,"%2s",savedseat01) == 1)
              {
                if(strcmp(cticket,savedseat01) ==0)
                {
                  booked01=1;
                  break;
                }
              }
              fclose(fptr);
            }

            if (booked01==1)
            {
                FILE*oldfile =fopen("memory.txt","r");
                FILE*newfile =fopen("temp.txt","w"); /* "w" beacuse writing from fresh not "r" , which speacially designed for adding part at very end of line */

                while (fscanf(oldfile,"%2s",savedseat01) == 1)
                {
                    if (strcmp(cticket,savedseat01) !=0)
                    {
                        fprintf(newfile,"%s\n",savedseat01);
                    }
                }
                fclose(oldfile);
                fclose(newfile);

                remove("memory.txt");
                rename("temp.txt","memory.txt");
                printf("\n");
                printf("Seat has been cancelled. ");


            }

            else 
            {
                printf("\n Your ticket is not found, Opps... you might have not booked this ticket \n ");
                printf("Press-1 To try another ticket \n Press-2 To Exit booking site \n Press-3 To homepage \n " );
                scanf("%d",&choice02);
                switch(choice02)
                {
                    case 1:
                    {
                    goto trynew;
                    break;
                    }
                    case 2:
                    {
                        goto exitpage;
                        break;
                    }
                    case 3:
                    {
                        goto homepage;
                        break;
                    }
                }
            }
            
            printf(" \n Press-1 To Exit booking site \n Press-2 To homepage \n " );
                scanf("%d",&choice03);
                switch(choice03)
                {
                    case 1:
                    {
                    goto exitpage;
                    break;
                    }
                    case 2:
                    {
                        goto homepage;
                        break;
                    }
                    
                }
                 
            break;
               
        }
        case 3:
        {
            exitpage:
            printf("\n \n Thank you for visiting booking site \n \n ");
            break;
        }

}
 return 0;
}