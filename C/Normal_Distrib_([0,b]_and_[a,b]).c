
#include <stdio.h>
#include <math.h>

double euler = 2.718281828;
double pi = 3.1415926535;

double a, b;


void zero_to_b();
void between();

int main() {

    int choice;

    do {
        printf("\n===== AREA CALCULATOR =====\n");
        printf("[1] Area from [0,b]\n");
        printf("[2] Area Between [a,b]\n");
        printf("[3] Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                zero_to_b();
                break;

            case 2:
                between();
                break;

            case 3:
                printf("Program Terminated.\n");
                break;

            default:
                printf("Invalid Choice!\n");
                break;
        }

    } while (choice != 3);

    return 0;
}


void zero_to_b() {

    printf("Enter the value of b: ");
    scanf("%lf", &b);

    double b_squared = b * b;
    double square_twopi = sqrt(2.0 * pi);

    double outside = (849.0 * b) / (1700.0 * square_twopi);

    double first_coefficient = pow(euler, -0.03 * b_squared);
    double second_coefficient = pow(euler, -0.297 * b_squared);

    double result = outside * (first_coefficient + second_coefficient);

    printf("\nArea from [0, %.4lf]: %.10lf\n", b, result);
}


void between() {

    printf("Enter the value of a: ");
    scanf("%lf", &a);

    printf("Enter the value of b: ");
    scanf("%lf", &b);

    double a_squared = a * a;
    double square_twopi = sqrt(2.0 * pi);

    double outside_a = (849.0 * a) / (1700.0 * square_twopi);

    double first_coefficient_a = pow(euler, -0.03 * a_squared);
    double second_coefficient_a = pow(euler, -0.297 * a_squared);

    double result_a = outside_a * (first_coefficient_a + second_coefficient_a);

    double b_squared = b * b;

    double outside_b = (849.0 * b) / (1700.0 * square_twopi);

    double first_coefficient_b = pow(euler, -0.03 * b_squared);
    double second_coefficient_b = pow(euler, -0.297 * b_squared);

    double result_b = outside_b * (first_coefficient_b + second_coefficient_b);

   
    double final = result_b - result_a;

    printf("\nF(a) = %.10lf\n", result_a);
    printf("F(b) = %.10lf\n", result_b);

    printf("\nArea between [%.4lf, %.4lf]: %.10lf\n", a, b, final);
}
