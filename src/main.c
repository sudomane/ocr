#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "network.h"
#include "matrix.h"
#include "utils.h"

#define IMAGE_DATA "data/train-images-idx3-ubyte"
#define LABEL_DATA "data/train-labels-idx1-ubyte"

int main(int argc, char* argv[])
{
	if (argc != 1 && argc != 3)
	{
		errx(-42, "Correct usage:\n\t./main (no arguments, default MNIST in data/)"
				  "\n\t./main [MNIST IMAGE PATH] [MNIST LABEL PATH]");
	}

	const char* image_data = IMAGE_DATA;
	const char* label_data = LABEL_DATA;

	if (argc == 3)
	{
		image_data = argv[1];
		label_data = argv[2];
	}
	
	srand(0);

	size_t L = 3;
	size_t input_size = 784;
	size_t hidden_size = 16;
	size_t output_size = 10;
	
	size_t n_data = 1;
	size_t batch_size = 32;
	double lr = 0.1f;
	
	dataset_t* data = data_init(n_data, input_size, output_size);
	network_t* net = net_init(L, input_size, hidden_size, output_size, batch_size, lr);
	
	data_load_mnist(image_data, data, LOAD_IMAGES);
	data_load_mnist(label_data, data, LOAD_LABELS);

	data_display(data);
	//net_train(net, data, 100);

	net_free(net);
	data_free(data);

	return 0;
}