#include "Vector3D.h"
#include <iostream>
#include <string>

int main()
{
  double const PI = 3.14159265

  double Fx = 10.0 * std::cos(45*PI/180.0);
  double Fx = 10.0 * std::sin(45*PI/180.0);
  double Fz=0;

  double Dx = 10.0;
  double Dy = 0.0;
  double Dz = 0.0;

  Vector3D vec3dForce(Fx, Fy, Fz);
  Vector 3D vec3dDisplacement(Dx, Dy, Dz);

  vec3dForce.display();
  vec3dDisplacement.display();

  double dWork = vec3dForce.dot(vec3dDisplacement);
  std::cout << "Work: " << dWork << std::endl;

  return 0;
}


Vector3D::Vector3D()
{
  this->m_vector.at(0) = 0.0;
  this->m_vector.at(1) = 0.0;
  this->m_vector.at(2) = 0.0;
  return;
}

Vector3D::Vector3D(double dX, double dY, double dZ)
{
  this->m_vector.at(0) = dX;
  this->m_vector.at(1) = dY;
  this->m_vector.at(2) = dZ;
  return;
}

Vector3D::~Vector3D()
{
  this->m_vector.at(0) = 0.0;
  this->m_vector.at(1) = 0.0;
  this->m_vector.at(2) = 0.0;
  return;
}

void Vector3D::display()
{
  std::cout << this->m_vector.at(0) << " x, " << this->m_vector.at(1) <<  " y, " << this->m_vector.at(2) << " z " << std::endl;
}

double Vector3D::dot(Vector3D vec3d)
{
  double dDotProduct = 0.0;
  for (unsigned int i = 0; i < this->m_vector.size(); i++)
  {
    dDotProduct+= this->m_vector.at(i) * vec3D.m_vector.at(i);
  }
  return dDotProduct;
}
