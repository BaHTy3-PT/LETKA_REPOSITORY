#ifndef SOLVER_H
#define SOLVER_H

#include <math.h>

const double ACCURACY = 0.0001; //Constant for comparing doubles

void SquareSolver(double coeff_1, double coeff_2, double coeff_3, double *x1_ptr, double *x2_ptr);
void LinearSolver(double coeff_2, double coeff_3, double *x1_ptr, double *x2_ptr);

#endif
