#pragma once

#pragma unmanaged
#include <vector>
#include <string>
//#include "FaceRecDLib.h"
#include "FaceLandmarkImg.h"
#include "opencv2/opencv.hpp"
#include "FaceRecDlib.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#pragma managed

#include <msclr\marshal_cppstd.h>

using namespace FaceLandmarkImg;

namespace Emotion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Emotion
	/// </summary>
	public ref class Emotion : public System::Windows::Forms::Form
	{
	public:
		Emotion(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	public:





	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;






	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;


	private: System::Windows::Forms::Label^  label11;







	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	private: System::Windows::Forms::PictureBox^  pictureBox11;
	private: System::Windows::Forms::PictureBox^  pictureBox12;
	private: System::Windows::Forms::Label^  MessageLbl;
	private: System::Windows::Forms::Label^  PersonFace1Lbl;
	private: System::Windows::Forms::Label^  PersonFace2Lbl;
	private: System::Windows::Forms::Label^  PersonFace3Lbl;
	private: System::Windows::Forms::Label^  Similar1Lbl;
	private: System::Windows::Forms::Label^  Similar2Lbl;
	private: System::Windows::Forms::Label^  Similar3Lbl;
	private: System::Windows::Forms::Label^  surplbl;
	private: System::Windows::Forms::Label^  sadlbl;
	private: System::Windows::Forms::Label^  happylbl;
	private: System::Windows::Forms::Label^  dislbl;
	private: System::Windows::Forms::Label^  anglbl;
	private: System::Windows::Forms::Label^  eyesLbl;
	private: System::Windows::Forms::Label^  XLbl;
	private: System::Windows::Forms::Label^  YLbl;
	private: System::Windows::Forms::Label^  ZLbl;
	private: System::Windows::Forms::Label^  fearlbl;

	private: System::Windows::Forms::ProgressBar^  progressBar2;
	private: System::Windows::Forms::ProgressBar^  progressBar3;
	private: System::Windows::Forms::ProgressBar^  progressBar4;
	private: System::Windows::Forms::ProgressBar^  progressBar5;
	private: System::Windows::Forms::ProgressBar^  progressBar6;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;







			 bool stop = false;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Emotion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->MessageLbl = (gcnew System::Windows::Forms::Label());
			this->PersonFace1Lbl = (gcnew System::Windows::Forms::Label());
			this->PersonFace2Lbl = (gcnew System::Windows::Forms::Label());
			this->PersonFace3Lbl = (gcnew System::Windows::Forms::Label());
			this->Similar1Lbl = (gcnew System::Windows::Forms::Label());
			this->Similar2Lbl = (gcnew System::Windows::Forms::Label());
			this->Similar3Lbl = (gcnew System::Windows::Forms::Label());
			this->surplbl = (gcnew System::Windows::Forms::Label());
			this->sadlbl = (gcnew System::Windows::Forms::Label());
			this->happylbl = (gcnew System::Windows::Forms::Label());
			this->dislbl = (gcnew System::Windows::Forms::Label());
			this->anglbl = (gcnew System::Windows::Forms::Label());
			this->eyesLbl = (gcnew System::Windows::Forms::Label());
			this->XLbl = (gcnew System::Windows::Forms::Label());
			this->YLbl = (gcnew System::Windows::Forms::Label());
			this->ZLbl = (gcnew System::Windows::Forms::Label());
			this->fearlbl = (gcnew System::Windows::Forms::Label());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar3 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar4 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar5 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar6 = (gcnew System::Windows::Forms::ProgressBar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(26, 193);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(646, 519);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(702, 232);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(216, 202);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Emotion::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(94, 10);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Stop";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Emotion::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(712, 596);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 16);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Удивление";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(1013, 746);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 16);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Страх";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(1005, 596);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 16);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Радость";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(868, 596);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 16);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Печаль";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(712, 746);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(90, 16);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Отвращение";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(869, 746);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(39, 16);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Гнев";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(427, 813);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(26, 13);
			this->label7->TabIndex = 22;
			this->label7->Text = L"X = ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(491, 813);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(26, 13);
			this->label8->TabIndex = 23;
			this->label8->Text = L"Y = ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(554, 813);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(26, 13);
			this->label9->TabIndex = 24;
			this->label9->Text = L"Z = ";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(20, 813);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(158, 13);
			this->label11->TabIndex = 27;
			this->label11->Text = L"Расстояние между глазами - ";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(962, 465);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 13);
			this->label13->TabIndex = 35;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(729, 652);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(88, 78);
			this->pictureBox3->TabIndex = 36;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(725, 501);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(88, 78);
			this->pictureBox4->TabIndex = 37;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(871, 501);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(88, 78);
			this->pictureBox5->TabIndex = 38;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(871, 652);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(88, 78);
			this->pictureBox6->TabIndex = 39;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Location = System::Drawing::Point(1016, 501);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(88, 78);
			this->pictureBox7->TabIndex = 40;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Location = System::Drawing::Point(1016, 652);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(88, 78);
			this->pictureBox8->TabIndex = 41;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Location = System::Drawing::Point(981, 210);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(140, 161);
			this->pictureBox9->TabIndex = 42;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->Click += gcnew System::EventHandler(this, &Emotion::pictureBox9_Click);
			// 
			// pictureBox10
			// 
			this->pictureBox10->Location = System::Drawing::Point(1203, 232);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(118, 139);
			this->pictureBox10->TabIndex = 43;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->Location = System::Drawing::Point(1409, 256);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(94, 115);
			this->pictureBox11->TabIndex = 44;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->Location = System::Drawing::Point(462, 12);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(738, 153);
			this->pictureBox12->TabIndex = 45;
			this->pictureBox12->TabStop = false;
			// 
			// MessageLbl
			// 
			this->MessageLbl->AutoSize = true;
			this->MessageLbl->Font = (gcnew System::Drawing::Font(L"Lucida Console", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MessageLbl->ForeColor = System::Drawing::Color::MediumTurquoise;
			this->MessageLbl->Location = System::Drawing::Point(157, 738);
			this->MessageLbl->Name = L"MessageLbl";
			this->MessageLbl->Size = System::Drawing::Size(204, 35);
			this->MessageLbl->TabIndex = 46;
			this->MessageLbl->Text = L"ПОДСКАЗКИ";
			// 
			// PersonFace1Lbl
			// 
			this->PersonFace1Lbl->AutoSize = true;
			this->PersonFace1Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PersonFace1Lbl->Location = System::Drawing::Point(955, 391);
			this->PersonFace1Lbl->Name = L"PersonFace1Lbl";
			this->PersonFace1Lbl->Size = System::Drawing::Size(70, 13);
			this->PersonFace1Lbl->TabIndex = 47;
			this->PersonFace1Lbl->Text = L"PersonFace1";
			// 
			// PersonFace2Lbl
			// 
			this->PersonFace2Lbl->AutoSize = true;
			this->PersonFace2Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PersonFace2Lbl->Location = System::Drawing::Point(1176, 391);
			this->PersonFace2Lbl->Name = L"PersonFace2Lbl";
			this->PersonFace2Lbl->Size = System::Drawing::Size(70, 13);
			this->PersonFace2Lbl->TabIndex = 48;
			this->PersonFace2Lbl->Text = L"PersonFace2";
			// 
			// PersonFace3Lbl
			// 
			this->PersonFace3Lbl->AutoSize = true;
			this->PersonFace3Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PersonFace3Lbl->Location = System::Drawing::Point(1376, 391);
			this->PersonFace3Lbl->Name = L"PersonFace3Lbl";
			this->PersonFace3Lbl->Size = System::Drawing::Size(70, 13);
			this->PersonFace3Lbl->TabIndex = 49;
			this->PersonFace3Lbl->Text = L"PersonFace3";
			// 
			// Similar1Lbl
			// 
			this->Similar1Lbl->AutoSize = true;
			this->Similar1Lbl->Location = System::Drawing::Point(1024, 420);
			this->Similar1Lbl->Name = L"Similar1Lbl";
			this->Similar1Lbl->Size = System::Drawing::Size(57, 13);
			this->Similar1Lbl->TabIndex = 50;
			this->Similar1Lbl->Text = L"Similar1Lbl";
			// 
			// Similar2Lbl
			// 
			this->Similar2Lbl->AutoSize = true;
			this->Similar2Lbl->Location = System::Drawing::Point(1235, 421);
			this->Similar2Lbl->Name = L"Similar2Lbl";
			this->Similar2Lbl->Size = System::Drawing::Size(57, 13);
			this->Similar2Lbl->TabIndex = 51;
			this->Similar2Lbl->Text = L"Similar2Lbl";
			// 
			// Similar3Lbl
			// 
			this->Similar3Lbl->AutoSize = true;
			this->Similar3Lbl->Location = System::Drawing::Point(1431, 420);
			this->Similar3Lbl->Name = L"Similar3Lbl";
			this->Similar3Lbl->Size = System::Drawing::Size(57, 13);
			this->Similar3Lbl->TabIndex = 52;
			this->Similar3Lbl->Text = L"Similar3Lbl";
			// 
			// surplbl
			// 
			this->surplbl->AutoSize = true;
			this->surplbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->surplbl->Location = System::Drawing::Point(794, 596);
			this->surplbl->Name = L"surplbl";
			this->surplbl->Size = System::Drawing::Size(48, 16);
			this->surplbl->TabIndex = 53;
			this->surplbl->Text = L"surplbl";
			// 
			// sadlbl
			// 
			this->sadlbl->AutoSize = true;
			this->sadlbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sadlbl->Location = System::Drawing::Point(931, 596);
			this->sadlbl->Name = L"sadlbl";
			this->sadlbl->Size = System::Drawing::Size(45, 16);
			this->sadlbl->TabIndex = 54;
			this->sadlbl->Text = L"sadlbl";
			// 
			// happylbl
			// 
			this->happylbl->AutoSize = true;
			this->happylbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->happylbl->Location = System::Drawing::Point(1065, 596);
			this->happylbl->Name = L"happylbl";
			this->happylbl->Size = System::Drawing::Size(60, 16);
			this->happylbl->TabIndex = 55;
			this->happylbl->Text = L"happylbl";
			// 
			// dislbl
			// 
			this->dislbl->AutoSize = true;
			this->dislbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dislbl->Location = System::Drawing::Point(808, 746);
			this->dislbl->Name = L"dislbl";
			this->dislbl->Size = System::Drawing::Size(40, 16);
			this->dislbl->TabIndex = 56;
			this->dislbl->Text = L"dislbl";
			// 
			// anglbl
			// 
			this->anglbl->AutoSize = true;
			this->anglbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->anglbl->Location = System::Drawing::Point(914, 746);
			this->anglbl->Name = L"anglbl";
			this->anglbl->Size = System::Drawing::Size(45, 16);
			this->anglbl->TabIndex = 57;
			this->anglbl->Text = L"anglbl";
			// 
			// eyesLbl
			// 
			this->eyesLbl->AutoSize = true;
			this->eyesLbl->Location = System::Drawing::Point(175, 813);
			this->eyesLbl->Name = L"eyesLbl";
			this->eyesLbl->Size = System::Drawing::Size(43, 13);
			this->eyesLbl->TabIndex = 58;
			this->eyesLbl->Text = L"eyesLbl";
			// 
			// XLbl
			// 
			this->XLbl->AutoSize = true;
			this->XLbl->Location = System::Drawing::Point(450, 813);
			this->XLbl->Name = L"XLbl";
			this->XLbl->Size = System::Drawing::Size(28, 13);
			this->XLbl->TabIndex = 59;
			this->XLbl->Text = L"XLbl";
			// 
			// YLbl
			// 
			this->YLbl->AutoSize = true;
			this->YLbl->Location = System::Drawing::Point(511, 813);
			this->YLbl->Name = L"YLbl";
			this->YLbl->Size = System::Drawing::Size(28, 13);
			this->YLbl->TabIndex = 60;
			this->YLbl->Text = L"YLbl";
			// 
			// ZLbl
			// 
			this->ZLbl->AutoSize = true;
			this->ZLbl->Location = System::Drawing::Point(574, 813);
			this->ZLbl->Name = L"ZLbl";
			this->ZLbl->Size = System::Drawing::Size(28, 13);
			this->ZLbl->TabIndex = 61;
			this->ZLbl->Text = L"ZLbl";
			// 
			// fearlbl
			// 
			this->fearlbl->AutoSize = true;
			this->fearlbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fearlbl->Location = System::Drawing::Point(1065, 746);
			this->fearlbl->Name = L"fearlbl";
			this->fearlbl->Size = System::Drawing::Size(45, 16);
			this->fearlbl->TabIndex = 62;
			this->fearlbl->Text = L"fearlbl";
			// 
			// progressBar2
			// 
			this->progressBar2->ForeColor = System::Drawing::Color::Turquoise;
			this->progressBar2->Location = System::Drawing::Point(1305, 547);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(212, 23);
			this->progressBar2->TabIndex = 64;
			// 
			// progressBar3
			// 
			this->progressBar3->ForeColor = System::Drawing::Color::Turquoise;
			this->progressBar3->Location = System::Drawing::Point(1305, 594);
			this->progressBar3->Name = L"progressBar3";
			this->progressBar3->Size = System::Drawing::Size(212, 23);
			this->progressBar3->TabIndex = 65;
			// 
			// progressBar4
			// 
			this->progressBar4->ForeColor = System::Drawing::Color::Turquoise;
			this->progressBar4->Location = System::Drawing::Point(1305, 640);
			this->progressBar4->Name = L"progressBar4";
			this->progressBar4->Size = System::Drawing::Size(212, 23);
			this->progressBar4->TabIndex = 66;
			// 
			// progressBar5
			// 
			this->progressBar5->ForeColor = System::Drawing::Color::Turquoise;
			this->progressBar5->Location = System::Drawing::Point(1305, 689);
			this->progressBar5->Name = L"progressBar5";
			this->progressBar5->Size = System::Drawing::Size(212, 23);
			this->progressBar5->TabIndex = 67;
			// 
			// progressBar6
			// 
			this->progressBar6->ForeColor = System::Drawing::Color::Turquoise;
			this->progressBar6->Location = System::Drawing::Point(1305, 738);
			this->progressBar6->Name = L"progressBar6";
			this->progressBar6->Size = System::Drawing::Size(212, 23);
			this->progressBar6->TabIndex = 68;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(1211, 514);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(81, 16);
			this->label10->TabIndex = 69;
			this->label10->Text = L"Удивление";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(1222, 689);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(57, 16);
			this->label12->TabIndex = 70;
			this->label12->Text = L"Печаль";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(1222, 640);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(62, 16);
			this->label14->TabIndex = 71;
			this->label14->Text = L"Радость";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(1202, 738);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(90, 16);
			this->label15->TabIndex = 72;
			this->label15->Text = L"Отвращение";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(1235, 596);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(39, 16);
			this->label16->TabIndex = 73;
			this->label16->Text = L"Гнев";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(1228, 554);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(46, 16);
			this->label17->TabIndex = 74;
			this->label17->Text = L"Страх";
			// 
			// progressBar1
			// 
			this->progressBar1->ForeColor = System::Drawing::Color::Turquoise;
			this->progressBar1->Location = System::Drawing::Point(1305, 507);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(212, 23);
			this->progressBar1->TabIndex = 75;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Lucida Console", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->ForeColor = System::Drawing::Color::Turquoise;
			this->label18->Location = System::Drawing::Point(876, 455);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(94, 21);
			this->label18->TabIndex = 76;
			this->label18->Text = L"ЭМОЦИИ";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Lucida Console", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->ForeColor = System::Drawing::Color::Turquoise;
			this->label19->Location = System::Drawing::Point(1221, 465);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(318, 21);
			this->label19->TabIndex = 77;
			this->label19->Text = L"ГИСТОГРАММЫ НАКОПЛЕНИЯ";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Lucida Console", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label20->ForeColor = System::Drawing::Color::Turquoise;
			this->label20->Location = System::Drawing::Point(1184, 193);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(192, 21);
			this->label20->TabIndex = 78;
			this->label20->Text = L"ИДЕНТИФИКАЦИЯ";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(246, 813);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(175, 13);
			this->label21->TabIndex = 79;
			this->label21->Text = L"Отклоненеи в градусах по осям: ";
			this->label21->Click += gcnew System::EventHandler(this, &Emotion::label21_Click);
			// 
			// Emotion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1575, 838);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->progressBar6);
			this->Controls->Add(this->progressBar5);
			this->Controls->Add(this->progressBar4);
			this->Controls->Add(this->progressBar3);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->fearlbl);
			this->Controls->Add(this->ZLbl);
			this->Controls->Add(this->YLbl);
			this->Controls->Add(this->XLbl);
			this->Controls->Add(this->eyesLbl);
			this->Controls->Add(this->anglbl);
			this->Controls->Add(this->dislbl);
			this->Controls->Add(this->happylbl);
			this->Controls->Add(this->sadlbl);
			this->Controls->Add(this->surplbl);
			this->Controls->Add(this->Similar3Lbl);
			this->Controls->Add(this->Similar2Lbl);
			this->Controls->Add(this->Similar1Lbl);
			this->Controls->Add(this->PersonFace3Lbl);
			this->Controls->Add(this->PersonFace2Lbl);
			this->Controls->Add(this->PersonFace1Lbl);
			this->Controls->Add(this->MessageLbl);
			this->Controls->Add(this->pictureBox12);
			this->Controls->Add(this->pictureBox11);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Emotion";
			this->Text = L"Emotion";
			this->Load += gcnew System::EventHandler(this, &Emotion::Emotion_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		/*private: delegate void MyDelegate(TextBox^ t, String^ s);
			 void updateTextBox8(TextBox^ t, String^ val) {
			t->Text = val;
		}
		*/

#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		stop = false;
		vector<string> a, arguments;
		arguments.push_back("E:/openface2/OpenFace-OpenFace_v0.2/build3/bin/Release/test2.exe");
		arguments.push_back("-f");
		arguments.push_back("E:/openface2/s01_13.jpg");
		arguments.push_back("-of");
		arguments.push_back("E:/openface2/test1.txt");

		cv::Mat image_smile1, image_smile2, image_smile3, image_smile4, image_smile5, image_smile6, image_smile7, image_quession;
		/*
		cv::Mat image_smile1_f= cv::imread("E://project_face_registration//faceregistration2//build//exe//Emotion//neutral2.png");

		cv::Mat image_smile2_f = cv::imread("E://project_face_registration//faceregistration2//build//exe//Emotion//surprise.jpg");

		cv::Mat image_smile3_f = cv::imread("E://project_face_registration//faceregistration2//build//exe//Emotion//fear.png");

		cv::Mat image_smile4_f = cv::imread("E://project_face_registration//faceregistration2//build//exe//Emotion//anger2.jpg");
	
		cv::Mat image_smile5_f = cv::imread("E://project_face_registration//faceregistration2//build//exe//Emotion//happiness.png");

		cv::Mat image_smile6_f = cv::imread("E://project_face_registration//faceregistration2//build//exe//Emotion//sad.jpg");

		cv::Mat image_smile7_f = cv::imread("E://project_face_registration//faceregistration2//build//exe//Emotion//disgust2.png");
		*/
		int emotion_counter=0;

		progressBar1->Minimum = 0; 
		progressBar1->Maximum = 100; 
		//progressBar1->Step = 1;
		progressBar2->Minimum = 0;
		progressBar2->Maximum = 100;
		progressBar3->Minimum = 0;
		progressBar3->Maximum = 100;
		progressBar4->Minimum = 0;
		progressBar4->Maximum = 100;
		progressBar5->Minimum = 0;
		progressBar5->Maximum = 100;
		progressBar6->Minimum = 0;
		progressBar6->Maximum = 100;

		progressBar1->Value = 0;
		progressBar2->Value = 0;
		progressBar3->Value = 0;
		progressBar4->Value = 0;
		progressBar5->Value = 0;
		progressBar6->Value = 0;

	

		int Value1 = 0, Value2 = 0, Value3 = 0, Value4 = 0, Value5 = 0, Value6 = 0;

		cv::Mat image_smile1_f = cv::imread("neutral2.png");
		cv::Mat image_smile2_f = cv::imread("surprise.jpg");
		cv::Mat image_smile3_f = cv::imread("fear.png");
		cv::Mat image_smile4_f = cv::imread("anger2.jpg");
		cv::Mat image_smile5_f = cv::imread("happiness.png");
		cv::Mat image_smile6_f = cv::imread("sad.jpg");
		cv::Mat image_smile7_f = cv::imread("disgust2.png");


		cv::Mat image_quession_f = cv::imread("quession.jpg");
		

		/*cv::Mat image_smile2_f = cv::imread("1.png");
		cv::Mat image_smile3_f = cv::imread("2.png");
		cv::Mat image_smile5_f = cv::imread("3.png");
		cv::Mat image_smile6_f = cv::imread("4.png");
		cv::Mat image_smile4_f = cv::imread("5.png");
		*/

		cv::resize(image_smile1_f, image_smile1, cv::Size(640, 480), 0, 0, cv::INTER_AREA);
		cv::resize(image_smile2_f, image_smile2, cv::Size(640, 480), 0, 0, cv::INTER_AREA);
		cv::resize(image_smile3_f, image_smile3, cv::Size(640, 480), 0, 0, cv::INTER_AREA);
		cv::resize(image_smile4_f, image_smile4, cv::Size(640, 480), 0, 0, cv::INTER_AREA);
		cv::resize(image_smile5_f, image_smile5, cv::Size(640, 480), 0, 0, cv::INTER_AREA);
		cv::resize(image_smile6_f, image_smile6, cv::Size(640, 480), 0, 0, cv::INTER_AREA);
		cv::resize(image_smile7_f, image_smile7, cv::Size(640, 480), 0, 0, cv::INTER_AREA);

		cv::resize(image_quession_f, image_quession, cv::Size(640, 480), 0, 0, cv::INTER_AREA);

		cv::Mat image_name;
		cv::Mat image_name_1 = cv::imread("name.jpg");
		cv::resize(image_name_1, image_name, cv::Size(640, 480), 0, 0, cv::INTER_AREA);
		/*
		cv::imshow("Image1", image_smile1);
		cv::waitKey(0);

		cv::imshow("Image2", image_smile2);
		cv::waitKey(0);

		cv::imshow("Image3", image_smile3);
		cv::waitKey(0);

		cv::imshow("Image4", image_smile4);
		cv::waitKey(0);

		cv::imshow("Image5", image_smile5);
		cv::waitKey(0);

		cv::imshow("Image6", image_smile6);
		cv::waitKey(0);
		cv::imshow("Image7", image_smile7);
		cv::waitKey(0);
		*/
		

		cv::Mat image;
		cv::VideoCapture cap(0);
		int strQ1 = 0;


		for (;;)
			//for (int i = 0; i < 3; i++)
		{
			System::Drawing::Graphics^ graphics_name = pictureBox12->CreateGraphics();
			System::IntPtr ptr_name(image_name.ptr());
			System::Drawing::Bitmap^ b_name = gcnew System::Drawing::Bitmap(image_name.cols, image_name.rows, image_name.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_name);
			System::Drawing::RectangleF rect_name(0, 0, pictureBox12->Width, pictureBox12->Height);
			graphics_name->DrawImage(b_name, rect_name);

			//surprise
			System::Drawing::Graphics^ graphics_surprise = pictureBox4->CreateGraphics();
			System::IntPtr ptr_surprise(image_smile2.ptr());
			System::Drawing::Bitmap^ b_surprise = gcnew System::Drawing::Bitmap(image_smile2.cols, image_smile2.rows, image_smile2.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_surprise);
			System::Drawing::RectangleF rect_surprise(0, 0, pictureBox4->Width, pictureBox4->Height);
			graphics_surprise->DrawImage(b_surprise, rect_surprise);

			//anger
			System::Drawing::Graphics^ graphics_anger = pictureBox6->CreateGraphics();
			System::IntPtr ptr_anger(image_smile4.ptr());
			System::Drawing::Bitmap^ b_anger = gcnew System::Drawing::Bitmap(image_smile4.cols, image_smile4.rows, image_smile4.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_anger);
			System::Drawing::RectangleF rect_anger(0, 0, pictureBox6->Width, pictureBox6->Height);
			graphics_anger->DrawImage(b_anger, rect_anger);

			//fear
			System::Drawing::Graphics^ graphics_fear = pictureBox8->CreateGraphics();
			System::IntPtr ptr_fear(image_smile3.ptr());
			System::Drawing::Bitmap^ b_fear = gcnew System::Drawing::Bitmap(image_smile3.cols, image_smile3.rows, image_smile3.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_fear);
			System::Drawing::RectangleF rect_fear(0, 0, pictureBox8->Width, pictureBox8->Height);
			graphics_fear->DrawImage(b_fear, rect_fear);

			//sad
			System::Drawing::Graphics^ graphics_sad = pictureBox5->CreateGraphics();
			System::IntPtr ptr_sad(image_smile6.ptr());
			System::Drawing::Bitmap^ b_sad = gcnew System::Drawing::Bitmap(image_smile6.cols, image_smile6.rows, image_smile6.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_sad);
			System::Drawing::RectangleF rect_sad(0, 0, pictureBox5->Width, pictureBox5->Height);
			graphics_sad->DrawImage(b_sad, rect_sad);

			//disgust
			System::Drawing::Graphics^ graphics_disgust = pictureBox3->CreateGraphics();
			System::IntPtr ptr_disgust(image_smile7.ptr());
			System::Drawing::Bitmap^ b_disgust = gcnew System::Drawing::Bitmap(image_smile7.cols, image_smile7.rows, image_smile7.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_disgust);
			System::Drawing::RectangleF rect_disgust(0, 0, pictureBox3->Width, pictureBox3->Height);
			graphics_disgust->DrawImage(b_disgust, rect_disgust);

			//happiness
			System::Drawing::Graphics^ graphics_happiness = pictureBox7->CreateGraphics();
			System::IntPtr ptr_happiness(image_smile5.ptr());
			System::Drawing::Bitmap^ b_happiness = gcnew System::Drawing::Bitmap(image_smile5.cols, image_smile5.rows, image_smile5.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_happiness);
			System::Drawing::RectangleF rect_happiness(0, 0, pictureBox7->Width, pictureBox7->Height);
			graphics_happiness->DrawImage(b_happiness, rect_happiness);

			cv::Mat frame;
			cap >> frame;
			image = frame.clone();
			//if (frame.empty()) break; // end of video stream
			//cv::imshow("this is you, smile! :)", frame);
			//cvWaitKey(1);

			//cv::circle(image, cv::Point(200, 200), 30, cv::Scalar(103, 234, 200), 1,8);
			//cv::circle(image, cv::Point(300, 300), 30, cv::Scalar(103, 234, 200), 1,8);
			
			/*
			System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
			System::IntPtr ptr(image.ptr());
			System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(image.cols, image.rows, image.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			System::Drawing::RectangleF rect(0, 0, pictureBox1->Width, pictureBox1->Height);
			graphics->DrawImage(b, rect);
			*/

			//FaceLandmarkImg::Emotion(arguments);
			//vector<string> a = FaceLandmarkImg::PoseHeadFrame3(arguments, clnf_model, frame);
			vector<string> e = FaceLandmarkImg::Emotion(arguments, frame);
			
			//cv::Mat image_smile;
			/*std::string siz = std::to_string(e.size());
			String^ sixxxx = gcnew String(siz.c_str());
			textBox1->Text = sixxxx;
			*/
			//if (e.size() != 0)
			if (e.size() != 1)
			{
				int face_count = std::stoi(e[150]);
				if (face_count == 1)
				{
					for (int i = 14; i < 150; i = i + 2)
					{
						int pointX = std::stoi(e[i]);
						int pointY = std::stoi(e[i + 1]);
						cv::circle(image, cv::Point(pointX, pointY), 3, cv::Scalar(200, 234, 103), 1, 8);
						//cv::imshow("face", image);
						//cv::waitKey(0);
					}

					System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
					System::IntPtr ptr(image.ptr());
					System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(image.cols, image.rows, image.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
					System::Drawing::RectangleF rect(0, 0, pictureBox1->Width, pictureBox1->Height);
					graphics->DrawImage(b, rect);


					string eyes = e[13];

					int eyes_n = atoi(eyes.c_str());
					string eyes_new = std::to_string(eyes_n);

					String^ eye = gcnew String(eyes_new.c_str());
					//textBox12->Text = eye;
					eyesLbl->Text = eye;

					int eyes_distanse = atoi(eyes.c_str());

					if (eyes_distanse > 30)
					{
						string pose1 = e[10];
						string pose2 = e[11];
						string pose3 = e[12];

						int pose_x = atoi(pose1.c_str());
						int pose_y = atoi(pose2.c_str());
						int pose_z = atoi(pose3.c_str());

						string Pose1 = std::to_string(pose_x);
						string Pose2 = std::to_string(pose_y);
						string Pose3 = std::to_string(pose_z);

						String^ poseX = gcnew String(Pose1.c_str());
						//textBox9->Text = poseX;
						XLbl->Text = poseX;

						String^ poseY = gcnew String(Pose2.c_str());
						//textBox10->Text = poseY;
						YLbl->Text = poseY;

						String^ poseZ = gcnew String(Pose3.c_str());
						//textBox11->Text = poseZ;
						ZLbl->Text = poseZ;

						

						if ((pose_x < 7) && (pose_y < 7) && (pose_z < 7) && (pose_x > -7) && (pose_y > -7) && (pose_z > -7))
						{
							emotion_counter++;

							std::string text8 = " ";
							String^ strT = gcnew String(text8.c_str());
							//textBox8->Text = strT;
							MessageLbl->Text = strT;


							cv::Mat image_smile;

							string strE1 = e[0];

							if (strE1 == "neutral")
							{
								image_smile = image_smile1;


							}

							if (strE1 == "surprise")
							{
								image_smile = image_smile2;
								Value1 += 1;


							}
							if (strE1 == "fear")
							{
								image_smile = image_smile3;
								Value2 += 1;

							}
							if (strE1 == "anger")
							{
								image_smile = image_smile4;
								Value3 += 1;

							}
							if (strE1 == "happiness")
							{
								image_smile = image_smile5;
								Value4 += 1;

							}
							if (strE1 == "sad")
							{
								image_smile = image_smile6;
								Value5 += 1;

							}
							if (strE1 == "disgust")
							{
								image_smile = image_smile7;
								Value6 += 1;

							}

							progressBar1->Value = round((Value1)*100 / emotion_counter);
							progressBar2->Value = round((Value2)*100 / emotion_counter);
							progressBar3->Value = round((Value3)*100 / emotion_counter);
							progressBar4->Value = round((Value4)*100 / emotion_counter);
							progressBar5->Value = round((Value5)*100 / emotion_counter);
							progressBar6->Value = round((Value6)*100 / emotion_counter);

							System::Drawing::Graphics^ graphics_emotion = pictureBox2->CreateGraphics();
							System::IntPtr ptr2(image_smile.ptr());
							System::Drawing::Bitmap^ image_smile_bit = gcnew System::Drawing::Bitmap(image_smile.cols, image_smile.rows, image_smile.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr2);
							System::Drawing::RectangleF rect2(0, 0, pictureBox2->Width, pictureBox2->Height);
							graphics_emotion->DrawImage(image_smile_bit, rect2);

							if (strE1 != "neutral")
							{

								string strE12 = e[4];
								string strE2 = e[5];
								string strE3 = e[6];
								string strE4 = e[7];
								string strE5 = e[8];
								string strE6 = e[9];

								String^ strE1r = gcnew String(strE12.c_str());
								String^ strE2r = gcnew String(strE2.c_str());
								String^ strE3r = gcnew String(strE3.c_str());
								String^ strE4r = gcnew String(strE4.c_str());
								String^ strE5r = gcnew String(strE5.c_str());
								String^ strE6r = gcnew String(strE6.c_str());

								/*
								textBox1->Text = strE1r;
								textBox2->Text = strE2r;
								textBox3->Text = strE3r;
								textBox4->Text = strE4r;
								textBox5->Text = strE5r;
								textBox6->Text = strE6r;
								*/
								surplbl->Text = strE1r;
								fearlbl->Text = strE2r;
								happylbl->Text = strE3r;
								sadlbl->Text = strE4r;
								dislbl->Text = strE5r;
								anglbl->Text = strE6r;



								delete strE1r;
								delete strE2r;
								delete strE3r;
								delete strE4r;
								delete strE5r;
								delete strE6r;
							}

							else
							{
								
								//recognition
								//std::vector<std::string> strd = FaceRecDLib::Recognition(frame);
								std::vector<std::pair<std::pair<std::string, std::string>, double>> strd = FaceRecDLib::Recognition(frame);
								//int a = strd.length();
								//std::string n = ::to_string(a);
								//String^ strD = gcnew String(n.c_str());
								//textBox7->Text = strD;
								
								double level_first = strd[0].second;
								int level1 = round((1-strd[0].second)*100);
								int level2 = round((1-strd[1].second)*100);
								int level3 = round((1-strd[2].second)*100);
								std::string level1_str, level2_str, level3_str;
								level1_str = std::to_string(level1) + "%";
								level2_str = std::to_string(level2) + "%";
								level3_str = std::to_string(level3) + "%";

								if (level_first <= 0.55)
								{

									String^ name1 = gcnew String(strd[0].first.first.c_str());
									//textBox13->Text = name1;
									PersonFace1Lbl->Text = name1;

									String^ name2 = gcnew String(strd[1].first.first.c_str());
									//textBox14->Text = name2;
									PersonFace2Lbl->Text = name2;

									String^ name3 = gcnew String(strd[2].first.first.c_str());
									//textBox15->Text = name3;
									PersonFace3Lbl->Text = name3;

									String^ level1 = gcnew String(level1_str.c_str());
									//textBox16->Text = level1;
									Similar1Lbl->Text = level1;

									String^ level2 = gcnew String(level2_str.c_str());
									//textBox17->Text = level2;
									Similar2Lbl->Text = level2;

									String^ level3 = gcnew String(level3_str.c_str());
									//textBox18->Text = level3;
									Similar3Lbl->Text = level3;
									

									cv::Mat image_person1, image_person2, image_person3;

									cv::Mat image_person1_nc = cv::imread("face_database_name\\"+ strd[0].first.second);
									cv::resize(image_person1_nc, image_person1, cv::Size(640, 480), 0, 0, cv::INTER_AREA);

									cv::Mat image_person2_nc = cv::imread("face_database_name\\" + strd[1].first.second);
									cv::resize(image_person2_nc, image_person2, cv::Size(640, 480), 0, 0, cv::INTER_AREA);

									cv::Mat image_person3_nc = cv::imread("face_database_name\\" + strd[2].first.second);
									cv::resize(image_person3_nc, image_person3, cv::Size(640, 480), 0, 0, cv::INTER_AREA);

									System::Drawing::Graphics^ graphics_person1 = pictureBox9->CreateGraphics();
									System::IntPtr ptr_person1(image_person1.ptr());
									System::Drawing::Bitmap^ image_person1_1 = gcnew System::Drawing::Bitmap(image_person1.cols, image_person1.rows, image_person1.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_person1);
									System::Drawing::RectangleF rect_person1(0, 0, pictureBox9->Width, pictureBox9->Height);
									graphics_person1->DrawImage(image_person1_1, rect_person1);

									System::Drawing::Graphics^ graphics_person2 = pictureBox10->CreateGraphics();
									System::IntPtr ptr_person2(image_person2.ptr());
									System::Drawing::Bitmap^ image_person2_2 = gcnew System::Drawing::Bitmap(image_person1.cols, image_person2.rows, image_person2.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_person2);
									System::Drawing::RectangleF rect_person2(0, 0, pictureBox10->Width, pictureBox10->Height);
									graphics_person2->DrawImage(image_person2_2, rect_person2);

									System::Drawing::Graphics^ graphics_person3 = pictureBox11->CreateGraphics();
									System::IntPtr ptr_person3(image_person3.ptr());
									System::Drawing::Bitmap^ image_person3_3 = gcnew System::Drawing::Bitmap(image_person3.cols, image_person3.rows, image_person3.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_person3);
									System::Drawing::RectangleF rect_person3(0, 0, pictureBox11->Width, pictureBox11->Height);
									graphics_person3->DrawImage(image_person3_3, rect_person3);
								
								}
								else
								{
									std::string text8 = "ПОРА МЕНЯТЬ ФОТО НА ПОРТАЛЕ";
									String^ strT = gcnew String(text8.c_str());
									//textBox8->Text = strT;
									MessageLbl->Text = strT;

									System::Drawing::Graphics^ graphics_q1 = pictureBox9->CreateGraphics();
									System::IntPtr ptr_q1(image_quession.ptr());
									System::Drawing::Bitmap^ image_q1 = gcnew System::Drawing::Bitmap(image_quession.cols, image_quession.rows, image_quession.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_q1);
									System::Drawing::RectangleF rect_q1(0, 0, pictureBox9->Width, pictureBox9->Height);
									graphics_q1->DrawImage(image_q1, rect_q1);

									System::Drawing::Graphics^ graphics_q2 = pictureBox10->CreateGraphics();
									System::IntPtr ptr_q2(image_quession.ptr());
									System::Drawing::Bitmap^ image_q2 = gcnew System::Drawing::Bitmap(image_quession.cols, image_quession.rows, image_quession.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_q2);
									System::Drawing::RectangleF rect_q2(0, 0, pictureBox10->Width, pictureBox10->Height);
									graphics_q2->DrawImage(image_q2, rect_q2);

									System::Drawing::Graphics^ graphics_q3 = pictureBox11->CreateGraphics();
									System::IntPtr ptr_q3(image_quession.ptr());
									System::Drawing::Bitmap^ image_q3 = gcnew System::Drawing::Bitmap(image_quession.cols, image_quession.rows, image_quession.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_q3);
									System::Drawing::RectangleF rect_q3(0, 0, pictureBox11->Width, pictureBox11->Height);
									graphics_q3->DrawImage(image_q3, rect_q3);

								}
								

								string s1 = "0%";
								String^ str = gcnew String(s1.c_str());
								/*
								textBox1->Text = str;
								textBox2->Text = str;
								textBox3->Text = str;
								textBox4->Text = str;
								textBox5->Text = str;
								textBox6->Text = str;
								*/
								surplbl->Text = str;
								fearlbl->Text = str;
								happylbl->Text = str;
								sadlbl->Text = str;
								dislbl->Text = str;
								anglbl->Text = str;
								
							}
							

							delete image_smile_bit;
							

						}
						else
						{
							System::Drawing::Graphics^ graphics_q = pictureBox2->CreateGraphics();
							System::IntPtr ptr_q(image_quession.ptr());
							System::Drawing::Bitmap^ image_smile_q = gcnew System::Drawing::Bitmap(image_quession.cols, image_quession.rows, image_quession.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_q);
							System::Drawing::RectangleF rect_q(0, 0, pictureBox2->Width, pictureBox2->Height);
							graphics_q->DrawImage(image_smile_q, rect_q);

							std::string text7 = "СМОТРИТЕ ПРЯМО";
							String^ strT = gcnew String(text7.c_str());
							//textBox8->Text = strT;
							MessageLbl->Text = strT;
						}

					}

					else
					{

						std::string text7 = "ПОДОЙДИТЕ БЛИЖЕ";
						String^ strT1 = gcnew String(text7.c_str());
						//textBox8->Text = strT;
						MessageLbl->Text = strT1;
					}

				}

				else
				{
					emotion_counter = 0;
					Value1 = 0;
					Value2 = 0;
					Value3 = 0;
					Value4 = 0;
					Value5 = 0;
					Value6 = 0;

					progressBar1->Value = 0;
					progressBar2->Value = 0;
					progressBar3->Value = 0;
					progressBar4->Value = 0;
					progressBar5->Value = 0;
					progressBar6->Value = 0;

					System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
					System::IntPtr ptr(frame.ptr());
					System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
					System::Drawing::RectangleF rect(0, 0, pictureBox1->Width, pictureBox1->Height);
					graphics->DrawImage(b, rect);

					std::string text8 = "СЛИШКОМ МНОГО ЛИЦ";
					String^ strT8 = gcnew String(text8.c_str());
					//textBox8->Text = strT8;
					MessageLbl->Text = strT8;
					//textBox8->BeginInvoke(gcnew MyDelegate(this, &Emotion::updateTextBox8), strT8);
				}


				if (stop)
				{

					break;
				}
			}

			else
			{
				emotion_counter = 0;
				Value1 = 0;
				Value2 = 0;
				Value3 = 0;
				Value4 = 0;
				Value5 = 0;
				Value6 = 0;

				progressBar1->Value = 0;
				progressBar2->Value = 0;
				progressBar3->Value = 0;
				progressBar4->Value = 0;
				progressBar5->Value = 0;
				progressBar6->Value = 0;

				System::Drawing::Graphics^ graphics_q1 = pictureBox9->CreateGraphics();
				System::IntPtr ptr_q1(image_quession.ptr());
				System::Drawing::Bitmap^ image_q1 = gcnew System::Drawing::Bitmap(image_quession.cols, image_quession.rows, image_quession.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_q1);
				System::Drawing::RectangleF rect_q1(0, 0, pictureBox9->Width, pictureBox9->Height);
				graphics_q1->DrawImage(image_q1, rect_q1);

				System::Drawing::Graphics^ graphics_q2 = pictureBox10->CreateGraphics();
				System::IntPtr ptr_q2(image_quession.ptr());
				System::Drawing::Bitmap^ image_q2 = gcnew System::Drawing::Bitmap(image_quession.cols, image_quession.rows, image_quession.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_q2);
				System::Drawing::RectangleF rect_q2(0, 0, pictureBox10->Width, pictureBox10->Height);
				graphics_q2->DrawImage(image_q2, rect_q2);

				System::Drawing::Graphics^ graphics_q3 = pictureBox11->CreateGraphics();
				System::IntPtr ptr_q3(image_quession.ptr());
				System::Drawing::Bitmap^ image_q3 = gcnew System::Drawing::Bitmap(image_quession.cols, image_quession.rows, image_quession.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr_q3);
				System::Drawing::RectangleF rect_q3(0, 0, pictureBox11->Width, pictureBox11->Height);
				graphics_q3->DrawImage(image_q3, rect_q3);


				System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
				System::IntPtr ptr(frame.ptr());
				System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
				System::Drawing::RectangleF rect(0, 0, pictureBox1->Width, pictureBox1->Height);
				graphics->DrawImage(b, rect);

				std::string text7 = "ЛИЦО НЕ НАЙДЕНО";
				String^ strT7 = gcnew String(text7.c_str());
				//textBox8->Text = strT;
				MessageLbl->Text = strT7;
			}
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		stop = true;
	}
	private: System::Void recognition_Click(System::Object^  sender, System::EventArgs^  e) {
		/*
	stop = false;
	cv::Mat image;
	cv::VideoCapture cap(0);
	//textBox1->Text = "0";
	for (;;)
		//for (int i = 0; i < 3; i++)
	{
		cv::Mat frame;
		cap >> frame;
		image = frame.clone();
		//textBox1->Text = "1";
		//std::string str = FaceRecDLib::Recognition(image);
		//textBox1->Text = "2";
		System::Drawing::Graphics^ graphics_emotion = pictureBox1->CreateGraphics();
		System::IntPtr ptr2(image.ptr());
		System::Drawing::Bitmap^ image_smile_bit = gcnew System::Drawing::Bitmap(image.cols, image.rows, image.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr2);
		System::Drawing::RectangleF rect2(0, 0, pictureBox1->Width, pictureBox1->Height);
		graphics_emotion->DrawImage(image_smile_bit, rect2);
		//textBox1->Text = "3";
		std::string str = "0";
		int a = str.length();
		std::string n = ::to_string(a);
		String^ strE1r = gcnew String(n.c_str());
		//textBox1->Text = "4";
		//textBox1->Text = strE1r;

		if (stop)
		{

			break;
		}
	}
	*/

}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	stop = false;
	cv::Mat image;
	cv::VideoCapture cap(0);
	int i;


	for (;;)
		//for (int i = 0; i < 3; i++)
	{
		cv::Mat frame;
		cap >> frame;
		image = frame.clone();
		i++;
		System::Drawing::Graphics^ graphics_emotion = pictureBox1->CreateGraphics();
		System::IntPtr ptr2(image.ptr());
		System::Drawing::Bitmap^ image_smile_bit = gcnew System::Drawing::Bitmap(image.cols, image.rows, image.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr2);
		System::Drawing::RectangleF rect2(0, 0, pictureBox1->Width, pictureBox1->Height);
		graphics_emotion->DrawImage(image_smile_bit, rect2);

		//if (frame.empty()) break; // end of video stream
		//cv::imshow("this is you, smile! :)", frame);
		//cvWaitKey(1);
		//std::string str = "0";
		//int a = str.length();
		//std::string n = ::to_string(i);
		//String^ strE1r = gcnew String(n.c_str());
		//textBox1->Text = strE1r;

		if (stop)
		{

			break;
		}
	}
	

}
private: System::Void pictureBox9_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void progressBar1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label21_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void Emotion_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}


/*

System::Drawing::Graphics^ graphics_emotion1 = pictureBox2->CreateGraphics();
System::IntPtr ptr1(image_smile1.ptr());
System::Drawing::Bitmap^ image_smile_bit1 = gcnew System::Drawing::Bitmap(image_smile1.cols, image_smile1.rows, image_smile1.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr1);
System::Drawing::RectangleF rect1(0, 0, pictureBox2->Width, pictureBox2->Height);

System::Drawing::Graphics^ graphics_emotion2 = pictureBox2->CreateGraphics();
System::IntPtr ptr2(image_smile2.ptr());
System::Drawing::Bitmap^ image_smile_bit2 = gcnew System::Drawing::Bitmap(image_smile2.cols, image_smile2.rows, image_smile2.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr2);
System::Drawing::RectangleF rect2(0, 0, pictureBox2->Width, pictureBox2->Height);

System::Drawing::Graphics^ graphics_emotion3 = pictureBox2->CreateGraphics();
System::IntPtr ptr3(image_smile3.ptr());
System::Drawing::Bitmap^ image_smile_bit3 = gcnew System::Drawing::Bitmap(image_smile3.cols, image_smile3.rows, image_smile3.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr3);
System::Drawing::RectangleF rect3(0, 0, pictureBox2->Width, pictureBox2->Height);

System::Drawing::Graphics^ graphics_emotion4 = pictureBox2->CreateGraphics();
System::IntPtr ptr4(image_smile4.ptr());
System::Drawing::Bitmap^ image_smile_bit4 = gcnew System::Drawing::Bitmap(image_smile4.cols, image_smile4.rows, image_smile4.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr4);
System::Drawing::RectangleF rect4(0, 0, pictureBox2->Width, pictureBox2->Height);

System::Drawing::Graphics^ graphics_emotion5 = pictureBox2->CreateGraphics();
System::IntPtr ptr5(image_smile5.ptr());
System::Drawing::Bitmap^ image_smile_bit5 = gcnew System::Drawing::Bitmap(image_smile5.cols, image_smile5.rows, image_smile5.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr5);
System::Drawing::RectangleF rect5(0, 0, pictureBox2->Width, pictureBox2->Height);

System::Drawing::Graphics^ graphics_emotion6 = pictureBox2->CreateGraphics();
System::IntPtr ptr6(image_smile6.ptr());
System::Drawing::Bitmap^ image_smile_bit6 = gcnew System::Drawing::Bitmap(image_smile6.cols, image_smile6.rows, image_smile6.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr6);
System::Drawing::RectangleF rect6(0, 0, pictureBox2->Width, pictureBox2->Height);

System::Drawing::Graphics^ graphics_emotion7 = pictureBox2->CreateGraphics();
System::IntPtr ptr7(image_smile7.ptr());
System::Drawing::Bitmap^ image_smile_bit7 = gcnew System::Drawing::Bitmap(image_smile7.cols, image_smile7.rows, image_smile7.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr7);
System::Drawing::RectangleF rect7(0, 0, pictureBox2->Width, pictureBox2->Height);*/