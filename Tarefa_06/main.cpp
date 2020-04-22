#include <iostream>
#include <cmath>

using namespace std;

double function(double x) {
    return pow((sin(2*x) + 4*pow(x,2) + 3*x), 2);
}

void gaussHermite2() {
  double x[2];
  x[0] = -0.707106;
  x[1] = 0.707106;

  double w[2];
  w[0] = 0.8862269;
  w[1] = 0.8862269;

  double res = 0;
  for (int i = 0; i < 2; i++) {
    res += w[i] * function(x[i]);
  }

  cout << "Gauss-Hermite com n = 2" << endl;
  cout << "Resultado: " << res << endl;
}

void gaussHermite3() {
  double x[3];
  x[0] = -1.224744;
  x[1] = 0;
  x[2] = 1.224744;

  double w[3];
  w[0] = 0.295408;
  w[1] = 1.181636;
  w[2] = 0.295408;

  double res = 0;
  for (int i = 0; i < 3; i++) {
    res += w[i] * function(x[i]);
  }

  cout << "Gauss-Hermite com n = 3" << endl;
  cout << "Resultado: " << res << endl;
}

void gaussHermite4() {
  double x[4];
  x[0] = -1.6507;
  x[1] = -0.52465;
  x[2] = 0.52465;
  x[3] = 1.6507;

  double w[4];
  w[0] = 0.0813;
  w[1] = 0.80491;
  w[2] = 0.80491;
  w[3] = 0.0813;

  double res = 0;
  for (int i = 0; i < 4; i++) {
    res += w[i] * function(x[i]);
  }

  cout << "Gauss-Hermite com n = 4" << endl;
  cout << "Resultado: " << res << endl;
}

void gaussLaguerre2() {
  double x[2];
  x[0] = 0.227546;
  x[1] = 3.772453;

  double w[2];
  w[0] = 0.943113;
  w[1] = 0.056886;

  double res = 0;
  for (int i = 0; i < 2; i++) {
    res += w[i] * function(x[i]);
  }

  cout << "Gauss-Laguerre com n = 2" << endl;
  cout << "Resultado: " << res << endl;
}

void gaussLaguerre3() {
  double x[3];
  x[0] = 0.415774;
  x[1] = 2.294280;
  x[2] = 6.289945;

  double w[3];
  w[0] = 0.711093;
  w[1] = 0.278517;
  w[2] = 0.010389;

  double res = 0;
  for (int i = 0; i < 3; i++) {
    res += w[i] * function(x[i]);
  }

  cout << "Gauss-Laguerre com n = 3" << endl;
  cout << "Resultado: " << res << endl;
}

void gaussLaguerre4() {
  double x[4];
  x[0] = 0.32255;
  x[1] = 1.7258;
  x[2] = 4.5366;
  x[3] = 9.3951;

  double w[4];
  w[0] = 0.60315;
  w[1] = 0.35742;
  w[2] = 0.03889;
  w[3] = 0.00054;

  double res = 0;
  for (int i = 0; i < 4; i++) {
    res += w[i] * function(x[i]);
  }

  cout << "Gauss-Laguerre com n = 4" << endl;
  cout << "Resultado: " << res << endl;
}

void gaussChebyshev2() {
  double x[2];
  x[0] = -0.707106;
  x[1] = 0.707106;

  double w[2];
  w[0] = M_PI/2;
  w[1] = M_PI/2;

  double res = 0;
  for (int i = 0; i < 2; i++) {
    res += w[i] * function(x[i]);
  }

  cout << "Gauss-Chebyshev com n = 2" << endl;
  cout << "Resultado: " << res << endl;
}

void gaussChebyshev3() {
  double x[3];
  x[0] = -0.866025;
  x[1] = 0;
  x[2] = 0.866025;

  double w[3];
  w[0] = M_PI/3;
  w[1] = M_PI/3;
  w[2] = M_PI/3;

  double res = 0;
  for (int i = 0; i < 3; i++) {
    res += w[i] * function(x[i]);
  }

  cout << "Gauss-Chebyshev com n = 3" << endl;
  cout << "Resultado: " << res << endl;
}

void gaussChebyshev4() {
  double x[4];
  x[0] = -0.92387;
  x[1] = -0.38268;
  x[2] = 0.38268;
  x[3] = 0.92387;

  double w[4];
  w[0] = M_PI/4;
  w[1] = M_PI/4;
  w[2] = M_PI/4;
  w[3] = M_PI/4;

  double res = 0;
  for (int i = 0; i < 4; i++) {
    res += w[i] * function(x[i]);
  }

  cout << "Gauss-Chebyshev com n = 4" << endl;
  cout << "Resultado: " << res << endl;
}

int main() {
  cout << "Função: f(x) = (sen(2x) + 4x² + 3x)²" << endl << endl;

  gaussHermite2();

  cout << endl;

  gaussHermite3();

  cout << endl;

  gaussHermite4();

  cout << endl;

  gaussLaguerre2();

  cout << endl;

  gaussLaguerre3();

  cout << endl;

  gaussLaguerre4();

  cout << endl;

  gaussChebyshev2();

  cout << endl;

  gaussChebyshev3();

  cout << endl;

  gaussChebyshev4();

  cout << endl;

  return 0;
}