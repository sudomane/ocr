/**
 * @file    utils.h
 * @author  Philippe Bouchet (philippe.bouchet@epita.fr)
 * @brief   Utility functions, mathematical formulas, etc...
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef UTILS_H
#define UTILS_H

double normalized_rand(void);
double sigmoid(double x);
double d_sigmoid(double x);
double relu(double x);
double d_relu(double x);

#endif // UTILS_H