#include <stdio.h>
#include <stdlib.h>
#include "pbPlots.h"
#include "supportLib.h"

/*

Say that we have two tensors of:
 - X: 1, 2, 3, 4, 5, 6
 - Y: 2, 4, 6, 8, 10, 12

and a device to find the relationship between the two tensors:

f = w * x + b
 - in this case f = 2 * x

*/

// given the x and w, gets the result: result
float* forward(float* x, float w, size_t size){
    float* result = calloc(size, sizeof(float));
    for(size_t i = 0; i < size; i++){
        result[i] = x[i] * w;
    }
    return result;
}

/*
    calculates the mean squared error (derived as function below) as the cost function

    n: size of the data

    C(observed, predicted) = 1/n sum((yi - ypred)^2) 
*/
float cost(float* observed, float* predicted, size_t size){
    float result = 0;
    for(size_t i = 0; i < size; i++){
        float error = observed[i] - predicted[i];
        result += (error * error);
    }
    return result/size;
}

/*
    using the gradient descent algorithm, solve for the gradient

*/
float gradient(float* x, float* Y, float* YPred, size_t size){
    float result = 0;
    for(size_t i = 0; i < size; i++ ){
        float error = Y[i] - YPred[i];
        result += (error * x[i]);
    }
    return (-2 * result) / size;
}

float randFloat(void){
    return (float) rand() / (float) RAND_MAX;
}

int main() {

    // change srand
    srand(42);

    // x and Y in/out
    float x[] = {1, 2, 3, 4, 5, 6};
    float Y[] = {2, 4, 6, 8, 10, 12};
    int dataSize = 6;

    // the W that changes
    float w = randFloat() * 10.0f;

    printf("Starting W: %f\n", w);

    // training
    float learningRate = 1e-3;
    size_t totalEpochs = 100;

    double* xs = calloc(totalEpochs, sizeof(double));
    double* ys = calloc(totalEpochs, sizeof(double));

    for(size_t epoch = 0; epoch < totalEpochs; epoch++){
        // predict = forward pass
        float* yPred = forward(x, w, dataSize);

        // getting the loss/cost
        float loss = cost(Y, yPred, dataSize);

        // calculate the gradients
        float grad = gradient(x, Y, yPred, dataSize);

        // update the weights due to the loss
        w -= learningRate * grad;

        if(epoch % 10 == 0){
            printf("Epoch: %d, Loss: %f, W: %f\n", epoch, loss, w);
        }

        xs[epoch] = (double) epoch;
        ys[epoch] = (double) loss;
        
        free(yPred);
    }

    //for(size_t i = 0; i < totalEpochs; i++){
    //    printf("%lf : %lf\n", xs[i], ys[i]);
    //}

    // plot
    
	_Bool success;

	StartArenaAllocator();

	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
	StringReference *errorMessage = CreateStringReference(L"", 0);
	success = DrawScatterPlot(canvasReference, 1200, 800, xs, totalEpochs, ys, totalEpochs, errorMessage);

	if(success){
		ByteArray *pngdata = ConvertToPNG(canvasReference->image);
		WriteToFile(pngdata, "result.png");
		DeleteImage(canvasReference->image);
	}else{
		fprintf(stderr, "Error: ");
		for(int i = 0; i < errorMessage->stringLength; i++){
			fprintf(stderr, "%c", errorMessage->string[i]);
		}
		fprintf(stderr, "\n");
	}

	FreeAllocations();
    
    // free xs and ys
    free(xs);
    free(ys);

    return 0;
}