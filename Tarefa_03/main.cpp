#include <iostream>
#include <cmath>

using namespace std;

double function(double x) {
    double res = pow((sin(2*x) + 4*pow(x,2) + 3*x), 2);
    return res;
}

double closed1(double a, double b, double e) {
  double err = 1, res = 0, aux, n = 1, delta, Xi;
  while (err > e) {
    aux = res;
    delta = (b - a)/n;
    res = 0;

    for(int i = 0; i < n; i++) {
      Xi = a + i*delta;
      res += (delta/2)*(function(Xi) + function(Xi + delta));
    }

    err = abs((res - aux)/res);
    n *= 2;
  }

  return res;
}

double closed2(double a, double b, double e) {
  double err = 1, res = 0, aux, n = 1, delta, h, Xi;
  while (err > e) {
    aux = res;
    delta = (b - a)/n;
    h = delta/2;
    res = 0;

    for(int i = 0; i < n; i++) {
      Xi = a + i*delta;
      res += (h/3)*(function(Xi) + 4*function(Xi + h) + function(Xi + 2*h));
    }

    err = abs((res - aux)/res);
    n *= 2;
  }
  return res;
}

double closed3(double a, double b, double e) {
  double err = 1, res = 0, aux, n = 1, delta, h, Xi;
  while (err > e) {
    aux = res;
    delta = (b - a)/n;
    h = delta/3;
    res = 0;

    for(int i = 0; i < n; i++) {
      Xi = a + i*delta;
      res += (3*h/8)*(function(Xi) + 3*function(Xi + h) + 3*function(Xi + 2*h) + function(Xi + 3*h));
    }

    err = abs((res - aux)/res);
    n *= 2;
  }
  return res;
}

double closed4(double a, double b, double e) {
  double err = 1, res = 0, aux, n = 1, delta, h, Xi;
  while (err > e) {
    aux = res;
    delta = (b - a)/n;
    h = delta/4;
    res = 0;

    for(int i = 0; i < n; i++) {
      Xi = a + i*delta;
      res += (2*h/45)*(7*function(Xi) + 32*function(Xi + h) + 12*function(Xi + 2*h) + 32*function(Xi + 3*h)
      + 7*function(Xi + 4*h));
    }

    err = abs((res - aux)/res);
    n *= 2;
  }
  return res;
}

double opened1(double a, double b, double e) {
  double err = 1, res = 0, aux, n = 1, delta, h, Xi;
  while (err > e) {
    aux = res;
    delta = (b - a)/n;
    h = delta/3;
    res = 0;

    for(int i = 0; i < n; i++) {
      Xi = a + i*delta;
      res += (delta/2)*(function(Xi + h) + function(Xi + 2*h));
    }

    err = abs((res - aux)/res);
    n *= 2;
  }
  return res;
}

double opened2(double a, double b, double e) {
  double err = 1, res = 0, aux, n = 1, delta, h, Xi;
  while (err > e) {
    aux = res;
    delta = (b - a)/n;
    h = delta/4;
    res = 0;

    for(int i = 0; i < n; i++) {
      Xi = a + i*delta;
      res += (4*h/3)*(2*function(Xi + h) - function(Xi + 2*h) + 2*function(Xi+ 3*h));
    }

    err = abs((res - aux)/res);
    n *= 2;
  }
  return res;
}

double opened3(double a, double b, double e) {
  double err = 1, res = 0, aux, n = 1, delta, h, Xi;
  while (err > e) {
    aux = res;
    delta = (b - a)/n;
    h = delta/5;
    res = 0;

    for(int i = 0; i < n; i++) {
      Xi = a + i*delta;
      res += (5*h/24)*(11*function(Xi + h) + function(Xi + 2*h) + function(Xi+ 3*h)
      + 11*function(Xi + 4*h));
    }

    err = abs((res - aux)/res);
    n *= 2;
  }
  return res;
}

double opened4(double a, double b, double e) {
  double err = 1, res = 0, aux, n = 1, delta, h, Xi;
  while (err > e) {
    aux = res;
    delta = (b - a)/n;
    h = delta/6;
    res = 0;

    for(int i = 0; i < n; i++) {
      Xi = a + i*delta;
      res += (6*h/20)*(11*function(Xi + h) - 14*function(Xi + 2*h) + 26*function(Xi+ 3*h)
      - 14*function(Xi + 4*h) + 11*function(Xi + 5*h));
    }

    err = abs((res - aux)/res);
    n *= 2;
  }
  return res;
}

int main() {
  double b;
  double a;
  double e;

  cout << "Entre o limite inferior a" << endl;
  cin >> a;
  cout << "Entre o limite superior b" << endl;
  cin >> b;
  cout << "Entre o erro e" << endl;
  cin >> e;


  cout << "f(x) = (sen(2x) + 4x² + 3x³)²" << endl << endl;
  double resClosed1 = closed1(a, b, e);
  cout << "fechada grau 01: " << resClosed1 << endl;
  double resClosed2 = closed2(a, b, e);
  cout << "fechada grau 02: " << resClosed2 << endl;
  double resClosed3 = closed3(a, b, e);
  cout << "fechada grau 03: " << resClosed3 << endl;
  double resClosed4 = closed4(a, b, e);
  cout << "fechada grau 04: " << resClosed4 << endl << endl;
  double resOpened1 = opened1(a, b, e);
  cout << "aberta grau 01: " << resOpened1 << endl;
  double resOpened2 = opened2(a, b, e);
  cout << "aberta grau 02: " << resOpened2 << endl;
  double resOpened3 = opened3(a, b, e);
  cout << "aberta grau 03: " << resOpened3 << endl;
  double resOpened4 = opened4(a, b, e);
  cout << "aberta grau 04: " << resOpened4 << endl;

  return 0;
}