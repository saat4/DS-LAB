// ADD 2 POLY :
// Write a C++ program to add two polynomial using linked list
// 5x^4+ 3x^3+ 2x^2+ 7x^1+ 5x^0
// 3x^4+ 7x^2+ 8x^0
// 8x^4+ 3x^3+ 9x^2+ 7x^1+ 13x^0

#include <iostream>
using namespace std;
class Term {
public:
    int coeff;
    int exp;
    Term *next;
    Term(int c, int e) {
        coeff = c;
        exp = e;
        next = NULL;
    }
    void display() {
        if (next == NULL) {
            cout << coeff << " " << endl;
        } else if (exp == 1) {
            cout << coeff << "x + ";
        } else {
            cout << coeff << "x^" << exp << " + ";
        }
    }
};
class Polynomial {
public:
    Term *hptr = NULL;
    void append(int c, int e) {
        if (hptr == NULL) {
            Term *temp = new Term(c, e);
            hptr = temp;
        } else {
            Term *temp = hptr;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            Term *nptr = new Term(c, e);
            temp->next = nptr;
        }
    }
    void display() {
        Term *temp = hptr;
        while (temp != NULL) {
            temp->display();
            temp = temp->next;
        }
    }
    Polynomial add(Polynomial pl) {
        Polynomial pr;
        Term *t1, *t2;
        t1 = hptr;
        t2 = pl.hptr;
        while (t1 != NULL && t2 != NULL) {
            if (t1->exp == t2->exp) {
                pr.append((t1->coeff) + (t2->coeff), t1->exp);
                t1 = t1->next;
                t2 = t2->next;
            } else if (t1->exp < t2->exp) {
                pr.append(t2->coeff, t2->exp);
                t2 = t2->next;
            } else if (t1->exp > t2->exp) {
                pr.append(t1->coeff, t1->exp);
                t1 = t1->next;
            }
        }
        if (t1 != NULL && t2 == NULL) {
            while (t1 != NULL) {
                pr.append(t1->coeff, t1->exp);
                t1 = t1->next;
            }
        } else if (t2 != NULL && t1 == NULL) {
            while (t2 != NULL) {
                pr.append(t2->coeff, t2->exp);
                t2 = t2->next;
            }
        }
        return pr;
    }
};

int main() {
    Polynomial p, p1, p2;
    p.append(5, 4);
    p.append(3, 3);
    p.append(2, 2);
    p.append(7, 1);
    p.append(5, 0);
    p.display();
    p1.append(3, 4);
    p1.append(7, 2);
    p1.append(8, 0);
    p1.display();
    p2 = p1.add(p);
    p2.display();
    // 5x^4+3x^3+2x^27x+5
    return 0;
}