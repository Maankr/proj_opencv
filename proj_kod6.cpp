#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


// изображение - двумерная матрица в виде класса Mat, каждый элемент матрицы представляет собой один пиксель 
int main() {
    // Загрузка изображения
    Mat image = imread("C:/Users/Мария/Documents/ProectDe3k2s/ПД 6с/ПД 6с ОИ/im-67-1-1.tif"); // путь к фото

    // Предобработка изображения
    Mat gray, blurred, thresholded;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, blurred, Size(5, 5), 0);
    threshold(blurred, thresholded, 88, 255, 0); /*Функция threshold возвращает изображение, в котором все пиксели, которые темнее (меньше) 88 заменены на 0, а все, которые ярче (больше) 88, — на 255.*/

    // Поиск контуров на изображении
    vector<vector<Point>> contours;
    findContours(thresholded, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // Отображение контуров на изображении
    drawContours(image, contours, -1, Scalar(0, 255, 0), 4);

    // Вывод координат контуров 
    for (size_t i = 0; i < contours.size(); i++)
    {
        // Вычисление прямоугольника, ограничивающего контур
        Rect boundingBox = boundingRect(contours[i]);
        Point center(boundingBox.x + boundingBox.width / 2, boundingBox.y + boundingBox.height / 2);

         // Нарисовать прямоугольник вокруг контура
        if (boundingBox.x < 430 && boundingBox.y > 350)
        {
            // Вывод координат центра контура
            //cout << "Detected object at position: " << boundingBox.x << ", " << boundingBox.y << endl;
             rectangle(image, boundingBox, Scalar(0, 255, 0), 8); 
        }
        
    }                                                                                                     // 1879 1626 левый нижний 
                                                                                                          // 1893 1383 левый верхний
                                                                                                          // 2622 1424 верхний правый
                                                                                                          //2610 1667 нижний правый
    // Отображение изображения с контурами
    namedWindow("Resized_Window", 0); // переименовали файл
    resizeWindow("Resized_Window", 2032, 768); // задали размеры ширина - высота
    imshow("Resized_Window", image); // вывели изображение на экран 

    waitKey(0); // ожидаем любую клавишу для закрытия окна 
    destroyAllWindows(); // закрываем окно

    return 0;
}
