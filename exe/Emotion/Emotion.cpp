#include "Emotion.h"
#include <msclr\marshal_cppstd.h>
//#include "FaceLandmarkImg.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
//void Main(array<String^>^ args) {
void Main(cli::array<System::String ^> ^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Emotion::Emotion form;
	Application::Run(%form);
}

