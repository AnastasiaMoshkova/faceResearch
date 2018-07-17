#include "MyForm.h"
#include <msclr\marshal_cppstd.h>
//#include "FaceLandmarkImg.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
//void Main(array<String^>^ args) {
void Main(cli::array<System::String ^> ^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PrCLR::MyForm form;
	/*String^ a1 = args[0];
	std::string s1 = msclr::interop::marshal_as<std::string>(a1);
	String^ a2 = args[1];
	std::string s2 = msclr::interop::marshal_as<std::string>(a2);
	String^ a3 = args[2];
	std::string s3 = msclr::interop::marshal_as<std::string>(a3);
	String^ a4 = args[3];
	std::string s4 = msclr::interop::marshal_as<std::string>(a4);
	//String^ a5 = args[4];
	//std::string s5 = msclr::interop::marshal_as<std::string>(a5);
	vector<string> arguments;
	arguments.push_back("PrCLR.exe");
	arguments.push_back(s1);
	arguments.push_back(s2);
	arguments.push_back(s3);
	arguments.push_back(s4);
	*/
	//arguments.push_back(s5);
	//form.tt2(arguments);
	//form.tt(arguments);
	//form.tt2(arguments);
	Application::Run(%form);
/*	cv::VideoCapture cap(0);
	int strQ1 = 0;
	//for (;;)
	while (cap.isOpened())
	{
		cv::Mat frame;
		cap >> frame;
		//if (frame.empty()) break; // end of video stream
		cv::imshow("this is you, smile! :)", frame);
		cvWaitKey(1);
		form.tt2(arguments, frame);
		Application::Run(%form);
	}
	*/
//	form.tt2(arguments);
	//LandmarkDetector::CLNF clnf_model = FaceLandmarkImg::PoseHeadFrame2(arguments);
	//cv::Mat frame;
	//vector<string> a = FaceLandmarkImg::PoseHeadFrame3(arguments, clnf_model, frame);
	//form.CreateMyTextBoxControl();
	//FaceLandmarkImg::
	//Application::Run(%form);
}

