#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

typedef struct Term {
    int coeff;
    int exp;
    struct Term* next;
} Term;

typedef struct Polynomial {
    Term* head;
} Polynomial;

/*creates empty linked list*/
Polynomial create_polynomial();

/*adds a term to the polynomial*/
void add_term(Polynomial* poly, int coeff, int exp);

/*prints polynomial*/
void print_polynomial(Polynomial poly);

/*adds two polynomials*/
Polynomial add_polynomials(Polynomial a, Polynomial b);

/*frees memory*/
void free_polynomial(Polynomial* poly);

#endif
