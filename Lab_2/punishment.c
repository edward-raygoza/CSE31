#include <stdio.h>

int main(){
    int number, typoline; 
    char sentence[50]= "C programming is the best! ";
    char typo[50]= "C programming language is the bet! ";

    printf("Enter the number of lines for the punishment: ");
    scanf("%d", &number);

    if(number < 0){
    printf("You entered an incorrect value for the number of lines! ");
    }
    else
    {
        printf("Enter the line for which we want to make a typo: ");
        scanf("%d", &typoline);
    
        if(typoline < 0|| typoline > number){
            printf("You entered an incorrect value for the line typo!");
        }
        else
        {
            for(int i = 1; i <=number; i++){
                if(i != typoline)
                    printf("%s",sentence);
                    else
                    printf("%s", typo);
                }
            }
        }
    return 0;
    }