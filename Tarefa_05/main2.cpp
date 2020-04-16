#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) {
    return pow((sin(2*x) + 4*pow(x,2) + 3*x), 2);
}


double x(double ak, double Xi, double Xf){
  return (Xi + Xf)/2 + ((Xf - Xi)/2)*ak;
}

double integralTolerancia(double a_, double b_, double tol_)
{

  double w[3], a[3];

  a[0] = -0.7745966692;
  a[1] = 0;
  a[2] = -a[0];

  w[0] = 0.5555555555;
  w[1] = 0.8888888888;
  w[2] = w[0];

    double Iv, In = 0,
               delta, sum,
               xi, xf, tol = 1;
    int count, N = 1;

    do
    {
        Iv = In;
        In = 0;
        count = 0;

        delta = (b_ - a_) / N;

        while (count < N)
        {
            xi = a_ + count * delta;
            xf = xi + delta;
            sum = 0;

            for (int k = 0; k < 3; k++)
                sum += (w[k] * f(x(a[k], xi, xf)));

            In += ((xf - xi) / 2) * sum;
            count++;
        }

        N *= 2;
        tol = (double)fabs((In - Iv) / In);

    } while (tol > tol_);

    cout << "Número de iterações: " << count << endl
         << "Integral = ";

    return In;
}

int main() {
  double b = 1;
  double a = 0;
  double err = 0.000001;

  double res;

  cout << "Gauss-Legendre com 3 pontos de interpolação: ";
  res = integralTolerancia(a, b, err);
  cout << res << endl;

  return 0;
}