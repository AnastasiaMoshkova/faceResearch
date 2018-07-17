

//#include "basictypes.h"


#pragma once


#ifdef EXPORTING
#define DECLSPEC_API __declspec(dllexport)
#else
#define DECLSPEC_API __declspec(dllimport)
#endif

#ifndef FACERECDLIB_H
#define FACERECDLIB_H

//#pragma unmanaged

//#include "basictypes.h"

#pragma managed

namespace FaceRecDLib
{
	//DECLSPEC_API std::vector<std::string> Recognition(cv::Mat image_opencv);
	DECLSPEC_API std::vector<std::pair<std::pair<std::string, std::string>, double>> Recognition(cv::Mat image_opencv);
}
/*
class DECLSPEC_API FaceRecDLib {
public:
	FaceRecDLib() 
    {
        deserialize("shape_predictor_68_face_landmarks.dat") >> sp;
        deserialize("dlib_face_recognition_resnet_model_v1.dat") >> net;
        //Logger::LOGI("models were loaded");
    }
	std::string face_descriptor_calc(cv::Mat image_opencv);
	double descriptions_compare(std::string descriptors_from_foto, std::string descriptors_from_base);
	
	
private:
    shape_predictor sp;
    anet_type net;
	std::vector<matrix<float, 0, 1>> string_to_float(std::string s);
	std::string float_to_string(std::vector<matrix<float, 0, 1>> matr);
	
	frontal_face_detector detector = get_frontal_face_detector();
};
*/
#endif // FACERECDLIB_H