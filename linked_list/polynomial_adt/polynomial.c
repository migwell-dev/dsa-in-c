#include "polynomial.h"
#include <stdio.h>
#include <stdlib.h>

Polynomial create_polynomial() {
  Polynomial p;
  p.head = NULL;
  return p;
}

void add_term(Polynomial *poly, int coeff, int exp) {
  if (coeff == 0)
    return; // 0*coeff^exp = 0, return

  Term *newTerm = malloc(sizeof(Term));
  newTerm->coeff = coeff;
  newTerm->exp = exp;
  newTerm->next = NULL;

  /*
   * if no term in head or if term to be added is highest degree
   */
  if (!poly->head || exp > poly->head->exp) {
    newTerm->next = poly->head;
    poly->head = newTerm;
    return;
  }

  /*
   * walk through linked list while curr is not null and curr's exp is
   * greater than exponent of the term to be added.
   * this results in the walk stopping at the end, OR when curr's exp is
   * equal to newTerm's exp, OR when curr's exp is less than newTerm's exp.
   */
  Term *curr = poly->head;
  Term *prev = NULL;
  while (curr && curr->exp > exp) {
    prev = curr;
    curr = curr->next;
  }

  /*
   * if curr->exp == exp:
   *     combine coefficients (curr->coeff += coeff)
   *     free newTerm (no new node needed)
   *     if resulting coefficient is 0, remove curr from the list.
   *     i.e. 5 + -5 = 0
   *
   * else (curr->exp < exp or curr == NULL):
   *     insert newTerm before curr
   *     adjust prev->next or head accordingly.
   */
  if (curr && curr->exp == exp) {
    curr->coeff += coeff;
    free(newTerm);
    if (curr->coeff == 0) {
      if (prev)
        prev->next = curr->next;
      else
        poly->head = curr->next;
      free(curr);
    }
  } else {
    newTerm->next = curr;
    if (prev)
      prev->next = newTerm;
    else
      poly->head = newTerm;
  }
}

void print_polynomial(Polynomial poly) {
  Term *curr = poly.head;
  if (!curr) {
    printf("0\n");
    return;
  }
  while (curr) {
    printf("%d", curr->coeff);
    if (curr->exp != 0)
      printf("x^%d", curr->exp);
    if (curr->next && curr->next->coeff > 0)
      printf(" + ");
    else if (curr->next && curr->next->coeff < 0)
      printf(" ");
    curr = curr->next;
  }
  printf("\n");
}

Polynomial add_polynomials(Polynomial a, Polynomial b) {
  Polynomial result = create_polynomial();
  Term *p = a.head;
  Term *q = b.head;
  while (p || q) {
    if (!q || (p && p->exp > q->exp)) {
      add_term(&result, p->coeff, p->exp);
      p = p->next;
    } else if (!p || q->exp > p->exp) {
      add_term(&result, q->coeff, q->exp);
      q = q->next;
    } else {
      add_term(&result, p->coeff + q->coeff, p->exp);
      p = p->next;
      q = q->next;
    }
  }
  return result;
}

void free_polynomial(Polynomial *poly) {
  Term *curr = poly->head;
  while (curr) {
    Term *next = curr->next;
    free(curr);
    curr = next;
  }
  poly->head = NULL;
}
