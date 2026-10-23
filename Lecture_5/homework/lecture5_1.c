#include<stdio.h>
#include<math.h>
float sigmoid(float x);
float ReLU(float x);
float tanh_1(float x);
float leaky_ReLU(float x);

int main(){
    float a = -0.5, b = 9, c;
    // sigmoid
    c = sigmoid(a);
    printf("sigmoid(%f) = %f\n",a, c);
    c = sigmoid(b);
    printf("sigmoid(%f) = %f\n",b, c);

    // tanh
    c = tanh_1(a);
    printf("tanh(%f) = %f\n",a, c);
    c = tanh_1(b);
    printf("tanh(%f) = %f\n",b, c);

    // ReLU
    c = ReLU(a);
    printf("ReLU(%f) = %f\n",a, c);
    c = ReLU(b);
    printf("ReLU(%f) = %f\n",b, c);

    // Leaky_ReLU
    c = leaky_ReLU(a);
    printf("leaky_ReLU(%f) = %f\n",a, c);
    c = leaky_ReLU(b);
    printf("leaky_ReLU(%f) = %f\n",b, c);

    return 0;
}

float sigmoid(float x){
    float y;
    y = 1/(1+exp(-x));
    return y;
}

float ReLU(float x){
    float y;
    y = x > 0 ? x:0;
    return y;
}

float tanh_1(float x){
    float y;
    y = (exp(x)-exp(-x))/(exp(x)+exp(-x));
    return y;
}

float leaky_ReLU(float x){
    float y;
    y = x > 0.01*x ? x:0.01*x;
    return y;
}
