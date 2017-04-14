#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Network.hpp"

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Initialize network with input length and learning rate
    int input_length = 50;
    Network net(input_length, .4);
    
    // Set error threshold
    net.setThreshold(1);
    
    // Generate random input sequence
    int sequence_length = 200;
    Matrix inputs;
    
    for(int i = 0; i < sequence_length; i++)
    {
        Vector in;
        for(int j = 0; j < input_dim; j++)
        {
            float x = rand() % 10;

            in.push_back(x);
        }
        inputs.push_back(in);
    }
    
    // Create template memory
    net.createTemplates(sequence_length);

    // Train network using online prediction-correction
    int training_steps = 10;
    int iterations = inputs.size() * training_steps;
    int current_input = 0;
    
    for(int i = 0; i < iterations; i++){
        
        // Update network with current input
        net.update(inputs[current_input]);
        
        // Print prediction error
        std::cout << net.getError() << "\n";

        // Update current input
        current_input++;
        if(current_input == inputs.size()){
            current_input = 0;
        }
    }
    
    return 0;
}
