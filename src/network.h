#ifndef NETWORK_H
#define NETWORK_H

#define INPUT_SIZE 2
#define HIDDEN_SIZE 2
#define OUTPUT_SIZE 1  

#define N_HIDDEN_LAYER 1

#include "matrix.h"

typedef struct
{
    matrix_2D_t* activation_network; // Matrix containing activation values
    matrix_2D_t* weights_network; // Matrix containing weights for each layer
    
    double bias[N_HIDDEN_LAYER + 2]; // Bias for every hidden layer + output layer
} network_t;

network_t* init_network();
void free_network(network_t* network);
void display_network(network_t* network);

void init_weights(network_t* network);
void init_bias(network_t* network);
void init_input(network_t* network, double* input);

void feed_forward(network_t* network);


#endif // NETWORK_H