#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
void removerBolhasExtremos(Mat image)
{
  for (int i = 0; i < image.rows; i++)
  {
    if (image.at<uchar>(i, 0) == 255)
    {
      floodFill(image, Point(0, i), 0);
      imshow("janela1", image);
    }
    if (image.at<uchar>(i, image.cols - 1) == 255)
    {
      floodFill(image, Point(image.cols - 1, i), 0);
      imshow("janela1", image);
    }
  }
  for (int i = 0; i < image.cols; i++)
  {
    if (image.at<uchar>(0, i) == 255)
    {
      floodFill(image, Point(i, 0), 0);
      imshow("janela1", image);
    }
    if (image.at<uchar>(image.rows - 1, i) == 255)
    {
      floodFill(image, Point(i, image.rows - 1), 0);
      imshow("janela1", image);
    }
  }
}
void pintarFundo(Mat image)
{
  int i = 0;
  bool flag = true;
  do
  {
    if (image.at<uchar>(0, i) == 0)
    {
      floodFill(image, Point(i, 0), 1);
      flag = false;
    }
  } while (flag);
}
int contarManchas(Mat image)
{
  int contador = 0;
  for (int i = 0; i < image.rows; i++)
  {
    for (int j = 0; j < image.cols; j++)
    {
      if (image.at<uchar>(i, j) == 255)
      {
        floodFill(image, Point(j, i), 200 - ++contador);
        imshow("janela1", image);
      }
    }
  }
  return contador;
}
int contarBolhas(Mat image)
{
  int contador = 0;
  for (int i = 0; i < image.rows; i++)
  {
    for (int j = 0; j < image.cols; j++)
    {
      if (image.at<uchar>(i, j) == 0)
      {
        floodFill(image, Point(j, i), 0);
        floodFill(image, Point(j, i), 1);
        contador++;
        imshow("janela1", image);
      }
    }
  }
  return contador;
}
int main(int, char **)
{
  Mat image;
  Vec3b val;
  image = imread("bolhas.png", IMREAD_GRAYSCALE);
  if (!image.data)
    cout << "nao abriu bolhas.png" << endl;
  namedWindow("janela1", WINDOW_AUTOSIZE);
  imshow("janela1", image);
  removerBolhasExtremos(image);
  pintarFundo(image);
  int qtnManchas = contarManchas(image);
  int qtnBolhas = contarBolhas(image);
  cout << qtnManchas << " manchas brancas sem bolha(s) e " << qtnBolhas << " com bolha(s)" << endl;
  waitKey();
  return 0;
}
