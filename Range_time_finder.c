/*
This program will intake v_0, angle, and height and will output the time of the flight and the range
*/

#include <stdio.h>
#include <math.h>

void input_values(float* v_0, float* angle, float* height);
void find_components(float v_0, float angle, float* vx_0, float* vy_0);
float time_of_flight(float vy_0, float y);
float find_range(float t_flight, float vx_0);
void print_results(float v_0, float angle, float height, float range, float t_flight);

int main(void) {
    float v_0;
    float angle;
    float vx_0;
    float vy_0;
    float t_flight;
    float range;
    float height;
    input_values(&v_0, &angle, &height);
    find_components(v_0, angle, &vx_0, &vy_0);
    t_flight = time_of_flight(vy_0, height);
    range = find_range(t_flight, vx_0);
    print_results(v_0, angle, height, range, t_flight);

}

void input_values(float* v_0, float* angle, float* height) {
    // Prompt the user for information to find t
    printf("Enter the initial velocity in m/s: ");
    scanf("%f", v_0); // variables are already dereferenced
    
    printf("Enter the angle in degrees: ");
    scanf("%f", angle);

    printf("Enter the height in meters: ");
    scanf("%f", height);

    return;
}

void find_components(float v_0, float angle, float* vx_0, float* vy_0) {
    // Define pi, turn angle into radians, and find the initial vx and vy
    float pi = 3.14159;
    float radians = angle * (pi / 180.0);
    *vx_0 = v_0 * cos(radians); // dereference to assign or type error
    *vy_0 = v_0 * sin(radians);

    return;
}

float time_of_flight(float vy_0, float y) {
    // find the time using quadratic formula
    float t;
    float a;
    float b;
    float c;
    a = 0.5*-9.8; // -9.8 is gravity
    b = vy_0;
    c = -y;
    t = (-b - sqrt(b*b - 4*a*c)) / (2*a);
    
    return t;
}

float find_range(float t_flight, float vx_0) {
    // find the range
    return (t_flight * vx_0);
}

void print_results(float v_0, float angle, float height, float range, float t_flight) {
    // just prints the results
    printf("================================================================\n");
    printf("For v_0 = %.2f m/s, Angle = %.2f deg, and Height = %.2f m,\n", v_0, angle, height);
    printf("Flight time = %.2f sec and Range = %.2f m\n", t_flight, range);
    printf("================================================================");
}