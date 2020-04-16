#include <iostream>
#include <cmath>

using namespace std;

double function(double x) {
    return pow((sin(2*x) + 4*pow(x,2) + 3*x), 2);
}

double xak(double Xi, double Xf, double ak){
  return (Xi + Xf)/2 + ((Xf - Xi)/2)*ak;
}

double fxak(double Xi, double Xf, double ak){
  return function((xak(Xi, Xf, ak)));
}

void gaussLegendre2(double a, double b, double err) {
    double aux, res = 0, delta, sum, Xi, Xf;
    int count, n = 1;

    double alpha[2];
    alpha[0] = -0.5773502;
    alpha[1] = 0.5773502;

    double w[2];
    w[0] = 1;
    w[1] = 1;

   while (abs((res - aux) / res) > err) {
    aux = res;
    delta = (b - a)/n;
    res = 0;
    count = 0;

    for(int i = 0; i < n; i++) {
      Xi = a + i * delta;
      Xf = Xi + delta;
      sum = 0;

      for (int k = 0; k < 2; k++){
        sum += (fxak(Xi, Xf, alpha[k]) * w[k]);
      }

      res += (Xf - Xi)/2 * sum;
      count++;
    }
    n *= 2;
  }
    cout << "Gauss-Legendre com 2 pontos de interpolação" << endl;
    cout << "Iterações: " << count << endl;
    cout << "Resultado: " << res << endl;
}

void gaussLegendre3(double a, double b, double err) {
    double aux, res = 0, delta, sum, Xi, Xf;
    int count, n = 1;

    double alpha[3];
    alpha[0] = -0.7745966692;
    alpha[1] = 0;
    alpha[2] = -alpha[0];

    double w[3];
    w[0] = 0.5555555555;
    w[1] = 0.8888888888;
    w[2] = w[0];

   while (abs((res - aux) / res) > err) {
    aux = res;
    delta = (b - a)/n;
    res = 0;
    count = 0;

    for(int i = 0; i < n; i++) {
      Xi = a + i * delta;
      Xf = Xi + delta;
      sum = 0;

      for (int k = 0; k < 3; k++){
        sum += (fxak(Xi, Xf, alpha[k]) * w[k]);
      }

      res += (Xf - Xi)/2 * sum;
      count++;
    }
    n *= 2;
  }
    cout << "Gauss-Legendre com 3 pontos de interpolação" << endl;
    cout << "Iterações: " << count << endl;
    cout << "Resultado: " << res << endl;
}

int main() {
  double b = 1;
  double a = 0;
  double err = 0.000001;

  gaussLegendre2(a, b, err);

  cout << endl;
  
  gaussLegendre3(a, b, err);

  cout << endl;
}