#include <stdio.h>

int get_input();
int add_four_digits(int num);
int first_digit(int num);
int second_digit(int num);
int third_digit(int num);
int fourth_digit(int num);
void print_results(int sum);

int main(void) {
    int num;
    int sum;
    num = get_input();
    sum = add_four_digits(num);
    print_results(sum);
    return 0;
}

int get_input(void) {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    return num;
}

int add_four_digits(int num) {
    int result;
    result = first_digit(num) + second_digit(num) + third_digit(num) + fourth_digit(num);
    return result;
}

int first_digit(int num) {
    return num % 10;
}

int second_digit(int num) {
    return (num/10) % 10;
}

int third_digit(int num) {
    return (num/100) % 10;
}
int fourth_digit(int num) {
    return (num/1000) % 10;
}

void print_results(int sum) {
    printf("Sum of last four digits is: %d", sum);
}