#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <cmath>
#include <vector>

class Vector:public std::vector<float>{};
class Matrix:public std::vector<Vector>{};
struct VPair{Vector first; Vector second;};
class VRelation:public std::vector<VPair>{};

Vector operator *(Vector, Vector);
Vector operator -(Vector, Vector);
Vector createVector(int, float);
float computeSum(Vector);
float computeError(Vector, Vector);

#endif // VECTOR_HPP_INCLUDED
