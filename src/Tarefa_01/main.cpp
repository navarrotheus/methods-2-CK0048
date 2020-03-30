#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
  // Lendo imagem e colocando-a em escala de cinza
  Mat image;
  image = imread("sample.jpeg" , CV_LOAD_IMAGE_GRAYSCALE);

  if(!image.data) {
      cout <<  "Could not open or find the image" << endl ;
      return -1;
  }

  // Criando nova imagem
  Mat newImage = Mat::zeros( image.size(), image.type() );

  // Menu de inicialização
  int opt;
  cout << "Selecione a opção desejada" << "\n";
  cout << "1) Box Blur" << "\n";
  cout << "2) Gaussian Blur" << "\n";
  cin >> opt;

  // Realizando algoritmo de acordo com opção escolhida
  switch (opt) {
    case 1:
      for (int i = 0; i < image.rows; i++){
        for (int j = 0; j < image.cols; j++){
          newImage.at<uchar>(i, j) = (image.at<uchar>(i-1,j) + image.at<uchar>(i+1, j)
          + image.at<uchar>(i, j-1) + image.at<uchar>(i+1, j+1))/4;
        }
      }
      break;
    case 2:
      break;
  }

  // Demonstrando imagem
  namedWindow( "Original image", WINDOW_AUTOSIZE );
  namedWindow( "New image", WINDOW_AUTOSIZE );

  imshow( "Original image", image );
  imshow( "New image", newImage );

  waitKey(0);
  return 0;
}