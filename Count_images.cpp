#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/*void main() {                // Code for loding image
    string path = "photo my.jpg";
	Mat	img = imread(path);
	imshow("Frame", img);
	waitKey(0);
}*/ 
/*void main() {                  // Code for loding  system camera
	VideoCapture video(1);
	Mat img;
	while (true) {
		video.read(img);
		imshow("Frame", img);
		waitKey(1);

	}
}*/


void main() {                       // Face detection code
	VideoCapture video(1);
	CascadeClassifier facedetect;
	Mat img;
	facedetect.load("haarcascade_frontalface_default.xml");

	while (true) {
		video.read(img);

		vector<Rect> faces;
		 
		facedetect.detectMultiScale(img, faces, 1.3, 5);

		cout << faces.size() << endl;  // for storing total no. of faces detected.

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
			rectangle(img, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED);
			putText(img, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1); // printing no. of faces detected
		}


		imshow("Frame", img);
		waitKey(1);


	}
}