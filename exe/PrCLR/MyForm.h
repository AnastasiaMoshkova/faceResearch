//using System::String;
#pragma once
//#include "LandmarkCoreIncludes.h"
//#define EXPORTING
//#include "FaceLandmarkImg.h"
//#pragma unmanaged
//#pragma managed(push, off)
#pragma unmanaged
#include <vector>
#include <string>
//#include "LandmarkCoreIncludes.h"
#include "FaceLandmarkImg.h"
#include "opencv2/opencv.hpp"

#pragma managed

#include <msclr\marshal_cppstd.h>
//#include "FaceLandmarkImg.h"

//extern "C" __declspec(dllimport)  vector<string> Emotion(vector<string> arguments);
//using namespace FaceLandmarkImg;
//#pragma managed
//#include "dlib\matrix\matrix.h"
//#include "FaceAnalyser.h"
//#include "LandmarkCoreIncludes.h"
//#include "opencv2\core\core.hpp"
//#include <vector>
//#pragma unmanaged(pop)
//#pragma managed
using namespace FaceLandmarkImg;

namespace PrCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			//dlib::matrix<float, 0, 1> m;
			//
			//TODO: добавьте код конструктора
			//
			//[DllImport("user32.dll")]
			
		}
		void tt(vector<string> arguments)
		{
			textBox1->Text = "Hello World!";
			/*vector<string> a,b;
			b.push_back("-f");
			b.push_back("C:\\Users\\AnMoshkova\\Documents\\face_test_img_front.jpg");
			b.push_back("-of");
			b.push_back("‪C:\\Users\\AnMoshkova\\Documents\\test1.txt");
*/
			/*
			//a = FaceLandmarkImg::Emotion(b);
			FaceLandmarkImg::Emotion(arguments);
			vector<string> a= FaceLandmarkImg::Emotion(arguments);
			string strQ1 = a[4];
			string strQ2 = a[5];
			string strQ3 = a[6];
			//string str = to_string(a.size());
			//string str = "test";
			//cout << str << endl;
			String^ str21 = gcnew String(strQ1.c_str());
			String^ str22 = gcnew String(strQ2.c_str());
			String^ str23 = gcnew String(strQ3.c_str());
			//Console::WriteLine(str2);
			textBox1->Text = str21;
			textBox2->Text = str22;
			textBox3->Text = str23;
			*/

		}

		void tt2(vector<string> arguments)
		{
			textBox1->Text = "Hello World!";
			//LandmarkDetector::CLNF clnf_model = FaceLandmarkImg::PoseHeadFrame2(arguments);
			cv::VideoCapture cap(0);
			int strQ1 = 0;
			//for (;;)
			for (int i = 0; i < 3; i++)
			{
				cv::Mat frame;
				cap >> frame;
				//if (frame.empty()) break; // end of video stream
				cv::imshow("this is you, smile! :)", frame);
				cvWaitKey(1);
				//FaceLandmarkImg::Emotion(arguments);
				//vector<string> a = FaceLandmarkImg::PoseHeadFrame3(arguments, clnf_model, frame);
				vector<string> a = FaceLandmarkImg::PoseHeadFrame4(arguments,frame);
				string strQ1 = a[0];
				string strQ2 = a[1];
				string strQ3 = a[2];
				//string str = to_string(a.size());
				//string str = "test";
				//cout << str << endl;
				String^ str21 = gcnew String(strQ1.c_str());
				String^ str22 = gcnew String(strQ2.c_str());
				String^ str23 = gcnew String(strQ3.c_str());
				//Console::WriteLine(str21);
				//Console::WriteLine(str22);
				//Console::WriteLine(str23);
				//std::cout << strQ1 << " " << strQ2 << " " << strQ3 << " " << std::endl;
				textBox1->Text = str21;
				textBox2->Text = str22;
				textBox3->Text = str23;
			
				
				//strQ1++;
				//string str = to_string(strQ1++);
				//String^ str21 = gcnew String(str.c_str());
				//textBox1->Text = str21;
			}

		}
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::CheckBox^  checkBox8;
	private: System::Windows::Forms::CheckBox^  checkBox9;
	public:
		bool stop = false;
		bool state1 = true;
		bool state2 = true;
		bool state3 = true;
		bool state4 = true;
		bool state5 = true;
		bool state6 = true;
		bool state7 = true;
		bool state8 = true;
		bool state9 = true;
private: System::Windows::Forms::Button^  button4;

private: System::Windows::Forms::TextBox^  textBox7;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::TextBox^  textBox8;
private: System::Windows::Forms::TextBox^  textBox9;
private: System::Windows::Forms::TextBox^  textBox10;
private: System::Windows::Forms::TextBox^  textBox11;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label10;

public:
	//String^ folderName;

private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;

		
		//cv::Mat image;
		

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::TextBox^  textBox4;
private: System::Windows::Forms::TextBox^  textBox5;
private: System::Windows::Forms::TextBox^  textBox6;
private: System::Windows::Forms::Button^  button2;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(98, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(98, 112);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(98, 164);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(95, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"X(назад/вперед)";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(80, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(135, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Y(поворот влево/вправо)";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(85, 187);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(130, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Z(наклон влево/вправо)";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(80, 243);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(289, 65);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 7;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(289, 112);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 8;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(292, 164);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 9;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(272, 243);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(104, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Stop and Save";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(179, 243);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"AutoSave";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(806, 12);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(90, 17);
			this->checkBox1->TabIndex = 12;
			this->checkBox1->Text = L"Фронтально";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(806, 45);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(167, 17);
			this->checkBox2->TabIndex = 13;
			this->checkBox2->Text = L"Наклон назад (20 градусов)";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(806, 77);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(173, 17);
			this->checkBox3->TabIndex = 14;
			this->checkBox3->Text = L"Наклон вперед (12 градусов)";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(806, 111);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(172, 17);
			this->checkBox4->TabIndex = 15;
			this->checkBox4->Text = L"Поворот влево (18 градусов)";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(806, 147);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(178, 17);
			this->checkBox5->TabIndex = 16;
			this->checkBox5->Text = L"Поворот вправо (18 градусов)";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(806, 183);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(336, 17);
			this->checkBox6->TabIndex = 17;
			this->checkBox6->Text = L"Поворот влево вверх (15 градусов вверх, 15 градусов влево)";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(806, 217);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(348, 17);
			this->checkBox7->TabIndex = 18;
			this->checkBox7->Text = L"Поворот вправо вверх (15 градусов вверх, 15 градусов вправо)";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Location = System::Drawing::Point(806, 249);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(331, 17);
			this->checkBox8->TabIndex = 19;
			this->checkBox8->Text = L"Поворот влево вниз (12 градусов вверх, 12 градусов влево)";
			this->checkBox8->UseVisualStyleBackColor = true;
			// 
			// checkBox9
			// 
			this->checkBox9->AutoSize = true;
			this->checkBox9->Location = System::Drawing::Point(806, 281);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(343, 17);
			this->checkBox9->TabIndex = 20;
			this->checkBox9->Text = L"Поворот вправо вниз (12 градусов вверх, 12 градусов вправо)";
			this->checkBox9->UseVisualStyleBackColor = true;
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->HelpRequest += gcnew System::EventHandler(this, &MyForm::folderBrowserDialog1_HelpRequest);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 10);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(109, 23);
			this->button4->TabIndex = 21;
			this->button4->Text = L"Выбрать папку";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(130, 12);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(318, 20);
			this->textBox7->TabIndex = 23;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox7_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(282, 187);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(123, 13);
			this->label4->TabIndex = 24;
			this->label4->Text = L"расстояние от камеры";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(286, 135);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(110, 13);
			this->label5->TabIndex = 25;
			this->label5->Text = L"положение по оси У";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(286, 88);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(109, 13);
			this->label6->TabIndex = 26;
			this->label6->Text = L"положение по оси Х";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(466, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(297, 253);
			this->pictureBox1->TabIndex = 27;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(363, 305);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 28;
			this->button5->Text = L"Эмоции";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(115, 291);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 29;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(115, 322);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 20);
			this->textBox9->TabIndex = 30;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(240, 291);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(100, 20);
			this->textBox10->TabIndex = 31;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(240, 322);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(100, 20);
			this->textBox11->TabIndex = 32;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(25, 294);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(81, 13);
			this->label7->TabIndex = 33;
			this->label7->Text = L"Эмоция 1 ранг";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(25, 325);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(81, 13);
			this->label8->TabIndex = 34;
			this->label8->Text = L"Эмоция 2 ранг";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label9->Location = System::Drawing::Point(587, 31);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(48, 55);
			this->label9->TabIndex = 35;
			this->label9->Text = L"↑";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label10->Location = System::Drawing::Point(591, 217);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(30, 66);
			this->label10->TabIndex = 36;
			this->label10->Text = L"↓\r\n↓";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1170, 363);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->checkBox9);
			this->Controls->Add(this->checkBox8);
			this->Controls->Add(this->checkBox7);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	//String^ a5 = args[4];
	//std::string s5 = msclr::interop::marshal_as<std::string>(a5);
	stop = false;
	vector<string> a, arguments;
	arguments.push_back("E:/openface2/OpenFace-OpenFace_v0.2/build3/bin/Release/test2.exe");
	arguments.push_back("-f");
	arguments.push_back("E:/openface2/s01_13.jpg");
	arguments.push_back("-of");
	arguments.push_back("E:/openface2/test1.txt");
	//textBox1->Text = "Hello World!";
	//LandmarkDetector::CLNF clnf_model = FaceLandmarkImg::PoseHeadFrame2(arguments);
	cv::Mat image;
	cv::VideoCapture cap(0);
	int strQ1 = 0;
	for (;;)
		//for (int i = 0; i < 3; i++)
	{
	    cv::Mat frame;
		cap >> frame;
		image = frame.clone();
		//if (frame.empty()) break; // end of video stream
		cv::imshow("this is you, smile! :)", frame);
		cvWaitKey(1);
		//FaceLandmarkImg::Emotion(arguments);
		//vector<string> a = FaceLandmarkImg::PoseHeadFrame3(arguments, clnf_model, frame);
		vector<string> a = FaceLandmarkImg::PoseHeadFrame4(arguments, frame);
		string strQ1 = a[0];
		string strQ2 = a[1];
		string strQ3 = a[2];
		string strQ4 = a[3];
		string strQ5 = a[4];
		string strQ6 = a[5];
		//string str = to_string(a.size());
		//string str = "test";
		//cout << str << endl;
		String^ str21 = gcnew String(strQ1.c_str());
		String^ str22 = gcnew String(strQ2.c_str());
		String^ str23 = gcnew String(strQ3.c_str());
		String^ str24 = gcnew String(strQ4.c_str());
		String^ str25 = gcnew String(strQ5.c_str());
		String^ str26 = gcnew String(strQ6.c_str());
		textBox1->Text = str21;
		textBox2->Text = str22;
		textBox3->Text = str23;
		textBox4->Text = str24;
		textBox5->Text = str25;
		textBox6->Text = str26;

		if (stop)
		{
			cv::imshow("image", image);
			IO::Stream^ myStream;
			SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
			//saveFileDialog1->Filter = "Dateityp PNG (*.PNG)|*.PNG|All files (*.*)|*.*";
			saveFileDialog1->Filter = "Dateityp PNG (*.PNG)|*.PNG";
			saveFileDialog1->FilterIndex = 2;
			saveFileDialog1->RestoreDirectory = true;
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ FileName1=saveFileDialog1->FileName;
				//saveFileDialog1->FileName;
				string strFile = msclr::interop::marshal_as<std::string>(FileName1);
				cv::imwrite(strFile,image);
			}

			break;
		}
	}
}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	stop = true;
	
	
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

	stop = false;
	vector<string> a, arguments;
	arguments.push_back("E:/openface2/OpenFace-OpenFace_v0.2/build3/bin/Release/test2.exe");
	arguments.push_back("-f");
	arguments.push_back("E:/openface2/s01_13.jpg");
	arguments.push_back("-of");
	arguments.push_back("E:/openface2/test1.txt");
	//textBox1->Text = "Hello World!";
	//LandmarkDetector::CLNF clnf_model = FaceLandmarkImg::PoseHeadFrame2(arguments);
	cv::Mat image;
	cv::VideoCapture cap(0);
	int strQ1 = 0;

	//std::string strFile = "E:\\project_face_registration\\faceregistration2\\build\\bin\\Release\\proverka\\";
	String^ strfolderName = textBox7->Text;
	std::string strFile = msclr::interop::marshal_as<std::string>(strfolderName);

	for (;;)
		//for (int i = 0; i < 3; i++)
	{
		cv::Mat frame;
		cap >> frame;
		image = frame.clone();
		//if (frame.empty()) break; // end of video stream
		//cv::imshow("this is you, smile! :)", frame);
		//cvWaitKey(1);
		System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
		System::IntPtr ptr(image.ptr());
		System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(image.cols, image.rows, image.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
		System::Drawing::RectangleF rect(0, 0, pictureBox1->Width, pictureBox1->Height);
		graphics->DrawImage(b, rect);

		//FaceLandmarkImg::Emotion(arguments);
		//vector<string> a = FaceLandmarkImg::PoseHeadFrame3(arguments, clnf_model, frame);
		vector<string> a = FaceLandmarkImg::PoseHeadFrame4(arguments, frame);
		string strQ1 = a[0];
		string strQ2 = a[1];
		string strQ3 = a[2];
		string strQ4 = a[3];
		string strQ5 = a[4];
		string strQ6 = a[5];
		//string str = to_string(a.size());
		//string str = "test";
		//cout << str << endl;
		String^ str21 = gcnew String(strQ1.c_str());
		String^ str22 = gcnew String(strQ2.c_str());
		String^ str23 = gcnew String(strQ3.c_str());
		String^ str24 = gcnew String(strQ4.c_str());
		String^ str25 = gcnew String(strQ5.c_str());
		String^ str26 = gcnew String(strQ6.c_str());
		textBox1->Text = str21;
		textBox2->Text = str22;
		textBox3->Text = str23;
		textBox4->Text = str24;
		textBox5->Text = str25;
		textBox6->Text = str26;

		double num1 = atof(strQ1.c_str());
		double num2 = atof(strQ2.c_str());
		double num3 = atof(strQ3.c_str());
	
		/*if (state1 & (num1 < 3) & (num2 < 3) & (num3 < 3))
		{
			state1 = false;
			checkBox1->Checked = true;
			//checkBox1->ThreeState = true;
			cv::imwrite(strFile+"1.PNG", image);
		}
		*/

		if (state1 && (num1 > -3) && (num1 < 3) && (num2 >-3) && (num2 < 3) && (num3>-3) && (num3 < 3))
		{
			state1 = false;
			checkBox1->Checked = true;
			//checkBox1->ThreeState = true;
			cv::imwrite(strFile + "\\" + "1.PNG", image);
		}

		if (state2 && (num1 > -21) && (num1 < -20) && (num2 >-5) && (num2 < 5) && (num3>-5) && (num3 < 5))
		{
			state2 = false;
			checkBox2->Checked = true;
			//checkBox1->ThreeState = true;
			cv::imwrite(strFile + "\\" + "2.PNG", image);
		}

		if (state3 && (num1 > 12) && (num1 < 13) && (num2 >-5) && (num2 < 5) && (num3>-5) && (num3 < 5))
		{
			state3 = false;
			checkBox3->Checked = true;
			//checkBox1->ThreeState = true;
			cv::imwrite(strFile + "\\" + "3.PNG", image);
		}

		if (state4 && (num1 > -5) && (num1 < 5) && (num2 >-19) && (num2 < -18) && (num3>-5) && (num3 < 5))
		{
			state4 = false;
			checkBox4->Checked = true;
			//checkBox1->ThreeState = true;
			cv::imwrite(strFile + "\\" + "4.PNG", image);
		}

		if (state5 && (num1 > -5) && (num1 < 5) && (num2 >18) && (num2 < 19) && (num3>-5) && (num3 < 5))
		{
			state5 = false;
			checkBox5->Checked = true;
			//checkBox1->ThreeState = true;
			cv::imwrite(strFile + "\\" + "5.PNG", image);
		}

		if (state6 && (num1 > -16) && (num1 < -15) && (num2 >-16) && (num2 < -15) && (num3>-5) && (num3 < 5))
		{
			state6 = false;
			checkBox6->Checked = true;
			//checkBox1->ThreeState = true;
			cv::imwrite(strFile + "\\" + "6.PNG", image);
		}

		if (state7 && (num1 > -16) && (num1 < -15) && (num2 >15) && (num2 < 16) && (num3>-5) && (num3 < 5))
		{
			state7 = false;
			checkBox7->Checked = true;
			//checkBox1->ThreeState = true;
			cv::imwrite(strFile + "\\" + "7.PNG", image);
		}

		if (state8 && (num1 > 12) && (num1 < 13) && (num2 >-13) && (num2 < -12) && (num3>-5) && (num3 < 5))
		{
			state8 = false;
			checkBox8->Checked = true;
			//checkBox1->ThreeState = true;
			cv::imwrite(strFile + "\\" + "8.PNG", image);
		}

		if (state9 && (num1 > 12) && (num1 < 13) && (num2 >12) && (num2 < 13) && (num3>-5) && (num3 < 5))
		{
			state9 = false;
			checkBox9->Checked = true;
			//checkBox1->ThreeState = true;
			cv::imwrite(strFile + "\\"+"9.PNG", image);
		}

		if (stop)
		{
			
			break;
		}
	}
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void folderBrowserDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {

	FolderBrowserDialog^ folderBrowserDialog1;
	folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;

	// Show the FolderBrowserDialog.
	System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();
	//if (result == ::DialogResult::OK)
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		String^ folderName = folderBrowserDialog1->SelectedPath;
		//string strfolderName = msclr::interop::marshal_as<std::string>(folderName);
		//
		//
	}


	//String^ FileName1 = folderBrowserDialog1->FileName;
	//saveFileDialog1->FileName;
	//string strFile = msclr::interop::marshal_as<std::string>(FileName1);
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	FolderBrowserDialog^ folderBrowserDialog1;
	folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;

	// Show the FolderBrowserDialog.
	System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();
	//if (result == ::DialogResult::OK)
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		String^ folderName = folderBrowserDialog1->SelectedPath;
		textBox7->Text = folderName;
		//string strfolderName = msclr::interop::marshal_as<std::string>(folderName);
		//
		//
	}
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void fileSystemWatcher1_Changed(System::Object^  sender, System::IO::FileSystemEventArgs^  e) {
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {


	stop = false;
	vector<string> a, arguments;
	arguments.push_back("E:/openface2/OpenFace-OpenFace_v0.2/build3/bin/Release/test2.exe");
	arguments.push_back("-f");
	arguments.push_back("E:/openface2/s01_13.jpg");
	arguments.push_back("-of");
	arguments.push_back("E:/openface2/test1.txt");
	//textBox1->Text = "Hello World!";
	//LandmarkDetector::CLNF clnf_model = FaceLandmarkImg::PoseHeadFrame2(arguments);
	cv::Mat image;
	cv::VideoCapture cap(0);
	int strQ1 = 0;

	//std::string strFile = "E:\\project_face_registration\\faceregistration2\\build\\bin\\Release\\proverka\\";
	String^ strfolderName = textBox7->Text;
	std::string strFile = msclr::interop::marshal_as<std::string>(strfolderName);

	for (;;)
		//for (int i = 0; i < 3; i++)
	{
		cv::Mat frame;
		cap >> frame;
		image = frame.clone();
		//if (frame.empty()) break; // end of video stream
		//cv::imshow("this is you, smile! :)", frame);
		//cvWaitKey(1);
		
		System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
		System::IntPtr ptr(image.ptr());
		System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(image.cols, image.rows, image.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
		System::Drawing::RectangleF rect(0, 0, pictureBox1->Width, pictureBox1->Height);
		graphics->DrawImage(b, rect);
		

		//FaceLandmarkImg::Emotion(arguments);
		//vector<string> a = FaceLandmarkImg::PoseHeadFrame3(arguments, clnf_model, frame);
		vector<string> e = FaceLandmarkImg::Emotion(arguments, frame);

		if (e.size() != 0)
		{



			string strE1 = e[0];
			string strE2 = e[1];
			string strE3 = e[2];
			string strE4 = e[3];

			//string str = to_string(a.size());
			//string str = "test";
			//cout << str << endl;
			String^ strE1r = gcnew String(strE1.c_str());
			String^ strE2r = gcnew String(strE2.c_str());
			String^ strP1 = gcnew String(strE3.c_str());
			String^ strP2 = gcnew String(strE4.c_str());


			textBox8->Text = strE1r;
			textBox9->Text = strE2r;
			textBox10->Text = strP1;
			textBox11->Text = strP2;


			delete strE1r;
			delete strE2r;
			delete strP1;
			delete strP2;

		}

		if (stop)
		{

			break;
		}
	}
}

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
