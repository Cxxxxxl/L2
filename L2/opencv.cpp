#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(){
    // ��ȡͼ��
    Mat img = imread("Lena.jpg");

    if (img.empty()){
        cout << "�޷���ȡͼ��" << endl;
        return -1;
    }

    // ת��Ϊ�Ҷ�ͼ
    Mat grayImg;
    cvtColor(img, grayImg, COLOR_BGR2GRAY);

    // ת��Ϊ��ֵͼ
    Mat binaryImg;
    threshold(grayImg, binaryImg, 128, 255, THRESH_BINARY);

    // ��ʾ�Ҷ�ͼ�Ͷ�ֵͼ
    imshow("Gray Image", grayImg);
    imshow("Binary Image", binaryImg);
    waitKey(0);

    // ����Ҷ�ͼ
    cout << "�Ҷ�ͼ��" << endl;
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < img.cols; ++j)
        {
            cout << std::setw(4) << static_cast<int>(img.at<uchar>(i, j)) << " ";
        }
        cout << endl;
    }

    // ����ƽ��ֵ����λ��
    Scalar meanValue, medianValue;
    meanStdDev(img, meanValue, medianValue);
    double average = meanValue.val[0];
    double median = medianValue.val[0];
    cout << "ƽ��ֵ: " << average << endl;
    cout << "��λ��: " << median << endl;

    // ������ֵ T
    double T = (average + median) / 2;
    cout << "��ֵ T: " << T << endl;

    // ������ֵ�����������
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < img.cols; ++j){
            if (img.at<uchar>(i, j) < T){
                img.at<uchar>(i, j) = 0;
            }
            else{
                img.at<uchar>(i, j) = 255;
            }
        }
    }

    // ��������ľ���
    cout << "�����ľ���" << endl;
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < img.cols; ++j){
            cout << setw(4) << static_cast<int>(img.at<uchar>(i, j)) << " ";
        }
        cout << endl;
    }
    return 0;
}