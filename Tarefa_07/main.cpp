#include <iostream>
#include <cmath>

using namespace std;

double function1(double x) {
  return 1.0/pow(pow(x, 2), 1/3.0);
}


double transformedFunction_Simple1(double a, double b, double s) {
  double xs = ((a+b)/2.0) + ((b-a)/2.0) * tanh(s);
  double dx = ((b-a)/2.0) * (1.0/pow(cosh(s), 2.0));
  return function1(xs) * dx;
}

double transformedFunction_Double1(double a, double b, double s) {
  double xs = ((a + b) / 2.0) + ((b - a) / 2.0) * tanh((M_PI / 2.0) * sinh(s));
  double dx = ((b - a) / 2.0) * ((M_PI / 2.0) * (cosh(s) / pow(cosh((M_PI / 2.0) * sinh(s)), 2.0)));
  return function1(xs) * dx;
}

void opened4Simple_Function1(double a, double b, double c, double e) {
  double err = 1.0, res = 0.0, aux, n = 1, delta, h, Xi, count;
  double negativeC = -c;
  while (err > e) {
    aux = res;
    delta = (c - negativeC)/n;
    h = delta/6.0;
    res = 0.0;

    for(int i = 0; i < n; i++) {
      Xi = negativeC + i*delta;
      res += (6.0*h/20.0)*(11.0*transformedFunction_Simple1(a, b, Xi + h) - 14.0*transformedFunction_Simple1(a, b, Xi + 2.0*h) + 26.0*transformedFunction_Simple1(a, b, Xi+ 3.0*h)
      - 14.0*transformedFunction_Simple1(a, b, Xi + 4.0*h) + 11.0*transformedFunction_Simple1(a, b, Xi + 5.0*h));
    }

    count++;
    err = abs((res - aux)/res);
    n *= 2.0;
  }

  cout << "Função 1 com exponencial simples" << endl;
  cout << "Resultado: " << 2 * res << endl;
  cout << "Iterações: " << count << endl;
  cout << "C: " << c << endl << endl;
}

void opened4Double_Function1(double a, double b, double c, double e) {
  double err = 1.0, res = 0.0, aux, n = 1, delta, h, Xi, count;
  double negativeC = -c;
  while (err > e) {
    aux = res;
    delta = (c - negativeC)/n;
    h = delta/6.0;
    res = 0.0;

    for(int i = 0; i < n; i++) {
      Xi = negativeC + i*delta;
      res += (6.0*h/20.0)*(11.0*transformedFunction_Double1(a, b, Xi + h) - 14.0*transformedFunction_Double1(a, b, Xi + 2.0*h) + 26.0*transformedFunction_Double1(a, b, Xi+ 3.0*h)
      - 14.0*transformedFunction_Double1(a, b, Xi + 4.0*h) + 11.0*transformedFunction_Double1(a, b, Xi + 5.0*h));
    }

    count++;
    err = abs((res - aux)/res);
    n *= 2.0;
  }

  cout << "Função 1 com exponencial dupla" << endl;
  cout << "Resultado: " << 2 * res << endl;
  cout << "Iterações: " << count << endl;
  cout << "C: " << c << endl << endl;
}

double function2(double x) {
  return 1.0/(sqrt(4.0 - x*x));
}

double transformedFunction_Simple2(double a, double b, double s) {
  double xs = ((a+b)/2.0) + ((b-a)/2.0) * tanh(s);
  double dx = ((b-a)/2.0) * (1.0/pow(cosh(s), 2.0));
  return function2(xs) * dx;
}

double transformedFunction_Double2(double a, double b, double s) {
  double xs = ((a + b) / 2.0) + ((b - a) / 2.0) * tanh((M_PI / 2.0) * sinh(s));
  double dx = ((b - a) / 2.0) * ((M_PI / 2.0) * (cosh(s) / pow(cosh((M_PI / 2.0) * sinh(s)), 2.0)));
  return function2(xs) * dx;
}

void opened4Simple_Function2(double a, double b, double c, double e) {
  double err = 1.0, res = 0.0, aux, n = 1, delta, h, Xi, count;
  double negativeC = -c;
  while (err > e) {
    aux = res;
    delta = (c - negativeC)/n;
    h = delta/6.0;
    res = 0.0;

    for(int i = 0; i < n; i++) {
      Xi = negativeC + i*delta;
      res += (6.0*h/20.0)*(11.0*transformedFunction_Simple2(a, b, Xi + h) - 14.0*transformedFunction_Simple2(a, b, Xi + 2.0*h) + 26.0*transformedFunction_Simple2(a, b, Xi+ 3.0*h)
      - 14.0*transformedFunction_Simple2(a, b, Xi + 4.0*h) + 11.0*transformedFunction_Simple2(a, b, Xi + 5.0*h));
    }

    count++;
    err = abs((res - aux)/res);
    n *= 2.0;
  }

  cout << "Função 2 com exponencial simples" << endl;
  cout << "Resultado: " << res << endl;
  cout << "Iterações: " << count << endl;
  cout << "C: " << c << endl << endl;
}

void opened4Double_Function2(double a, double b, double c, double e) {
  double err = 1.0, res = 0.0, aux, n = 1, delta, h, Xi, count;
  double negativeC = -c;
  while (err > e) {
    aux = res;
    delta = (c - negativeC)/n;
    h = delta/6.0;
    res = 0.0;

    for(int i = 0; i < n; i++) {
      Xi = negativeC + i*delta;
      res += (6.0*h/20.0)*(11.0*transformedFunction_Double2(a, b, Xi + h) - 14.0*transformedFunction_Double2(a, b, Xi + 2.0*h) + 26.0*transformedFunction_Double2(a, b, Xi+ 3.0*h)
      - 14.0*transformedFunction_Double2(a, b, Xi + 4.0*h) + 11.0*transformedFunction_Double2(a, b, Xi + 5.0*h));
    }

    count++;
    err = abs((res - aux)/res);
    n *= 2.0;
  }

  cout << "Função 2 com exponencial dupla" << endl;
  cout << "Resultado: " << res << endl;
  cout << "Iterações: " << count << endl;
  cout << "C: " << c << endl << endl;
}

int main() {
  cout << "Função 1: f(x) = 1/³√x²" << endl << endl;

  opened4Simple_Function1(0, 1, 9, 0.000001);
  opened4Double_Function1(0, 1, 2.5, 0.000001);

  cout << "Função 2: f(x) = 1/√(4-x²)" << endl << endl;

  opened4Simple_Function2(-2, 0, 9, 0.000001);
  opened4Double_Function2(-2, 0, 2.5, 0.000001);
  

  return 0;
}