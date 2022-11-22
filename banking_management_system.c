#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct user {
        char name[40];
        char acc[11];
        char phone[11];
        char password[11];
        float balance;
}user;

int main()
{
    user usr, usr1;
    int opt,choice;
    FILE *fp;
    char filename[50], acc[50], password[50];
    char cont = 'y';
    float amount;


    printf("\nWelcome, kindly select a command below;\n");
    printf("\t1. Open or register an account\n");
    printf("\t2. Login to your account\n");

    printf("Enter your choice:\t");
    scanf("%d", &opt);

    if (opt == 1)
    {
        system("clear");
        printf("Enter your name:\t");
        scanf("%s", usr.name);
        printf("Enter phone number:\t");
        scanf("%s", usr.phone);
        printf("Enter account number:\t");
        scanf("%s", usr.acc);
        printf("Enter password: \t");
        scanf("%s", usr.password);
        usr.balance = 0; 
        strcpy(filename, usr.acc);
        fp = fopen(strcat(filename,".dat"), "w");
        fwrite(&usr, sizeof(user), 1, fp);
        if (fwrite != 0)
        {
            printf("\n\nAccount registered successfully");
        }else{
            printf("\n\nOops! somthing went wrong, please try again");
        }  
        fclose(fp);
    }
    if (opt == 2)
    {
         system("clear");
         printf("\nEnter your account number\t");
         scanf("%s", acc);
         printf("\nEnter your password  \t");
         scanf("%s", password);
         strcpy(filename, acc);
         fp = fopen(strcat(filename,".dat"), "r");
        if (fp == NULL)
        {
            printf("\nAccount number not registered\n");
        }else{
            fread(&usr, sizeof(user), 1, fp);
            fclose(fp);
            if (!strcmp(password, usr.password))
            {
                system("clear");
                printf("\tWelcome %s", usr.name);
                while (cont == 'y')
                {
                   printf("\n\nPress 1 for balance \t");
                   printf("\nPress 2 for cash deposit \t");
                   printf("\nPress 3 for cash withdrawal \t");
                   printf("\nPress 4 for online transfer \t");
                   printf("\nPress 5 to change password \t");
                   printf("\nYour choice: \t");
                   scanf("%d", &choice);

                   switch (choice)
                   {
                    case 1:
                        printf("Your account balance is \t%.2f", usr.balance);
                        break;

                    case 2:
                        printf("Enter amount \t");
                        scanf("%f", &amount);
                        usr.balance += amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(user),1,fp);
                        if (fwrite != NULL)
                        {
                            printf("%.2f, Deposited into your account succesfully", amount);
                        }
                        
                        fclose(fp); 
                        break;
                    case 3:
                        printf("Enter amount: \t");
                        scanf("%f", &amount);
                        usr.balance -= amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(user),1,fp);
                        if (fwrite != NULL)
                        {
                            printf("%.2f, Withdrawn from your account succesfully", amount);
                        }
                        
                        fclose(fp); 
                        break;
                    case 4:
                        printf("Enter reciepient account number \t");
                        scanf("%s", &acc);
                        printf("Enter transfer amount \t");
                        scanf("%f", &amount);
                        strcpy(filename, acc);
                        fp = fopen(strcat(filename,".dat"), "r");
                        if (fp == NULL)
                        {
                            printf("\nAccount number does not exist");
                        }else{
                                fread(&usr1, sizeof(user),1,fp);
                        fclose(fp);
                        if (amount > usr.balance)
                        {
                            printf("\nInsufficient balance");
                        }else{
    
                            fp = fopen(filename, "w");
                            usr1.balance += amount;
                            fwrite(&usr1, sizeof(user),1,fp);  
                            fclose(fp);
                            if (fwrite != NULL)
                            {
                                strcpy(filename, usr.acc);
                                fp = fopen(strcat(filename,".dat"), "w");
                                usr.balance -= amount;
                                fwrite(&usr, sizeof(user),1,fp);
                                fclose(fp);
                                printf("\nYou have transferred %f to user with %s account successfully ", amount, acc);
                            }
                        }
                        
                        }
                        break;
                    case 5:
                        printf("\nEnter new password");
                        scanf("%s", password);
                        fp = fopen(filename, "w");
                        strcpy(usr.password, password);
                        fwrite(&usr, sizeof(user), 1, fp);
                        if (fwrite != NULL)
                        {
                            printf("\nPassword changed successfully");
                        }
                        
                      break;  

                   default:
                    printf("\nInvalid selection");
                    break;
                   }
                
                   printf("\n\nDo you want to continue transaction? [y/n]: \t");
                   scanf("%s", &cont);
                }
                
            }else
            {
                printf("\nInvalid Password\n");
                
            }

        }
        

    
    }  

    
       

    return (0);
}