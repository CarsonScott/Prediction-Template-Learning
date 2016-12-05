#include "Network.hpp"

Vector Network::updatePrediction(Vector in, Vector temp, float discount)
{
    Vector p;
    for(int i = 0; i < temp.size(); i++)
    {
        float value = temp[i] + discount*learning_rate*(in[i] - temp[i]);
        p.push_back(value);
    }
    return p;
}

Network::Network(int input_length, float rate)
{
    input = createVector(input_length, 0);
    threshold = 10;
    decay_rate = 1/pow(10, 5);

    learning_rate = rate;
    current_error = 0;
    prediction = 0;
}

void Network::setThreshold(float t)
{
    threshold = t;
}

void Network::createTemplates(int temps)
{
    for(int i = 0; i < temps; i++)
    {
        VPair vp;
        vp.first = createVector(input.size(), 0);
        vp.second = createVector(input.size(), 0);
        templates.push_back(vp);

        discounts.push_back(1);
    }
}

void Network::update(Vector in)
{
    input = in;
    templates[prediction].second = updatePrediction(input, templates[prediction].second, discounts[prediction]);

    int best_discount = 0;
    int best_prediction = 0;
    float lowest_error = -1;

    for(int i = 0; i < templates.size(); i++)
    {
        float error = computeError(input, templates[i].first);
        if(error < lowest_error || lowest_error == -1)
        {
            lowest_error = error;
            best_prediction = i;
        }

        if(discounts[i] > discounts[best_discount])
            best_discount = i;
    }

    if(lowest_error > threshold*discounts[best_prediction])
    {
        prediction = best_discount;
        current_error = computeError(input, templates[prediction].first);
    }
    else
    {
        prediction = best_prediction;
        current_error = lowest_error;
    }

    templates[prediction].first = updatePrediction(input, templates[prediction].first, discounts[prediction]);

    learning_rate -= decay_rate;
    if(learning_rate < 0)
    {
        learning_rate = 0;
    }

    discounts[prediction] -= decay_rate;
    if(discounts[prediction] < 0)
    {
        discounts[prediction] = 0;
    }
}

float Network::getError()
{
    return current_error;
}

Vector Network::getPredictedState()
{
    return templates[prediction].second;
}
