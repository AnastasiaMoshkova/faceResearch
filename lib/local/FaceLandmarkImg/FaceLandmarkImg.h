#pragma once


#ifdef EXPORTING
#define DECLSPEC_API __declspec(dllexport)
#else
#define DECLSPEC_API __declspec(dllimport)
#endif

#ifndef __FACELANDMARKIMG_h_
#define __FACELANDMARKIMG_h_

#pragma managed

//#pragma unmanaged
typedef std::vector<std::string> ListString;
//typedef cv::Mat ImageMat;

//using namespace std;
namespace  FaceLandmarkImg
{

		/*vector<string> get_arguments(int argc, char **argv);
		void convert_to_grayscale(const cv::Mat& in, cv::Mat& out);
		void create_directory_from_file(string output_path);
		void write_out_pose_landmarks(const string& outfeatures, const cv::Mat_<double>& shape3D, const cv::Vec6d& pose, const cv::Point3f& gaze0, const cv::Point3f& gaze1);
		void write_out_landmarks(const string& outfeatures, const LandmarkDetector::CLNF& clnf_model, const cv::Vec6d& pose, const cv::Point3f& gaze0, const cv::Point3f& gaze1, std::vector<std::pair<std::string, double>> au_intensities, std::vector<std::pair<std::string, double>> au_occurences, std::vector<string> &vec);
		void create_display_image(const cv::Mat& orig, cv::Mat& display_image, LandmarkDetector::CLNF& clnf_model);
		*/
		DECLSPEC_API ListString Emotion(ListString arguments, cv::Mat read_image);
		//DECLSPEC_API vector<string> Emotion(vector<string> arguments, cv::Mat read_image);
		//DECLSPEC_API vector<string> PoseHeadFrame(vector<string> arguments);
		DECLSPEC_API ListString PoseHeadFrame(ListString arguments);
		DECLSPEC_API ListString PoseHeadFrame4(ListString arguments, cv::Mat read_image);
		//DECLSPEC_API LandmarkDetector::CLNF PoseHeadFrame2(vector<string> arguments);
		//DECLSPEC_API vector<string> PoseHeadFrame3(vector<string> arguments, LandmarkDetector::CLNF clnf_model, cv::Mat read_image);
		//DECLSPEC_API vector<string> PoseHeadFrame4(vector<string> arguments, cv::Mat read_image);
		//DECLSPEC_API ListString PoseHeadFrame4(ListString arguments, cv::Mat read_image);
}

//class DECLSPEC_API FaceLandmarkImg

/*
class FaceLandmarkImg
//class FaceLandmarkImg
{
public:
	FaceLandmarkImg()
	{

	}
	vector<string> Emotion(vector<string> arguments);
private:
	vector<string> get_arguments(int argc, char **argv);
	void convert_to_grayscale(const cv::Mat& in, cv::Mat& out);
	void create_directory_from_file(string output_path);
	void write_out_pose_landmarks(const string& outfeatures, const cv::Mat_<double>& shape3D, const cv::Vec6d& pose, const cv::Point3f& gaze0, const cv::Point3f& gaze1);
	void write_out_landmarks(const string& outfeatures, const LandmarkDetector::CLNF& clnf_model, const cv::Vec6d& pose, const cv::Point3f& gaze0, const cv::Point3f& gaze1, std::vector<std::pair<std::string, double>> au_intensities, std::vector<std::pair<std::string, double>> au_occurences, std::vector<string> &vec);
	void create_display_image(const cv::Mat& orig, cv::Mat& display_image, LandmarkDetector::CLNF& clnf_model);
	

};
*/
#endif
