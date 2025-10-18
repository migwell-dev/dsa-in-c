#include <stdio.h>
#include "polynomial.h"

int main() {
    Polynomial A = create_polynomial();
    Polynomial B = create_polynomial();

    add_term(&A, 3, 4);
    add_term(&A, 2, 2);
    add_term(&A, -5, 0);

    add_term(&B, 4, 3);
    add_term(&B, 2, 2);
    add_term(&B, 7, 0);

    printf("Polynomial A: ");
    print_polynomial(A);

    printf("Polynomial B: ");
    print_polynomial(B);

    Polynomial C = add_polynomials(A, B);
    printf("A + B = ");
    print_polynomial(C);

    free_polynomial(&A);
    free_polynomial(&B);
    free_polynomial(&C);
    return 0;
}
