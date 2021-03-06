#pragma once

#include "Rational.hpp"

#include <Eigen/Core>

namespace eccd
{

typedef Eigen::Matrix<Rational, 3, 1> Vector3r;
typedef Eigen::Matrix<double, 3, 1> Vector3d;

template <typename V1, typename V2>
Vector3r cross(const V1 &v1, const V2 &v2)
{
    Vector3r res;
    res[0] = v1[1] * v2[2] - v1[2] * v2[1];
    res[1] = v1[2] * v2[0] - v1[0] * v2[2];
    res[2] = v1[0] * v2[1] - v1[1] * v2[0];

    return res;
}

template<typename V>
void print(const V &v)
{
    std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;
}

void write(const Vector3d &v, std::ostream &out);
Vector3d read(std::istream &in);

int orient3d(const Vector3r &a, const Vector3r &b, const Vector3r &c, const Vector3r &d);

int origin_ray_triangle_inter(const Vector3d &dir, const Vector3r &t1, const Vector3r &t2, const Vector3r &t3);

bool segment_segment_inter(const Vector3r &s0, const Vector3r &e0, const Vector3r &s1, const Vector3r &e1, Vector3r &res, int axis);

int segment_triangle_inter(const Vector3d &e0, const Vector3d &e1, const Vector3d &t1, const Vector3d &t2, const Vector3d &t3);

} // namespace eccd
