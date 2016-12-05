#ifndef NETWORK_HPP_INCLUDED
#define NETWORK_HPP_INCLUDED

#include "Vector.hpp"

class Network
{
    Vector input;
    float learning_rate;
    float decay_rate;
    float threshold;
    float current_error;
    VRelation templates;
    Vector discounts;
    int prediction;

    Vector updatePrediction(Vector, Vector, float);
public:
    Network(int, float);
    void setThreshold(float);
    void createTemplates(int);
    void update(Vector);
    float getError();
    Vector getPredictedState();
};

#endif // NETWORK_HPP_INCLUDED
