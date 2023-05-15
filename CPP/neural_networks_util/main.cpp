#include "./functions.cpp"
#include <iostream>

class weight;

class neuron {
 public: 
  weight * weights;
  weight * back_connections;
  float bias = 0;
  float value = 0;
  int iterations = 0;
  int function_type = 0; //0 is linear
};

class weight {
 public: 
  float weight_val = 0;
  /*neuron * neuron_o;
  neuron * neuron_t;*/
  int neuron_o;
  int neuron_t; 
};

class layer {
 public:
  neuron  * neurons;
};

class neural_network {
 public:
  layer * layers;
  int * cooked_neural_network;

  /*Neuron data*/



  void cook_neural_network(){};
};

void neural_network::cook_neural_network() /*
This is a form of compiler for neural networks
It helps to "cook" the neural network so it's easier and faster to process instead of the slow grinding through 2d array.
That method creates a new array, which has written indexes of the weights that were activated in chronological order and stores it inside of the
class object.
*/
{
    
}

int main()
{

 func_math[0] = to_linear; 
 func_math[1] = to_sigmoid;
 func_math[2] = to_bin;
 func_math[3] = to_tanh;
 func_math[4] = to_RELU;

 float v_a = 0.5;
 float * v_p = &v_a;
 float * p = new float;
 func_math[1](v_p,p);
 std::cout << *p;
}


