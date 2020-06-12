#include <iostream>

#include "otcos/otcos.hxx"

using namespace OT;
using namespace OTCOS;

int main()
{
  const Point amplitude(1, 1.0);
  const Point scale(1, 1.0);
  const Scalar alpha = 1.36;
  CosineCovarianceModel cosine(scale, amplitude, alpha);
  std::cout << cosine << std::endl;
  return 0;
}

