#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h> // Wincosk2.h должен быть раньше windows!
#include <cstdlib>
#include <iostream>
#include <winsock.h>

#include <vector>
// System includes
#include <fstream>
#include <sstream>

#include<vector>
#include <iostream>
#include <algorithm>    
#include <Windows.h>
#include <iterator>
#include <numeric>

// OpenCV includes
#include <opencv2/videoio/videoio.hpp>  // Video write
#include <opencv2/videoio/videoio_c.h>  // Video write
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"

// Boost includes
#include <filesystem.hpp>
#include <filesystem/fstream.hpp>
#include <boost/algorithm/string.hpp>

// Local includes
#include "LandmarkCoreIncludes.h"

#include <Face_utils.h>
#include <FaceAnalyser.h>
#include <GazeEstimation.h>

//#include "LandmarkCoreIncludes.h"
#include "FaceLandmarkImg.h"

using namespace FaceLandmarkImg;

int main(int argc, char **argv)
//int main()
{
	//vector<string> arguments = get_arguments(argc, argv);
	vector<string> a, arguments;
	arguments.push_back("E:/openface2/OpenFace-OpenFace_v0.2/build_face_reg/bin/Release/test2.exe");
	arguments.push_back("-f");
	arguments.push_back("E:/openface2/s01_13.jpg");
	arguments.push_back("-of");
	arguments.push_back("E:/openface2/test1.txt");


/*	vector<string> arguments;

	for (int i = 0; i < argc; ++i)
	{
		arguments.push_back(string(argv[i]));
		
	}
	string s11 = arguments[0];
	std::cout << s11 << std::endl;
	string s12 = arguments[1];
	std::cout << s12 << std::endl;
	string s13 = arguments[2];
	std::cout << s13 << std::endl;
	string s14 = arguments[3];
	std::cout << s14 << std::endl;
	string s15 = arguments[4];
	std::cout << s15 << std::endl;
	*/
	
	/*
	vector<string> vector_AU = Emotion(arguments);
	//vector<string> vector_AU = PoseHeadFrame(arguments);
	string s1 = vector_AU[vector_AU.size() - 1];
	string s2 = vector_AU[vector_AU.size() - 2];
	string s3 = vector_AU[vector_AU.size() - 3];
	string s4 = vector_AU[vector_AU.size() - 4];
	string s5 = vector_AU[vector_AU.size() - 5];
	string s6 = vector_AU[vector_AU.size() - 6];
	string s7 = vector_AU[vector_AU.size() - 7];
	cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
	cout << s4 << " " << s5 << " " << s6 << " " << s7 << endl;
	cout << vector_AU.size() << endl;

	//LandmarkDetector::CLNF clnf_model = FaceLandmarkImg::PoseHeadFrame2(arguments);
	
	cv::VideoCapture cap;
	if (!cap.open(0))
		return 0;
	for (;;)
	{
		cv::Mat frame;
		cap >> frame;
		//if (frame.empty()) break; // end of video stream
		cv::imshow("this is you, smile! :)", frame);

		cvWaitKey(1);
		//cv::waitKey(1);
			//break; // stop capturing by pressing ESC 

		//cv::Mat frame;
		//vector<string> vector_AU2 = PoseHeadFrame3(arguments, clnf_model, frame);
		vector<string> vector_AU2 = PoseHeadFrame4(arguments,frame);
		cout << "vector_AU2.size()"<<vector_AU2.size() << endl;
		string s12 = vector_AU2[vector_AU2.size() - 1];
		string s22 = vector_AU2[vector_AU2.size() - 2];
		string s32 = vector_AU2[vector_AU2.size() - 3];
	//	string s42 = vector_AU2[vector_AU2.size() - 4];
		string s42 = vector_AU2[vector_AU2.size() - 4];
		string s52 = vector_AU2[vector_AU2.size() - 5];
		string s62 = vector_AU2[vector_AU2.size() - 6];
		cout << s12 << " " << s22 << " " << s32 << " "  << endl;
		cout << s42 << " " << s52 << " " << s62 << " " << endl;
		
	}
	
	

	return 0;
}
*/

//int main()
//{
//	return 0;
//}


/*int main()
{
	return 0;
}
*/

	cv::VideoCapture cap;
	if (!cap.open(0))
		return 0;
	for (;;)
	{
		cv::Mat frame;
		cap >> frame;
		//if (frame.empty()) break; // end of video stream
		cv::imshow("this is you, smile! :)", frame);

		cvWaitKey(1);
		//cv::waitKey(1);
		//break; // stop capturing by pressing ESC 

		//cv::Mat frame;
		//vector<string> vector_AU2 = PoseHeadFrame3(arguments, clnf_model, frame);
		vector<string> vector_AU2 = Emotion(arguments, frame);
		//vector<string> vector_AU2 = PoseHeadFrame4(arguments, frame);
		cout << "vector_AU2.size()" << vector_AU2.size() << endl;
		if (vector_AU2.size() == 1)
		{
			cout << "not found" << endl;
		}
		else {
			//cout << "vector_AU2.size()" << vector_AU2.size() << endl;
			string s12 = vector_AU2[vector_AU2.size() - 1];
			string s22 = vector_AU2[vector_AU2.size() - 2];
			string s32 = vector_AU2[vector_AU2.size() - 3];
			//	string s42 = vector_AU2[vector_AU2.size() - 4];
			string s42 = vector_AU2[vector_AU2.size() - 4];
			//string s52 = vector_AU2[vector_AU2.size() - 5];
			//string s62 = vector_AU2[vector_AU2.size() - 6];
			cout << s12 << " " << s22 << " " << s32 << " " << " " << s42 << endl;
			
			//cout << s42 << " " << s52 << " " << s62 << " " << endl;
			//double num1 = atof(vector_AU2[0].c_str());
			//double num2 = atof(vector_AU2[1].c_str());
			//double num3 = atof(vector_AU2[2].c_str());
			//cout << num1 << " " << num2 << " " << num3 << endl;


		}

	}



	return 0;
}