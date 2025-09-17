#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// initialize variables
char Input[100];
int hydraulic_pump, PLC_module, servo_motor;

// function to print what we have of each part
void whatOfEach()
{
    printf("We have \n");
    printf("%2d: %s\n", hydraulic_pump, "hydraulic pump");
    printf("%2d: %s\n", PLC_module, "PLC module");
    printf("%2d: %s\n", servo_motor, "servo motor");
}
// function 
void evaluateInput()
{
    // restart point
restart:

    // ask and get input
    printf("\nWhich part do you need? (hydraulic pump, PLC module, servo motor)");
    fgets(Input, sizeof(Input), stdin);

    // Remove newline character
    Input[strcspn(Input, "\n")] = 0;
    char *input = Input;

    // evaluate input
    if (strcmp(input, "PLC module") == 0 && PLC_module > 0)
        printf("Yes, we have %d PLC modules in stock.\n", PLC_module);
    else if (strcmp(input, "hydraulic pump") == 0 && hydraulic_pump > 0)
        printf("Yes, we have %d hydraulic pumps in stock.\n", hydraulic_pump);
    else if (strcmp(input, "servo motor") == 0 && servo_motor > 0)
        printf("Yes, we have %d servo motors in stock.\n", servo_motor);
    else if (strcmp(input, "Is there anything in stock at all?") == 0 || strcmp(input, "Do you actually have any parts?") == 0)
        whatOfEach();
    else
    {
        printf("Sorry, we don't have that part in stock.\n");
        goto restart;
    }
}
// main function
int main(void)
{
    // assign random values to the parts: 0-99
    hydraulic_pump = rand() % 100;
    PLC_module = rand() % 100;
    servo_motor = rand() % 100;


    printf("Hej. Welcome to the spare parts inventory!\n");

    evaluateInput();

    return 0;
}
