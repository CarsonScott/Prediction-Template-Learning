#include "Vector.hpp"

Vector operator *(Vector a, Vector b)
{
    Vector v;
    for(int i = 0; i < a.size(); i++)
    {
        v.push_back(a[i] * b[i]);
    }
    return v;
}

Vector operator -(Vector a, Vector b)
{
    Vector v;
    for(int i = 0; i < a.size(); i++)
    {
        v.push_back(a[i] - b[i]);
    }
    return v;
}

Vector createVector(int length, float value)
{
    Vector v;
    for(int i = 0; i < length; i++)
    {
        v.push_back(value);
    }
    return v;
}

float computeSum(Vector v)
{
    float sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}

float computeError(Vector a, Vector b)
{
    float error = 0;
    for(int i = 0; i < a.size(); i++)
    {
        error += pow(a[i]-b[i], 2);
    }
    return error/a.size();
}
