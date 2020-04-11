#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{
  
 
    Mat img = imread("test.jpeg");

    if(img.empty())
    {
        printf(" Error opening image\n");
        return -1;
    }

    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    medianBlur(gray, gray, 5);
    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
                gray.rows/8,  
                80, 30, 0, 0
           
    );

    for(size_t i = 0; i < circles.size(); i++)
    {
        Vec3i c = circles[i];
        Point center = Point(c[0], c[1]);
        circle( img, center, 1, Scalar(0,100,100), 3, LINE_AA);
        int radius = c[2];
        circle( img, center, radius, Scalar(255,0,255), 3, LINE_AA);
    }

    imshow("detected circles", img);
    waitKey();
    return 0;
}