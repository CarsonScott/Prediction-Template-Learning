#ifndef NETWORK_HPP_INCLUDED
#define NETWORK_HPP_INCLUDED

#include "Vector.hpp"

class Network
{
    Vector input;
    int max_templates;
    float learning_rate;
    float decay_rate;
    float threshold;
    float current_error;
    VRelation templates;
    Vector discounts;
    int prediction;

    void createTemplate(Vector);
    Vector updatePrediction(Vector, Vector, float);
public:
    Network(int, int, float);
    void setThreshold(float);
    void setTemplates(int);
    void train(Vector);
    float getError();
    Vector getPrediction();
    std::vector<Vector> computePredictions(Vector, int);
};

#endif // NETWORK_HPP_INCLUDED
