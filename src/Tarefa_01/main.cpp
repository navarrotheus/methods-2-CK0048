#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
  // Pegando o nome da imagem (presente na pasta)
  string nameImage;
  cout << "Qual o nome da imagem?" << endl;
  cin >> nameImage;

  // Lendo imagem e colocando-a em escala de cinza
  Mat image;
  image = imread(nameImage , CV_LOAD_IMAGE_COLOR);

  if(!image.data) {
      cout <<  "Não foi possível abrir ou ler a imagem" << endl ;
      return -1;
  }
  
  // Convertendo imagem para escala de cinza
  Mat grayImage;
  cvtColor(image, grayImage, CV_BGR2GRAY);

  // Criando borda na imagem
  copyMakeBorder(grayImage, grayImage, 1, 1, 1, 1, BORDER_CONSTANT, 0);


  // Realizando algoritmos

  // Criando nova imagem p/ Box Blur
  Mat boxBlurImage = Mat::zeros(grayImage.size(), grayImage.type());

  // Box Blur
  // Como temos uma borda, começamos pelo index 1 e percorremos uma linha e uma coluna a menos
  for (int i = 1; i < image.rows - 1; i++){
    for (int j = 1; j < image.cols - 1; j++){
      boxBlurImage.at<uchar>(i,j) = abs((grayImage.at<uchar>(i+1,j) + grayImage.at<uchar>(i-1,j)
      + grayImage.at<uchar>(i,j+1) + grayImage.at<uchar>(i,j-1))/4);
    }
  }

  // Criando nova imagem p/ Gaussian Blur
  Mat gaussianBlurImage = Mat::zeros(grayImage.size(), grayImage.type());

  for (int i = 1; i < grayImage.rows - 1; i++){
    for (int j = 1; j < grayImage.cols - 1; j++){
      gaussianBlurImage.at<uchar>(i,j) = abs((grayImage.at<uchar>(i+1,j-1) + (grayImage.at<uchar>(i+1,j)*2)
      + grayImage.at<uchar>(i+1,j+1) + (grayImage.at<uchar>(i,j+1)*2) + (grayImage.at<uchar>(i,j)*4)
      + (grayImage.at<uchar>(i,j-1)*2) + grayImage.at<uchar>(i-1,j-1) + (grayImage.at<uchar>(i-1,j)*2)
      + grayImage.at<uchar>(i-1,j+1))/16);
    }
  }

  // Criando nova imagem p/ Detector de bordas
  Mat borderDetectionImage = Mat::zeros(grayImage.size(), grayImage.type());

  for (int i = 1; i < grayImage.rows - 1; i++){
    for (int j = 1; j < grayImage.cols - 1; j++){
      borderDetectionImage.at<uchar>(i,j) = abs(grayImage.at<uchar>(i,j+1) - grayImage.at<uchar>(i,j-1)
      + grayImage.at<uchar>(i+1,j) - grayImage.at<uchar>(i-1,j));
    }
  }

  // Criando nova imagem p/ Sharpen Effect
  Mat sharpenEffectImage = Mat::zeros(grayImage.size(), grayImage.type());

  for (int i = 1; i < grayImage.rows - 1; i++){
    for (int j = 1; j < grayImage.cols - 1; j++){
      sharpenEffectImage.at<uchar>(i,j) = abs((grayImage.at<uchar>(i,j)*5) - grayImage.at<uchar>(i+1,j)
      - grayImage.at<uchar>(i-1,j) - grayImage.at<uchar>(i,j+1) - grayImage.at<uchar>(i,j-1));
    }
  }

  // Criando nova imagem p/ Embossing Effect
  Mat embossingEffectImage = Mat::zeros(grayImage.size(), grayImage.type());

  for (int i = 1; i < grayImage.rows - 1; i++){
    for (int j = 1; j < grayImage.cols - 1; j++){
      embossingEffectImage.at<uchar>(i,j) = abs(grayImage.at<uchar>(i+1,j-1) + grayImage.at<uchar>(i+1,j)
      + grayImage.at<uchar>(i,j-1) - grayImage.at<uchar>(i,j+1) - grayImage.at<uchar>(i-1,j)
      - grayImage.at<uchar>(i-1,j+1) + 128);
    }
  }

  // Demonstrando imagens
  namedWindow( "Imagem original", WINDOW_AUTOSIZE );
  namedWindow( "Escala de cinza", WINDOW_AUTOSIZE );
  namedWindow( "Box Blur", WINDOW_AUTOSIZE );
  namedWindow( "Gaussian Blur", WINDOW_AUTOSIZE );
  namedWindow( "Detector de bordas", WINDOW_AUTOSIZE );
  namedWindow( "Sharpen Effect", WINDOW_AUTOSIZE );
  namedWindow( "Embossing Effect", WINDOW_AUTOSIZE );

  imshow( "Imagem original", image );
  imshow( "Escala de cinza", grayImage );
  imshow( "Box Blur", boxBlurImage );
  imshow( "Gaussian Blur", gaussianBlurImage );
  imshow( "Detector de bordas", borderDetectionImage );
  imshow( "Sharpen Effect", sharpenEffectImage );
  imshow( "Embossing Effect", embossingEffectImage );

  cout << "Pressione qualquer tecla para interromper a exibição" << endl;

  waitKey();

  return 0;
}