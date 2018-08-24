#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int, char **)
{
	Mat image, dst;
	// Mat contours, dst_contours;

	image = imread("gira_lc.jpg", IMREAD_GRAYSCALE);
	if (!image.data)
		cout << "nao abriu bolhas.png" << endl;

	namedWindow("janela0", WINDOW_AUTOSIZE);
	namedWindow("janela1", WINDOW_AUTOSIZE);
	imshow("janela0", image);
	equalizeHist(image, dst);
	fastNlMeansDenoising(dst, image, 5, 7, 21);
	imshow("janela1", dst);
	waitKey();

	return 0;
}
