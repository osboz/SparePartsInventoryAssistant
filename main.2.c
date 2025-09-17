#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char Input[100];

int hydraulic_pump, PLC_module, servo_motor;

void whatOfEach()
{
    printf("We have \n");
    printf("%2d: %s\n", hydraulic_pump, "hydraulic pump");
    printf("%2d: %s\n", PLC_module, "PLC module");
    printf("%2d: %s\n", servo_motor, "servo motor");
}

void evaluateInput(const char *input)
{


    
restart:
    if (strcmp(input, "PLC_module") == 0 && PLC_module > 0)
        printf("Yes, we have %d PLC modules in stock.\n", PLC_module);
    else if (strcmp(input, "hydraulic_pump") == 0 && hydraulic_pump > 0)
        printf("Yes, we have %d hydraulic pumps in stock.\n", hydraulic_pump);
    else if (strcmp(input, "servo_motor") == 0 && servo_motor > 0)
        printf("Yes, we have %d servo motors in stock.\n", servo_motor);
    else if (strcmp(input, "do you have anything at all ?") == 0)
        whatOfEach();
    else
    {
        printf("Sorry, we don't have that part in stock.\n");
        while ((getchar()) != '\n'); // clear input buffer
        goto restart;
    }
}

int main(void)
{
    hydraulic_pump = rand() % 100;
    PLC_module = rand() % 100;
    servo_motor = rand() % 100;

    printf("Hej. Welcome to the spare parts inventory!\n");
    printf("Which part do you need? (hydraulic_pump, PLC_module, servo_motor, all)\n");

    fgets(Input, sizeof(Input), stdin);
    // Remove newline character
    Input[strcspn(Input, "\n")] = 0;

    evaluateInput(Input);


    return 0;
}
