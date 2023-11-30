#include <stdio.h>
#include <math.h>

int main() {
    FILE *file;
    file = fopen("rgr.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int a, b, c;
    int solutions = 0;
    int errors = 0;

    while (fscanf(file, "%d %d %d", &a, &b, &c) == 3) {
        if (a > c) {
            double discriminant = b * b - 4 * a * c;

            if (discriminant > 0) {
                double root1 = (-b + sqrt(discriminant)) / (2 * a);
                double root2 = (-b - sqrt(discriminant)) / (2 * a);
                printf("Solution %d: Root 1 = %.2lf, Root 2 = %.2lf\n", solutions + 1, root1, root2);
                solutions++;
            } else if (discriminant == 0) {
                double root = -b / (2 * a);
                printf("Solution %d: Double root = %.2lf\n", solutions + 1, root);
                solutions++;
            } else {
                printf("Error: No real roots for Solution %d\n", solutions + 1);
                errors++;
            }
        } else {
            printf("Error: a <= c for Solution %d\n", solutions + 1);
            errors++;
        }
    }

    printf("\nTotal Solutions: %d\n", solutions);
    printf("Total Errors: %d\n", errors);

    fclose(file);

    return 0;
}
