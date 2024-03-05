#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


// ����������� - ��������� ������� � ���� ������ Mat, ������ ������� ������� ������������ ����� ���� ������� 
int main() {
    // �������� �����������
    Mat image = imread("C:/Users/�����/Documents/ProectDe3k2s/�� 6�/�� 6� ��/im-67-1-1.tif"); // ���� � ����

    // ������������� �����������
    Mat gray, blurred, thresholded;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, blurred, Size(5, 5), 0);
    threshold(blurred, thresholded, 88, 255, 0); /*������� threshold ���������� �����������, � ������� ��� �������, ������� ������ (������) 88 �������� �� 0, � ���, ������� ���� (������) 88, � �� 255.*/

    // ����� �������� �� �����������
    vector<vector<Point>> contours;
    findContours(thresholded, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // ����������� �������� �� �����������
    drawContours(image, contours, -1, Scalar(0, 255, 0), 4);

    // ����� ��������� �������� 
    for (size_t i = 0; i < contours.size(); i++)
    {
        // ���������� ��������������, ��������������� ������
        Rect boundingBox = boundingRect(contours[i]);
        Point center(boundingBox.x + boundingBox.width / 2, boundingBox.y + boundingBox.height / 2);

         // ���������� ������������� ������ �������
        if (boundingBox.x < 430 && boundingBox.y > 350)
        {
            // ����� ��������� ������ �������
            //cout << "Detected object at position: " << boundingBox.x << ", " << boundingBox.y << endl;
             rectangle(image, boundingBox, Scalar(0, 255, 0), 8); 
        }
        
    }                                                                                                     // 1879 1626 ����� ������ 
                                                                                                          // 1893 1383 ����� �������
                                                                                                          // 2622 1424 ������� ������
                                                                                                          //2610 1667 ������ ������
    // ����������� ����������� � ���������
    namedWindow("Resized_Window", 0); // ������������� ����
    resizeWindow("Resized_Window", 2032, 768); // ������ ������� ������ - ������
    imshow("Resized_Window", image); // ������ ����������� �� ����� 

    waitKey(0); // ������� ����� ������� ��� �������� ���� 
    destroyAllWindows(); // ��������� ����

    return 0;
}
