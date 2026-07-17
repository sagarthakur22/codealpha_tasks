#include<stdio.h>

  int main()
  {
    int a, b, choice;

    printf("Enter your choice \n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4)
    {
        printf("Select within the range!\n");
        return 1;
    }

    printf("Enter 2 integer numbers\n");
    if (scanf("%d %d", &a, &b) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    }

    switch(choice)
    {
        case 1 : printf("%d + %d = %d\n", a, b, (a+b));
                 break;

        case 2 : printf("%d - %d = %d\n", a, b, (a-b));
                 break;

        case 3 : printf("%d * %d = %d\n", a, b, (a*b));
                 break;

        case 4 : if (b != 0)
                     printf("%d / %d = %d\n", a, b, (a/b));
                 else
                     printf("Number cannot be divided by zero\n");
                 break;

        default : printf("You entered wrong choice\n");
                 break;
    }

    return 0;
 }
