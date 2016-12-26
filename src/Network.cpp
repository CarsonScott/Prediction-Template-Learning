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

void Network::createTemplate(Vector initial)
{
    VPair temp;
    temp.first = initial;
    temp.second = createVector(input.size(), 0);
    templates.push_back(temp);
    discounts.push_back(1);
}

Network::Network(int input_length, int max_temps, float rate)
{
    input = createVector(input_length, 0);
    max_templates = max_temps;
    threshold = 0;
    decay_rate = 0.000001;
    learning_rate = rate;
    current_error = 0;
    prediction = 0;
}

void Network::setThreshold(float t)
{
    threshold = t;
}

std::vector<Vector> Network::computePredictions(Vector in, int predictions)
{
    Vector x = in;
    std::vector<Vector> chain;

    for(int j = 0; j < predictions; j++)
    {
        int best = 0;
        float error = -1;
        for(int i = 0; i < templates.size(); i++)
        {
            float e = computeError(x, templates[i].first);
            if(e < error || error == -1)
            {
                error = e;
                best = i;
            }
        }
        x = templates[best].second;
        chain.push_back(x);
    }
    return chain;
}

void Network::train(Vector in)
{
    input = in;
    if(templates.size() == 0)
    {
        createTemplate(input);
    }

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
        {
            best_discount = i;
        }

        discounts[i] += decay_rate/max_templates;
    }

    if(lowest_error > threshold*discounts[best_prediction])
    {
        if(templates.size() >= max_templates)
        {
            prediction = best_discount;
        }
        else
        {
            createTemplate(input);
            prediction = templates.size()-1;
        }
        current_error = computeError(input, templates[prediction].first);
    }
    else
    {
        prediction = best_prediction;
        current_error = lowest_error;
    }

    discounts[prediction] -= decay_rate;
    if(discounts[prediction] < 0)
    {
        discounts[prediction] = 0;
    }

    templates[prediction].first = updatePrediction(input, templates[prediction].first, discounts[prediction]);
}

float Network::getError()
{
    return current_error;
}

Vector Network::getPrediction()
{
    return templates[prediction].second;
}
