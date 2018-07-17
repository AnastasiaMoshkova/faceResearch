#include "basictypes.h"
#include "FaceRecDLib.h"

#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
//#include <future>
//#include <thread>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <dlib/assert.h>
#include <dlib/image_processing.h>
#include <dlib/dnn.h>
#include <dlib/clustering.h>
#include <dlib/string.h>
#include <dlib/image_io.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/opencv.h>
#include <dlib/image_transforms.h>
#include <dlib/opencv/cv_image.h>
#include <dlib/matrix/lapack/gesvd.h>
#include <dlib/matrix/lapack/gesdd.h>

  
std::string face_descriptor_calc(cv::Mat image_opencv)
{
	auto start3 = std::chrono::high_resolution_clock::now();

	static shape_predictor sp;
	static anet_type net;
	static frontal_face_detector detector = get_frontal_face_detector();
	static bool falg = true;

	if (falg)
	{
	deserialize("shape_predictor_68_face_landmarks.dat") >> sp;
	deserialize("dlib_face_recognition_resnet_model_v1.dat") >> net;
	falg = false;
	}

	cv::cvtColor(image_opencv, image_opencv, cv::COLOR_BGR2RGB);

	std::cout << std::noboolalpha << falg << " == " << std::boolalpha << falg << std::endl;
	std::cout << "deserialize \n" << std::endl;
	auto finish3 = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish3 - start3).count() << " ms" << std::endl;

	dlib::matrix<dlib::rgb_pixel> img(dlib::mat(dlib::cv_image<dlib::rgb_pixel>(image_opencv)));
	//matrix<rgb_pixel> img;
	//load_image(img, image_path);



	std::vector<matrix<rgb_pixel>> faces;

	for (auto face : detector(img))
	{
		auto shape = sp(img, face);
		matrix<rgb_pixel> face_chip;
		extract_image_chip(img, get_face_chip_details(shape, 150, 0.2), face_chip);
		faces.push_back(std::move(face_chip));
	}

	if (faces.size() > 0)
	{
		std::vector<matrix<float, 0, 1>> face_descriptors = net(faces);

		//string for descriptors
		std::string descriptors_string;

		std::string str;
		//float fVal;
		//	str = toString(fVal);

		for (int i = 0; i < face_descriptors[0].size(); i++)
		{
			str = toString(face_descriptors[0](i));
			descriptors_string += str + ',';
			str.clear();
		}

		return descriptors_string;
	}
	else
	{
		return "";
	}
}

std::vector<matrix<float, 0, 1>> string_to_float(std::string s) {

	matrix<float, 0, 1> matr;
	std::vector<matrix<float, 0, 1>> matr_vect;
	matr.set_size(128);
	int j = 0;
	std::string s1;
	std::vector<std::string> sv;
	std::vector<float> sf;
	float calc;

	for (int i = 0;i < s.size();i++)
	{
		if (s[i] != ',')
		{
			s1 = s1 + s[i];
		}
		if (s[i] == ',')
		{
			//sv.push_back(s1);
			//calc = fromString(s1);

			calc = fromString<float>(s1);

			sf.push_back(calc);
			matr(j) = calc;
			j++;

			s1.clear();
		}
	}

	matr_vect.push_back(matr);

	return matr_vect;
	//return sf;
}

double descriptions_compare(std::string descriptors_from_foto, std::string descriptors_from_base) {


	auto face_descriptors_from_foto = string_to_float(descriptors_from_foto);
	auto face_descriptors_from_base = string_to_float(descriptors_from_base);

	double level;
	level = length(face_descriptors_from_foto[0] - face_descriptors_from_base[0]);
	
	return level;
}

std::string float_to_string(std::vector<matrix<float, 0, 1>> face_descriptors)
{
	std::string descriptors_string;

	std::string str;
	//float fVal;
	//	str = toString(fVal);

	for (int i = 0; i < face_descriptors[0].size(); i++)
	{
		str = toString(face_descriptors[0](i));
		descriptors_string += str + ',';
		str.clear();
	}

	return descriptors_string;
}

/*std::vector<std::pair<std::string, std::string>> parser_file(std::string filename)
{
	std::cout << "parser" << std::endl;
	std::vector<std::pair<std::string, std::string>> descriptors_from_base;

	std::string str,name,desc;
	std::ifstream file(filename);
	if (file.is_open())
	{
		std::cout << "file is opend" << std::endl;
		while (!file.eof())
		{
			std::getline(file, str);

			if (str.empty()) {
				//std::cout << "kjdrfksdklf" << std::endl;
				continue;
			}
			//std::cout << "str " << str << std::endl;
			int ind = str.find(";");
			name = str.substr(0, ind);
			desc = str.substr(ind + 1);
			descriptors_from_base.push_back(std::make_pair(name, desc));
			str.clear();
		}
	}
	else {
		std::cout << "file is not opend" << std::endl;
	}
	return descriptors_from_base;
}
*/

std::vector<std::pair<std::pair<std::string, std::string>, std::string>> parser_file(std::string filename)
{
	std::cout << "parser" << std::endl;
	std::vector<std::pair<std::pair<std::string, std::string>, std::string>> descriptors_from_base;

	std::string str, name, desc,file_name;
	std::ifstream file(filename);
	if (file.is_open())
	{
		std::cout << "file is opend" << std::endl;
		while (!file.eof())
		{
			std::getline(file, str);

			if (str.empty()) {
				//std::cout << "kjdrfksdklf" << std::endl;
				continue;
			}
			//std::cout << "str " << str << std::endl;
			int ind = str.find(";");
			name = str.substr(0, ind);
			int ind2 = str.find(";",ind+1);
			file_name = str.substr(ind + 1, ind2- ind - 1);
			desc = str.substr(ind2 + 1);
			descriptors_from_base.push_back(std::make_pair(std::make_pair(name,file_name), desc));
			str.clear();
		}
	}
	else {
		std::cout << "file is not opend" << std::endl;
	}
	return descriptors_from_base;
}

//typedef std::pair<int, std::pair<int, int>> IntIntInt;
/*struct Compare {
	inline bool operator()(const std::pair<std::string, double> &x, const std::pair<std::string, double> &y) const {
		return x.second < y.second;
	}
};
*/

struct Compare {
	inline bool operator()(const std::pair<std::pair<std::string, std::string>, double> &x, const std::pair<std::pair<std::string, std::string>, double> &y) const {
		return x.second < y.second;
	}
};


//std::vector<std::string> FaceRecDLib::Recognition(cv::Mat image_opencv)
std::vector<std::pair<std::pair<std::string, std::string>, double>> FaceRecDLib::Recognition(cv::Mat image_opencv)
{


	//std::vector<std::string> result;
	std::vector<std::pair<std::pair<std::string, std::string>, double>> result;
	std::vector<std::pair<std::pair<std::string, std::string>, double>> level_descriptors;

	//static std::vector<std::pair<std::string, std::string>> descriptors_from_base = parser_file("E:\\project_face_registration\\faceregistration2\\faceReclibrary\\face_desc.txt");
	static std::vector<std::pair<std::pair<std::string, std::string>, std::string>> descriptors_from_base = parser_file("face_desc.txt");

	auto start3 = std::chrono::high_resolution_clock::now();

	std::string descriptors_from_foto = face_descriptor_calc(image_opencv);

	
	
	//for (int i = 0;i < descriptors_from_base.size();i++)
	//{
	//	std::cout << "descriptors_from_base " << descriptors_from_base[i].first << " " << descriptors_from_base[i].second << std::endl;
	//}
	//std::string descriptors_from_base;
	for (int i = 0;i < descriptors_from_base.size();i++)
	{
		double level = descriptions_compare(descriptors_from_foto, descriptors_from_base[i].second);
		//level_descriptors.push_back(std::make_pair(descriptors_from_base[i].first, level));
		level_descriptors.push_back(std::make_pair(descriptors_from_base[i].first, level));
		//std::cout << descriptors_from_base[i].first << " level " << level << std::endl;
	}

	

	//std::sort(level_descriptors.second.begin(), level_descriptors.second.end());

	std::sort(level_descriptors.begin(), level_descriptors.end(), Compare());

	for (int i = 0;i < descriptors_from_base.size();i++)
	{
		std::cout << level_descriptors[i].first.first << " FIO "<< level_descriptors[i].first.second << " level " << level_descriptors[i].second << std::endl;
	}

	std::cout << "time \n" << std::endl;
	auto finish3 = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish3 - start3).count() << " ms" << std::endl;
	//std::string name = "a";
	/*
	result.push_back(level_descriptors[0].first);
	result.push_back(level_descriptors[1].first);
	result.push_back(level_descriptors[2].first);
	result.push_back(std::to_string(level_descriptors[0].second));
	result.push_back(std::to_string(level_descriptors[1].second));
	result.push_back(std::to_string(level_descriptors[2].second));
	*/
	result.push_back(level_descriptors[0]);
	result.push_back(level_descriptors[1]);
	result.push_back(level_descriptors[2]);

	return result;
}

