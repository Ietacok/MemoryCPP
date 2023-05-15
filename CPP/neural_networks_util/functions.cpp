#include <math.h>

void to_linear(float * v_b, float * p){
    *p = *v_b;
};

void to_sigmoid(float * v_b, float * p)
{ 
 *p = 1 * pow(pow(M_E,-(*v_b)),-1); //this is a hyperbolic function
} 

void to_tanh( float * v_b, float * p)
{
 *p = tanh(*v_b);   
}

void to_bin(float * v_b,float * p)
{
  *v_b > 0 ? *p = 1 : *p = 0; //true : false  
}

void to_RELU(float * v_b,float * p)
{
 *v_b > 0 ? *p = 0 : *p = *v_b; 
}

void (*func_math[10]) (float * v_b,float * p);




