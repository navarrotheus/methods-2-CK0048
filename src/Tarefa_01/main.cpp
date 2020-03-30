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
  image = imread(nameImage , CV_LOAD_IMAGE_GRAYSCALE);

  // Criando borda na imagem
  copyMakeBorder(image, image, 1, 1, 1, 1, BORDER_CONSTANT, 0);

  if(!image.data) {
      cout <<  "Não foi possível abrir ou ler a imagem" << endl ;
      return -1;
  }

  // Criando nova imagem
  Mat newImage = Mat::zeros( image.size(), image.type() );

  // Menu de inicialização
  int opt;
  cout << "Selecione a opção desejada" << endl;
  cout << "1) Box Blur" << endl;
  cout << "2) Gaussian Blur" << endl;
  cout << "3) Detector de bordas" << endl;
  cin >> opt;

  // Realizando algoritmo de acordo com opção escolhida
  switch (opt) {
    case 1:
      // Como temos aquela borda, começamos pelo index 1 e diminuimos em 1 as colunas e linhas
      for (int i = 1; i < image.rows - 1; i++){
        for (int j = 1; j < image.cols - 1; j++){
          newImage.at<uchar>(i, j) = (image.at<uchar>(i-1,j) + image.at<uchar>(i+1, j)
          + image.at<uchar>(i, j-1) + image.at<uchar>(i+1, j+1))/4;
        }
      }
      break;
    case 2:
      for (int i = 1; i < image.rows - 1; i++){
        for (int j = 1; j < image.cols - 1; j++){
          newImage.at<uchar>(i, j) = (image.at<uchar>(i-1,j+1) + (image.at<uchar>(i,j+1)*2)
          + image.at<uchar>(i+1,j+1) + (image.at<uchar>(i-1,j)*2) + (image.at<uchar>(i,j)*4)
          + (image.at<uchar>(i+1,j)*2) + image.at<uchar>(i-1,j-1) + (image.at<uchar>(i,j-1)*2)
          + image.at<uchar>(i+1,j-1))/16;
        }
      }
      break;
    case 3:
      for (int i = 1; i < image.rows - 1; i++){
        for (int j = 1; j < image.cols - 1; j++){
          newImage.at<uchar>(i, j) = abs(image.at<uchar>(i+1, j) - image.at<uchar>(i-1, j)
          + image.at<uchar>(i, j+1) - image.at<uchar>(i, j-1));
        }
      }
  }

  // Demonstrando imagem
  namedWindow( "Imagem original", WINDOW_AUTOSIZE );
  namedWindow( "Imagem nova", WINDOW_AUTOSIZE );

  imshow( "Imagem original", image );
  imshow( "Imagem nova", newImage );

  cout << "Pressione qualquer tecla para interromper a exibição" << endl;

  waitKey(0);
  return 0;
}