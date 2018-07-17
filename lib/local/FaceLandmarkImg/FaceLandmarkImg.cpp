///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016, Carnegie Mellon University and University of Cambridge,
// all rights reserved.
//
// THIS SOFTWARE IS PROVIDED “AS IS” FOR ACADEMIC USE ONLY AND ANY EXPRESS
// OR IMPLIED WARRANTIES WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS
// BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY.
// OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Notwithstanding the license granted herein, Licensee acknowledges that certain components
// of the Software may be covered by so-called “open source” software licenses (“Open Source
// Components”), which means any software licenses approved as open source licenses by the
// Open Source Initiative or any substantially similar licenses, including without limitation any
// license that, as a condition of distribution of the software licensed under such license,
// requires that the distributor make the software available in source code format. Licensor shall
// provide a list of Open Source Components for a particular version of the Software upon
// Licensee’s request. Licensee will comply with the applicable terms of such licenses and to
// the extent required by the licenses covering Open Source Components, the terms of such
// licenses will apply in lieu of the terms of this Agreement. To the extent the terms of the
// licenses applicable to Open Source Components prohibit any of the restrictions in this
// License Agreement with respect to such Open Source Component, such restrictions will not
// apply to such Open Source Component. To the extent the terms of the licenses applicable to
// Open Source Components require Licensor to make an offer to provide source code or
// related information in connection with the Software, such offer is hereby made. Any request
// for source code or related information should be directed to cl-face-tracker-distribution@lists.cam.ac.uk
// Licensee acknowledges receipt of notices for the Open Source Components for the initial
// delivery of the Software.

//     * Any publications arising from the use of this software, including but
//       not limited to academic journal and conference publications, technical
//       reports and manuals, must cite at least one of the following works:
//
//       OpenFace: an open source facial behavior analysis toolkit
//       Tadas Baltrušaitis, Peter Robinson, and Louis-Philippe Morency
//       in IEEE Winter Conference on Applications of Computer Vision, 2016  
//
//       Rendering of Eyes for Eye-Shape Registration and Gaze Estimation
//       Erroll Wood, Tadas Baltrušaitis, Xucong Zhang, Yusuke Sugano, Peter Robinson, and Andreas Bulling 
//       in IEEE International. Conference on Computer Vision (ICCV),  2015 
//
//       Cross-dataset learning and person-speci?c normalisation for automatic Action Unit detection
//       Tadas Baltrušaitis, Marwa Mahmoud, and Peter Robinson 
//       in Facial Expression Recognition and Analysis Challenge, 
//       IEEE International Conference on Automatic Face and Gesture Recognition, 2015 
//
//       Constrained Local Neural Fields for robust facial landmark detection in the wild.
//       Tadas Baltrušaitis, Peter Robinson, and Louis-Philippe Morency. 
//       in IEEE Int. Conference on Computer Vision Workshops, 300 Faces in-the-Wild Challenge, 2013.    
//
///////////////////////////////////////////////////////////////////////////////
// FaceLandmarkImg.cpp : Defines the entry point for the console application for detecting landmarks in images.

//dlib

#define _CRT_SECURE_NO_WARNINGS

//#define DLIB_USE_BLAS
//#define DLIB_USE_LAPACK
#define DLIB_JPEG_SUPPORT
#define DLIB_PNG_SUPPORT


//#define _WIN32_WINNT
//#define WINVER 0x0A00  
//#define _WIN32_WINNT 0x0A00
#define _WIN32_WINNT 0x0502



#include <fstream>
#include <string>
#include <iostream>
#include <future>
#include <thread>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <dlib/assert.h>
#include <dlib/image_processing.h>
//#include <dlib/dnn.h>
#include <dlib/clustering.h>
#include <dlib/string.h>
#include <dlib/image_io.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/opencv.h>
#include <dlib/image_transforms.h>
#include <dlib/opencv/cv_image.h>
#include <dlib/matrix/lapack/gesvd.h>
#include <dlib/matrix/lapack/gesdd.h>

// ñêîðåå âñåãî ýòî íå íóæíî
#include <windows.h>
#include <stdio.h>

//#define EXPORTING
#include "LandmarkCoreIncludes.h"

// System includes
#include <fstream>

#include<vector>
#include <iostream>
#include <algorithm>    
#include <Windows.h>
#include <iterator>
#include <numeric>

#include <fstream>
#include <string>
#include <iostream>
#include <future>
#include <thread>
#include <vector>

// OpenCV includes
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

// Boost includes
#include <filesystem.hpp>
#include <filesystem/fstream.hpp>

#include <dlib/image_processing/frontal_face_detector.h>

#include <tbb/tbb.h>
//#include <tbb.h>




#include <FaceAnalyser.h>
#include <GazeEstimation.h>
#include "FaceLandmarkImg.h"
//#include "basictypes.h"
/*
#include "LandmarkCoreIncludes.h"

// System includes
#include <fstream>

#include<vector>
#include <iostream>
#include <algorithm>    
#include <Windows.h>
#include <iterator>
#include <numeric>

// OpenCV includes
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

// Boost includes
#include <filesystem.hpp>
#include <filesystem/fstream.hpp>

#include <dlib/image_processing/frontal_face_detector.h>

#include <tbb/tbb.h>

#include <FaceAnalyser.h>
#include <GazeEstimation.h>


using namespace std;
*/
using namespace std;
//using namespace dlib;
/*

std::string face_descriptor_calc(cv::Mat image_opencv)
{

	dlib::shape_predictor sp;
	anet_type net;
	dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();
	deserialize("shape_predictor_68_face_landmarks.dat") >> sp;
	deserialize("dlib_face_recognition_resnet_model_v1.dat") >> net;

	

	dlib::matrix<dlib::rgb_pixel> img(dlib::mat(dlib::cv_image<dlib::rgb_pixel>(image_opencv)));

	std::vector<matrix<rgb_pixel>> faces;

	for (auto face : detector(img))
	{
	
		auto shape = sp(img, face);
		
		matrix<rgb_pixel> face_chip;
		
		extract_image_chip(img, get_face_chip_details(shape, 150, 0.25), face_chip);
	
		faces.push_back(std::move(face_chip));
		
	}

	std::vector<matrix<float, 0, 1>> face_descriptors = net(faces);
	

	//string for descriptors
	std::string descriptors_string;

	std::string str;

/*
	for (int i = 0; i < face_descriptors[0].size(); i++)
	{
		str = toString(face_descriptors[0](i));
		descriptors_string += str + ';';
		str.clear();
	}
	
	std::string descriptors_string;
	return descriptors_string;
}
*/

//namespace FaceLandmarkImg
//{


	std::vector<string> get_arguments(int argc, char **argv)
	{

		std::vector<string> arguments;

		for (int i = 0; i < argc; ++i)
		{
			arguments.push_back(string(argv[i]));
		}
		return arguments;
	}

	void convert_to_grayscale(const cv::Mat& in, cv::Mat& out)
	{
		if (in.channels() == 3)
		{
			// Make sure it's in a correct format
			if (in.depth() != CV_8U)
			{
				if (in.depth() == CV_16U)
				{
					cv::Mat tmp = in / 256;
					tmp.convertTo(tmp, CV_8U);
					cv::cvtColor(tmp, out, CV_BGR2GRAY);
				}
			}
			else
			{
				cv::cvtColor(in, out, CV_BGR2GRAY);
			}
		}
		else if (in.channels() == 4)
		{
			cv::cvtColor(in, out, CV_BGRA2GRAY);
		}
		else
		{
			if (in.depth() == CV_16U)
			{
				cv::Mat tmp = in / 256;
				out = tmp.clone();
			}
			else if (in.depth() != CV_8U)
			{
				in.convertTo(out, CV_8U);
			}
			else
			{
				out = in.clone();
			}
		}
	}

	// Useful utility for creating directories for storing the output files
	void create_directory_from_file(string output_path)
	{

		// Creating the right directory structure

		// First get rid of the file
		auto p = boost::filesystem::path(boost::filesystem::path(output_path).parent_path());
		//auto p = boost::filesystem::path(boost::filesystem::path(output_path));

		std::cout << "number2" << p.string() << std::endl;

		if (!p.empty() && !boost::filesystem::exists(p))
		{
			bool success = boost::filesystem::create_directories(p);
			if (!success)
			{
				cout << "Failed to create a directory... " << p.string() << endl;
			}
		}
	}

	// This will only be accurate when camera parameters are accurate, useful for work on 3D data
	void write_out_pose_landmarks(const string& outfeatures, const cv::Mat_<double>& shape3D, const cv::Vec6d& pose, const cv::Point3f& gaze0, const cv::Point3f& gaze1)
	{
		create_directory_from_file(outfeatures);
		std::ofstream featuresFile;
		featuresFile.open(outfeatures);

		if (featuresFile.is_open())
		{
			int n = shape3D.cols;
			featuresFile << "version: 1" << endl;
			featuresFile << "npoints: " << n << endl;
			featuresFile << "{" << endl;

			for (int i = 0; i < n; ++i)
			{
				// Use matlab format, so + 1
				featuresFile << shape3D.at<double>(i) << " " << shape3D.at<double>(i + n) << " " << shape3D.at<double>(i + 2 * n) << endl;
			}
			featuresFile << "}" << endl;

			// Do the pose and eye gaze if present as well
			featuresFile << "pose: eul_x, eul_y, eul_z: " << endl;
			featuresFile << "{" << endl;
			featuresFile << pose[3] << " " << pose[4] << " " << pose[5] << endl;
			featuresFile << "}" << endl;

			// Do the pose and eye gaze if present as well
			featuresFile << "gaze: dir_x_1, dir_y_1, dir_z_1, dir_x_2, dir_y_2, dir_z_2: " << endl;
			featuresFile << "{" << endl;
			featuresFile << gaze0.x << " " << gaze0.y << " " << gaze0.z << " " << gaze1.x << " " << gaze1.y << " " << gaze1.z << endl;
			featuresFile << "}" << endl;
			featuresFile.close();
		}
	}

	void write_out_landmarks(const string& outfeatures, const LandmarkDetector::CLNF& clnf_model, const cv::Vec6d& pose, const cv::Point3f& gaze0, const cv::Point3f& gaze1, std::vector<std::pair<std::string, double>> au_intensities, std::vector<std::pair<std::string, double>> au_occurences, std::vector<string> &vec)
	{
		create_directory_from_file(outfeatures);
		std::ofstream featuresFile;
		featuresFile.open(outfeatures);

		std::vector<string> vect;
		string an, an2, bb, cc;
		string zz1, zz2, p1, p2, p3;
		std::vector<double> ActionUnit;

		if (featuresFile.is_open())
		{
			int n = clnf_model.patch_experts.visibilities[0][0].rows;
			featuresFile << "version: 1" << endl;
			featuresFile << "npoints: " << n << endl;
			featuresFile << "{" << endl;

			for (int i = 0; i < n; ++i)
			{
				// Use matlab format, so + 1
				featuresFile << clnf_model.detected_landmarks.at<double>(i) + 1 << " " << clnf_model.detected_landmarks.at<double>(i + n) + 1 << endl;
			}
			featuresFile << "}" << endl;

			// Do the pose and eye gaze if present as well
			featuresFile << "pose: eul_x, eul_y, eul_z: " << endl;
			featuresFile << "{" << endl;
			featuresFile << pose[3] << " " << pose[4] << " " << pose[5] << endl;
			featuresFile << "}" << endl;

			//p1= std::to_string(pose[3]);
			//p2 = std::to_string(pose[4]);
			//p3 = std::to_string(pose[5]);

			// Do the pose and eye gaze if present as well
			featuresFile << "gaze: dir_x_1, dir_y_1, dir_z_1, dir_x_2, dir_y_2, dir_z_2: " << endl;
			featuresFile << "{" << endl;
			featuresFile << gaze0.x << " " << gaze0.y << " " << gaze0.z << " " << gaze1.x << " " << gaze1.y << " " << gaze1.z << endl;
			featuresFile << "}" << endl;

			// Do the au intensities
			featuresFile << "au intensities: " << au_intensities.size() << endl;
			featuresFile << "{" << endl;

			for (int i = 0; i < au_intensities.size(); ++i)
			{
				// Use matlab format, so + 1
				featuresFile << au_intensities[i].first << " " << au_intensities[i].second << endl;
				ActionUnit.push_back(au_intensities[i].second);
			}

			featuresFile << "}" << endl;

			// Do the au occurences
			featuresFile << "au occurences: " << au_occurences.size() << endl;
			featuresFile << "{" << endl;

			for (int i = 0; i < au_occurences.size(); ++i)
			{
				// Use matlab format, so + 1
				featuresFile << au_occurences[i].first << " " << au_occurences[i].second << endl;
				ActionUnit.push_back(au_occurences[i].second);
			}

			featuresFile << "}" << endl;


			featuresFile.close();
		}
		/*
		int n = clnf_model.patch_experts.visibilities[0][0].rows;

		for (int i = 0; i < n; ++i)
		{
			// Use matlab format, so + 1
			std::cout<< clnf_model.detected_landmarks.at<double>(i) + 1 << " " << clnf_model.detected_landmarks.at<double>(i + n) + 1 << std::endl;
		}
		*/
		double eyes = clnf_model.detected_landmarks.at<double>(42) - clnf_model.detected_landmarks.at<double>(39);
		std::cout << "eyes " << eyes << std::endl;

		std::vector<double> e1, e2, e3, e4, e5, e6;

		double AU01_c = ActionUnit[0], AU02_c = ActionUnit[1], AU04_c = ActionUnit[2], AU05_c = ActionUnit[3], AU06_c = ActionUnit[4], AU07_c = ActionUnit[5], AU09_c = ActionUnit[6],
			AU10_c = ActionUnit[7], AU12_c = ActionUnit[8], AU14_c = ActionUnit[9], AU15_c = ActionUnit[10], AU17_c = ActionUnit[11], AU20_c = ActionUnit[12], AU23_c = ActionUnit[13],
			AU25_c = ActionUnit[14], AU26_c = ActionUnit[15], AU45_c = ActionUnit[16];
		double AU01_r = ActionUnit[17], AU02_r = ActionUnit[18], AU04_r = ActionUnit[19], AU05_r = ActionUnit[20], AU06_r = ActionUnit[21], AU07_r = ActionUnit[22], AU09_r = ActionUnit[23],
			AU10_r = ActionUnit[24], AU12_r = ActionUnit[25], AU14_r = ActionUnit[26], AU15_r = ActionUnit[27], AU17_r = ActionUnit[28], AU20_r = ActionUnit[29], AU23_r = ActionUnit[30],
			AU25_r = ActionUnit[31], AU26_r = ActionUnit[32], AU28_r = ActionUnit[33], AU45_r = ActionUnit[34];


		std::cout << AU01_c << std::endl;
		std::cout << AU02_c << std::endl;
		std::cout << AU05_c << std::endl;
		std::cout << AU06_c << std::endl;
		std::cout << AU07_c << std::endl;
		std::cout << AU09_c << std::endl;
		std::cout << AU10_c << std::endl;
		std::cout << AU12_c << std::endl;
		std::cout << AU14_c << std::endl;
		std::cout << AU15_c << std::endl;
		std::cout << AU20_c << std::endl;
		std::cout << AU23_c << std::endl;
		std::cout << AU25_c << std::endl;
		std::cout << AU26_c << std::endl;
		std::cout << AU45_c << std::endl;


		std::cout << AU01_r << std::endl;
		std::cout << AU02_r << std::endl;
		std::cout << AU05_r << std::endl;
		std::cout << AU06_r << std::endl;
		std::cout << AU07_r << std::endl;
		std::cout << AU09_r << std::endl;
		std::cout << AU10_r << std::endl;
		std::cout << AU12_r << std::endl;
		std::cout << AU14_r << std::endl;
		std::cout << AU15_r << std::endl;
		std::cout << AU20_r << std::endl;
		std::cout << AU23_r << std::endl;
		std::cout << AU25_r << std::endl;
		std::cout << AU26_r << std::endl;
		std::cout << AU28_r << std::endl;
		std::cout << AU45_r << std::endl;

		//óäèâëåíèå
		e1.push_back((AU01_c*AU01_r + AU02_c*AU02_r + AU05_c*AU05_r + AU26_c*AU26_r) / 4);

		e1.push_back((AU01_c*AU01_r + AU02_c*AU02_r + AU05_c*AU05_r) / 3);
		e1.push_back((AU01_c*AU01_r + AU02_c*AU02_r + AU26_c*AU26_r) / 3);

		e1.push_back((AU05_c*AU05_r + AU26_c*AU26_r) / 2);



		//%ñòðàõ

		e2.push_back((AU01_c*AU01_r + AU02_c*AU02_r + AU04_c*AU04_r + AU05_c*AU05_r + AU25_c*AU25_r + AU26_c*AU26_r) / 6);

		e2.push_back((AU01_c*AU01_r + AU02_c*AU02_r + AU04_c*AU04_r + AU05_c*AU05_r) / 4);
		e2.push_back((AU01_c*AU01_r + AU02_c*AU02_r + AU05_c*AU05_r + AU25_c*AU25_r) / 4);
		e2.push_back((AU01_c*AU01_r + AU02_c*AU02_r + AU05_c*AU05_r + AU25_c*AU25_r + AU26_c*AU26_r) / 5);

		e2.push_back((AU01_c*AU01_r + AU02_c*AU02_r + AU05_c*AU05_r + AU26_c*AU26_r) / 4);

		e2.push_back((AU01_c*AU01_r + AU02_c*AU02_r + AU05_c*AU05_r) / 3);
		e2.push_back((AU05_c*AU05_r + AU20_c*AU20_r + AU25_c*AU25_r) / 3);
		e2.push_back((AU05_c*AU05_r + AU20_c*AU20_r + AU25_c*AU25_r + AU26_c*AU26_r) / 4);

		e2.push_back((AU05_c*AU05_r + AU20_c*AU20_r + AU26_c*AU26_r) / 3);

		e2.push_back((AU05_c*AU05_r + AU20_c*AU20_r) / 2);
		//%ðàäîñòü
		e3.push_back((AU06_c*AU06_r + AU12_c*AU12_r) / 2);
		e3.push_back((AU12_c*AU12_r));
		//%å÷àëü

		e4.push_back((AU01_c*AU01_r + AU04_c*AU04_r + AU15_c*AU15_r) / 3);
		e4.push_back((AU06_c*AU06_r + AU15_c*AU15_r) / 2);

		e4.push_back((AU01_c*AU01_r + AU04_c*AU04_r + AU15_c*AU15_r + AU17_c*AU17_r) / 4);

		//%îòâðàùåíèå
		e5.push_back((AU09_c*AU09_r));

		e5.push_back((AU09_c*AU09_r + AU17_c*AU17_r) / 2);
		e5.push_back((AU10_c*AU10_r));

		e5.push_back((AU10_c*AU10_r + AU17_c*AU17_r) / 2);
		//%ãíåâ

		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU07_c*AU07_r + AU10_c*AU10_r + AU23_c*AU23_r + AU25_c*AU25_r) / 6);
		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU07_c*AU07_r + AU10_c*AU10_r + AU23_c*AU23_r + AU26_c*AU26_r) / 6);
		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU07_c*AU07_r + AU23_c*AU23_r + AU25_c*AU25_r) / 5);
		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU07_c*AU07_r + AU23_c*AU23_r + AU26_c*AU26_r) / 5);
		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU07_c*AU07_r + AU17_c*AU17_r + AU23_c*AU23_r) / 5);

		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU07_c*AU07_r + AU23_c*AU23_r) / 4);



		e6.push_back((AU05_c*AU05_r + AU07_c*AU07_r + AU10_c*AU10_r + AU23_c*AU23_r + AU25_c*AU25_r) / 5);
		e6.push_back((AU05_c*AU05_r + AU07_c*AU07_r + AU10_c*AU10_r + AU23_c*AU23_r + AU26_c*AU26_r) / 5);
		e6.push_back((AU05_c*AU05_r + AU07_c*AU07_r + AU23_c*AU23_r + AU25_c*AU25_r) / 4);
		e6.push_back((AU05_c*AU05_r + AU07_c*AU07_r + AU23_c*AU23_r + AU26_c*AU26_r) / 4);
		e6.push_back((AU05_c*AU05_r + AU07_c*AU07_r + AU17_c*AU17_r + AU23_c*AU23_r) / 4);

		e6.push_back((AU05_c*AU05_r + AU07_c*AU07_r + AU23_c*AU23_r) / 3);



		e6.push_back((AU04_c*AU04_r + AU07_c*AU07_r + AU10_c*AU10_r + AU23_c*AU23_r + AU25_c*AU25_r) / 5);
		e6.push_back((AU04_c*AU04_r + AU07_c*AU07_r + AU10_c*AU10_r + AU23_c*AU23_r + AU26_c*AU26_r) / 5);
		e6.push_back((AU04_c*AU04_r + AU07_c*AU07_r + AU23_c*AU23_r + AU25_c*AU25_r) / 4);
		e6.push_back((AU04_c*AU04_r + AU07_c*AU07_r + AU23_c*AU23_r + AU26_c*AU26_r) / 4);
		e6.push_back((AU04_c*AU04_r + AU07_c*AU07_r + AU17_c*AU17_r + AU23_c*AU23_r) / 4);

		e6.push_back((AU04_c*AU04_r + AU07_c*AU07_r + AU23_c*AU23_r) / 3);

		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU10_c*AU10_r + AU23_c*AU23_r + AU25_c*AU25_r) / 5);
		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU10_c*AU10_r + AU23_c*AU23_r + AU26_c*AU26_r) / 5);
		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU23_c*AU23_r + AU25_c*AU25_r) / 4);
		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU23_c*AU23_r + AU26_c*AU26_r) / 4);
		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU17_c*AU17_r + AU23_c*AU23_r) / 4);

		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU23_c*AU23_r) / 3);

		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU07_c*AU07_r + AU23_c*AU23_r + AU25_c*AU25_r) / 5);
		e6.push_back((AU04_c*AU04_r + AU05_c*AU05_r + AU07_c*AU07_r + AU23_c*AU23_r + AU26_c*AU26_r) / 5);




		std::vector<double>::iterator result1;
		result1 = std::max_element(e1.begin(), e1.end());
		int r1 = std::distance(e1.begin(), result1);

		std::vector<double>::iterator result2;
		result2 = std::max_element(e2.begin(), e2.end());
		int r2 = std::distance(e2.begin(), result2);

		std::vector<double>::iterator result3;
		result3 = std::max_element(e3.begin(), e3.end());
		int r3 = std::distance(e3.begin(), result3);

		std::vector<double>::iterator result4;
		result4 = std::max_element(e4.begin(), e4.end());
		int r4 = std::distance(e4.begin(), result4);

		std::vector<double>::iterator result5;
		result5 = std::max_element(e5.begin(), e5.end());
		int r5 = std::distance(e5.begin(), result5);

		std::vector<double>::iterator result6;
		result6 = std::max_element(e6.begin(), e6.end());
		int r6 = std::distance(e6.begin(), result6);

		std::vector<double> em;
		em.push_back(e1[r1]);
		em.push_back(e2[r2]);
		em.push_back(e3[r3]);
		em.push_back(e4[r4]);
		em.push_back(e5[r5]);
		em.push_back(e6[r6]);

		// íîâîå
		double summa = e1[r1] + e2[r2]+ e3[r3]+ e4[r4]+ e5[r5]+ e6[r6];

		int emotion1 = round((e1[r1] / summa) * 100);
		int emotion2 = round((e2[r2] / summa) * 100);
		int emotion3 = round((e3[r3] / summa) * 100);
		int emotion4 = round((e4[r4] / summa) * 100);
		int emotion5 = round((e5[r5] / summa) * 100);
		int emotion6 = round((e6[r6] / summa) * 100);


		string emotion1_str = to_string(emotion1) + "%";
		string emotion2_str = to_string(emotion2) + "%";
		string emotion3_str = to_string(emotion3) + "%";
		string emotion4_str = to_string(emotion4) + "%";
		string emotion5_str = to_string(emotion5) + "%";
		string emotion6_str = to_string(emotion6) + "%";


		for (int i = 0; i < em.size(); i++)
		{
			//std::cout << em[i] << std::endl;
			printf("[%d]: %4.2lf\t", i, em[i]);
			
		}
		std::cout << "\n" << std::endl;
		

		std::vector<double>::iterator result;
		result = std::max_element(em.begin(), em.end());
		int r = std::distance(em.begin(), result);

		double a = em[r];


		//double sum_of_elems = std::accumulate(em.begin(), em.end(), 0.0);
		double sum_of_elems = std::accumulate(em.begin(), em.end(), 0);

		string strr, strr2;
		//if (sum_of_elems < 1)
		if (sum_of_elems == 0)
		{
			//*output_file << " " << "neutral 100%";

			strr = "neutral";

		}


		else
		{

			if (r == 0)
			{
				//*output_file << " " << "surprise";
				strr = "surprise";
			}
			if (r == 1)
			{
				//*output_file << " " << "fear";
				strr = "fear";
			}
			if (r == 2)
			{
				//*output_file << " " << "happiness";
				strr = "happiness";
			}
			if (r == 3)
			{
				//*output_file << " " << "sad";
				strr = "sad";
			}
			if (r == 4)
			{
				//*output_file << " " << "disgust";
				strr = "disgust";
			}
			if (r == 5)
			{
				//*output_file << " " << "anger";
				strr = "anger";
			}

			em[r] = 0;
			std::vector<double>::iterator result7;
			result7 = std::max_element(em.begin(), em.end());
			int r7 = std::distance(em.begin(), result7);
			double a2 = em[r7];
			if (r7 == 0)
			{
				//*output_file << " " << "surprise";
				strr2 = "surprise";
			}
			if (r7 == 1)
			{
				//*output_file << " " << "fear";
				strr2 = "fear";
			}
			if (r7 == 2)
			{
				//*output_file << " " << "happiness";
				strr2 = "happiness";
			}
			if (r7 == 3)
			{
				//*output_file << " " << "sad";
				strr2 = "sad";
			}
			if (r7 == 4)
			{
				//*output_file << " " << "disgust";
				strr2 = "disgust";
			}
			if (r7 == 5)
			{
				//*output_file << " " << "anger";
				strr2 = "anger";
			}

			double sum = a + a2;
			double z1 = (a / sum) * 100;
			double z2 = (a2 / sum) * 100;
			//*output_file << " " << z1 << "%";
			//*output_file << " " << z2 << "%";

		
	
			zz1 = to_string(z1) + "%";

			zz2 = to_string(z2) + "%";


		}
		ActionUnit.clear();

		//*output_file << endl;
		p1= to_string(round(pose[3] * 180 / 3.14));
		p2= to_string(round(pose[4] * 180 / 3.14));
		p3 = to_string(round(pose[5] * 180 / 3.14));

		string eyes_distanse = to_string(round(eyes));


		//p1 = to_string(pose[3]);
		//p2 = to_string(pose[4]);
		//p3 = to_string(pose[5]);

		vect.push_back(strr);
		vect.push_back(strr2);
		vect.push_back(zz1);
		vect.push_back(zz2);
		vect.push_back(emotion1_str);
		vect.push_back(emotion2_str);
		vect.push_back(emotion3_str);
		vect.push_back(emotion4_str);
		vect.push_back(emotion5_str);
		vect.push_back(emotion6_str);
		vect.push_back(p1);
		vect.push_back(p2);
		vect.push_back(p3);
		vect.push_back(eyes_distanse);

		int n = clnf_model.patch_experts.visibilities[0][0].rows;
	
		for (int i = 0; i < n; ++i)
			{
				// Use matlab format, so + 1
			int c_x = round(clnf_model.detected_landmarks.at<double>(i));
			int c_y= round(clnf_model.detected_landmarks.at<double>(i + n));
			std::string coordinaye_x = std::to_string(c_x);
			std::string coordinaye_y = std::to_string(c_y);
			vect.push_back(coordinaye_x);
			vect.push_back(coordinaye_y);
			}
		cout <<"------------------------"<< strr << strr2 << zz1 << zz2 << endl;

		//vect.push_back(p1);
		//vect.push_back(p2);
		//vect.push_back(p3);


		return vec.swap(vect);
	}

	void create_display_image(const cv::Mat& orig, cv::Mat& display_image, LandmarkDetector::CLNF& clnf_model)
	{

		// Draw head pose if present and draw eye gaze as well

		// preparing the visualisation image
		display_image = orig.clone();

		// Creating a display image			
		cv::Mat xs = clnf_model.detected_landmarks(cv::Rect(0, 0, 1, clnf_model.detected_landmarks.rows / 2));
		cv::Mat ys = clnf_model.detected_landmarks(cv::Rect(0, clnf_model.detected_landmarks.rows / 2, 1, clnf_model.detected_landmarks.rows / 2));
		double min_x, max_x, min_y, max_y;

		cv::minMaxLoc(xs, &min_x, &max_x);
		cv::minMaxLoc(ys, &min_y, &max_y);

		double width = max_x - min_x;
		double height = max_y - min_y;

		int minCropX = max((int)(min_x - width / 3.0), 0);
		int minCropY = max((int)(min_y - height / 3.0), 0);

		int widthCrop = min((int)(width*5.0 / 3.0), display_image.cols - minCropX - 1);
		int heightCrop = min((int)(height*5.0 / 3.0), display_image.rows - minCropY - 1);

		double scaling = 350.0 / widthCrop;

		// first crop the image
		display_image = display_image(cv::Rect((int)(minCropX), (int)(minCropY), (int)(widthCrop), (int)(heightCrop)));

		// now scale it
		cv::resize(display_image.clone(), display_image, cv::Size(), scaling, scaling);

		// Make the adjustments to points
		xs = (xs - minCropX)*scaling;
		ys = (ys - minCropY)*scaling;

		cv::Mat shape = clnf_model.detected_landmarks.clone();

		xs.copyTo(shape(cv::Rect(0, 0, 1, clnf_model.detected_landmarks.rows / 2)));
		ys.copyTo(shape(cv::Rect(0, clnf_model.detected_landmarks.rows / 2, 1, clnf_model.detected_landmarks.rows / 2)));

		// Do the shifting for the hierarchical models as well
		for (size_t part = 0; part < clnf_model.hierarchical_models.size(); ++part)
		{
			cv::Mat xs = clnf_model.hierarchical_models[part].detected_landmarks(cv::Rect(0, 0, 1, clnf_model.hierarchical_models[part].detected_landmarks.rows / 2));
			cv::Mat ys = clnf_model.hierarchical_models[part].detected_landmarks(cv::Rect(0, clnf_model.hierarchical_models[part].detected_landmarks.rows / 2, 1, clnf_model.hierarchical_models[part].detected_landmarks.rows / 2));

			xs = (xs - minCropX)*scaling;
			ys = (ys - minCropY)*scaling;

			cv::Mat shape = clnf_model.hierarchical_models[part].detected_landmarks.clone();

			xs.copyTo(shape(cv::Rect(0, 0, 1, clnf_model.hierarchical_models[part].detected_landmarks.rows / 2)));
			ys.copyTo(shape(cv::Rect(0, clnf_model.hierarchical_models[part].detected_landmarks.rows / 2, 1, clnf_model.hierarchical_models[part].detected_landmarks.rows / 2)));

		}

		LandmarkDetector::Draw(display_image, clnf_model);

	}

	//int main (int argc, char **argv)
	std::vector<string> FaceLandmarkImg::Emotion(std::vector<string> arguments, cv::Mat read_image)
	{
		cv::Mat tt(10, 10, CV_8U, cv::Scalar(150));
		imshow("colour", tt);
		cv::waitKey(1);

		auto start2 = std::chrono::high_resolution_clock::now();
		//std::cout << arguments[0] << std::endl;
		//std::cout << arguments[1] << std::endl;
		//std::cout << arguments[2] << std::endl;

		int face_numbers = 0;

		std::vector<string> vector_AU;
		string st1, st2, st3, st4;
		//Convert arguments to more convenient vector form
		//vector<string> arguments = get_arguments(argc, argv);

		// Some initial parameters that can be overriden from command line
		std::vector<string> files, depth_files, output_images, output_landmark_locations, output_pose_locations;

		// Bounding boxes for a face in each image (optional)
		std::vector<cv::Rect_<double> > bounding_boxes;

		//std::cout <<" bounding_boxes "<< bounding_boxes.size() << std::endl;

		LandmarkDetector::get_image_input_output_params(files, depth_files, output_landmark_locations, output_pose_locations, output_images, bounding_boxes, arguments);
		LandmarkDetector::FaceModelParameters det_parameters(arguments);

		//std::cout << " bounding_boxes2 " << bounding_boxes.size() << std::endl;
		// No need to validate detections, as we're not doing tracking
		det_parameters.validate_detections = false;

		// Grab camera parameters if provided (only used for pose and eye gaze and are quite important for accurate estimates)
		float fx = 0, fy = 0, cx = 0, cy = 0;
		int device = -1;
		LandmarkDetector::get_camera_params(device, fx, fy, cx, cy, arguments);

		// If cx (optical axis centre) is undefined will use the image size/2 as an estimate
		bool cx_undefined = false;
		bool fx_undefined = false;
		if (cx == 0 || cy == 0)
		{
			cx_undefined = true;
		}
		if (fx == 0 || fy == 0)
		{
			fx_undefined = true;
		}

		// The modules that are being used for tracking
		cout << "Loading the model" << endl;
		static LandmarkDetector::CLNF clnf_model(det_parameters.model_location);

	
		cout << "Model loaded" << endl;

	

		static cv::CascadeClassifier classifier(det_parameters.face_detector_location);
		static dlib::frontal_face_detector face_detector_hog = dlib::get_frontal_face_detector();

		// Loading the AU prediction models
		string au_loc = "AU_predictors/AU_all_static.txt";

		//cout << au_loc << endl;


		if (!boost::filesystem::exists(boost::filesystem::path(au_loc)))
		{
			boost::filesystem::path loc = boost::filesystem::path(arguments[0]).parent_path() / au_loc;
			//boost::filesystem::path loc = boost::filesystem::path(arguments[0]) / au_loc;
			string au_loc2 = loc.string();
			cout << "number3" << au_loc2 << endl;

			if (boost::filesystem::exists(loc))
			{
				au_loc = loc.string();
				cout << "number4" << au_loc << endl;

			//	cout << au_loc << endl;
				
			}
			else
			{
				cout << "Can't find AU prediction files, exiting" << endl;
				//return 0;
			}
		}

		

		// Used for image masking for AUs
		string tri_loc;
		if (boost::filesystem::exists(boost::filesystem::path("model/tris_68_full.txt")))
		{
			std::ifstream triangulation_file("model/tris_68_full.txt");
			tri_loc = "model/tris_68_full.txt";
		}
		else
		{
			boost::filesystem::path loc = boost::filesystem::path(arguments[0]).parent_path() / "model/tris_68_full.txt";
			//boost::filesystem::path loc = boost::filesystem::path(arguments[0]) / "model/tris_68_full.txt";
			tri_loc = loc.string();
			cout << "number5" << tri_loc << endl;

			if (!exists(loc))
			{
				cout << "Can't find triangulation files, exiting" << endl;
				//return 0;
			}
		}

		cout << au_loc << " " << tri_loc << endl;
		
		FaceAnalysis::FaceAnalyser face_analyser(std::vector<cv::Vec3d>(), 0.7, 112, 112, au_loc, tri_loc);

		bool visualise = !det_parameters.quiet_mode;

		// Do some image loading
		for (size_t i = 0; i < files.size(); i++)
		{
			string file = files.at(i);

			// Loading image
			//cv::Mat read_image = cv::imread(file, -1);
			
			// Loading depth file if exists (optional)
			cv::Mat_<float> depth_image;

			if (depth_files.size() > 0)
			{
				string dFile = depth_files.at(i);
				cv::Mat dTemp = cv::imread(dFile, -1);
				dTemp.convertTo(depth_image, CV_32F);
			}

			// Making sure the image is in uchar grayscale
			cv::Mat_<uchar> grayscale_image;
			convert_to_grayscale(read_image, grayscale_image);


			// If optical centers are not defined just use center of image
			if (cx_undefined)
			{
				cx = grayscale_image.cols / 2.0f;
				cy = grayscale_image.rows / 2.0f;
			}
			// Use a rough guess-timate of focal length
			if (fx_undefined)
			{
				fx = 500 * (grayscale_image.cols / 640.0);
				fy = 500 * (grayscale_image.rows / 480.0);

				fx = (fx + fy) / 2.0;
				fy = fx;
			}


			// if no pose defined we just use a face detector
			if (bounding_boxes.empty())
			{

				// Detect faces in an image
				std::vector<cv::Rect_<double> > face_detections;

				if (det_parameters.curr_face_detector == LandmarkDetector::FaceModelParameters::HOG_SVM_DETECTOR)
				{
					std::vector<double> confidences;
					LandmarkDetector::DetectFacesHOG(face_detections, grayscale_image, face_detector_hog, confidences);
				}
				else
				{
					LandmarkDetector::DetectFaces(face_detections, grayscale_image, classifier);
				}

				// Detect landmarks around detected faces
				int face_det = 0;
				// perform landmark detection for every face detected
				for (size_t face = 0; face < face_detections.size(); ++face)
				{
					// if there are multiple detections go through them
					bool success = LandmarkDetector::DetectLandmarksInImage(grayscale_image, depth_image, face_detections[face], clnf_model, det_parameters);

					// Estimate head pose and eye gaze				
					cv::Vec6d headPose = LandmarkDetector::GetCorrectedPoseWorld(clnf_model, fx, fy, cx, cy);

					// Gaze tracking, absolute gaze direction
					cv::Point3f gazeDirection0(0, 0, -1);
					cv::Point3f gazeDirection1(0, 0, -1);

					if (success && det_parameters.track_gaze)
					{
						FaceAnalysis::EstimateGaze(clnf_model, gazeDirection0, fx, fy, cx, cy, true);
						FaceAnalysis::EstimateGaze(clnf_model, gazeDirection1, fx, fy, cx, cy, false);

					}

				/*	
					cv::imshow("read_image", read_image);
					cv::waitKey(0);

					cv::imshow("grayscale_image", grayscale_image);
					cv::waitKey(0);

					cv::imshow("depth_image", depth_image);
					cv::waitKey(0);
					*/

					auto ActionUnits = face_analyser.PredictStaticAUs(read_image, clnf_model, false);

					// Writing out the detected landmarks (in an OS independent manner)
					if (!output_landmark_locations.empty())
					{
						char name[100];
						// append detection number (in case multiple faces are detected)
						sprintf(name, "_det_%d", face_det);

						// Construct the output filename
						boost::filesystem::path slash("/");
						std::string preferredSlash = slash.make_preferred().string();

						boost::filesystem::path out_feat_path(output_landmark_locations.at(i));
						boost::filesystem::path dir = out_feat_path.parent_path();
						//boost::filesystem::path dir = out_feat_path;
						std::cout << "number6" << dir.string() << std::endl;
						boost::filesystem::path fname = out_feat_path.filename().replace_extension("");
						boost::filesystem::path ext = out_feat_path.extension();
						string outfeatures = dir.string() + preferredSlash + fname.string() + string(name) + ext.string();
						write_out_landmarks(outfeatures, clnf_model, headPose, gazeDirection0, gazeDirection1, ActionUnits.first, ActionUnits.second, vector_AU);


						st1 = vector_AU[vector_AU.size() - 1];
						st2 = vector_AU[vector_AU.size() - 2];
						st3 = vector_AU[vector_AU.size() - 3];
						st4 = vector_AU[vector_AU.size() - 4];
						cout << st1 << " " << st2 << " " << st3 << " " << st4 << endl;

					}

					if (!output_pose_locations.empty())
					{
						char name[100];
						// append detection number (in case multiple faces are detected)
						sprintf(name, "_det_%d", face_det);

						// Construct the output filename
						boost::filesystem::path slash("/");
						std::string preferredSlash = slash.make_preferred().string();

						boost::filesystem::path out_pose_path(output_pose_locations.at(i));
						boost::filesystem::path dir = out_pose_path.parent_path();
						//boost::filesystem::path dir = out_pose_path;
						std::cout << "number7" << dir.string() << std::endl;
						boost::filesystem::path fname = out_pose_path.filename().replace_extension("");
						boost::filesystem::path ext = out_pose_path.extension();
						string outfeatures = dir.string() + preferredSlash + fname.string() + string(name) + ext.string();
						write_out_pose_landmarks(outfeatures, clnf_model.GetShape(fx, fy, cx, cy), headPose, gazeDirection0, gazeDirection1);

					}

					if (det_parameters.track_gaze)
					{
						cv::Vec6d pose_estimate_to_draw = LandmarkDetector::GetCorrectedPoseWorld(clnf_model, fx, fy, cx, cy);

						// Draw it in reddish if uncertain, blueish if certain
						LandmarkDetector::DrawBox(read_image, pose_estimate_to_draw, cv::Scalar(255.0, 0, 0), 3, fx, fy, cx, cy);
						FaceAnalysis::DrawGaze(read_image, clnf_model, gazeDirection0, gazeDirection1, fx, fy, cx, cy);
					}

					// displaying detected landmarks
					//cv::Mat display_image;
					//create_display_image(read_image, display_image, clnf_model);

					/*if (visualise && success)
					{
						cv::Mat tt(10, 10, CV_8U, cv::Scalar(150));
						imshow("colour", tt);
						cv::waitKey(1);
					}
					*/
					

					// Saving the display images (in an OS independent manner)
					if (!output_images.empty() && success)
					{
						string outimage = output_images.at(i);
						if (!outimage.empty())
						{
							char name[100];
							sprintf(name, "_det_%d", face_det);

							boost::filesystem::path slash("/");
							std::string preferredSlash = slash.make_preferred().string();

							// append detection number
							boost::filesystem::path out_feat_path(outimage);
							boost::filesystem::path dir = out_feat_path.parent_path();
							//boost::filesystem::path dir = out_feat_path;
							std::cout << "number1" << dir.string() << std::endl;
							boost::filesystem::path fname = out_feat_path.filename().replace_extension("");
							boost::filesystem::path ext = out_feat_path.extension();
							outimage = dir.string() + preferredSlash + fname.string() + string(name) + ext.string();
							create_directory_from_file(outimage);
							//imwrite(outimage, display_image);

						}

					}

					if (success)
					{
						face_det++;
					}

				}

				//std::cout << " bounding_boxes " << face_detections.size() << std::endl;
				face_numbers = face_detections.size();
			}
			else
			{
				// Have provided bounding boxes
				LandmarkDetector::DetectLandmarksInImage(grayscale_image, bounding_boxes[i], clnf_model, det_parameters);

				// Estimate head pose and eye gaze				
				cv::Vec6d headPose = LandmarkDetector::GetCorrectedPoseWorld(clnf_model, fx, fy, cx, cy);

				// Gaze tracking, absolute gaze direction
				cv::Point3f gazeDirection0(0, 0, -1);
				cv::Point3f gazeDirection1(0, 0, -1);

				if (det_parameters.track_gaze)
				{
					FaceAnalysis::EstimateGaze(clnf_model, gazeDirection0, fx, fy, cx, cy, true);
					FaceAnalysis::EstimateGaze(clnf_model, gazeDirection1, fx, fy, cx, cy, false);
				}

				auto ActionUnits = face_analyser.PredictStaticAUs(read_image, clnf_model, false);

				// Writing out the detected landmarks
				if (!output_landmark_locations.empty())
				{
					string outfeatures = output_landmark_locations.at(i);
					write_out_landmarks(outfeatures, clnf_model, headPose, gazeDirection0, gazeDirection1, ActionUnits.first, ActionUnits.second, vector_AU);
					st1 = vector_AU[vector_AU.size() - 1];
					st2 = vector_AU[vector_AU.size() - 2];
					st3 = vector_AU[vector_AU.size() - 3];
					st4 = vector_AU[vector_AU.size() - 4];
					cout << st1 << " " << st2 << " " << st3 << " " << st4 << endl;
				}

				// Writing out the detected landmarks
				if (!output_pose_locations.empty())
				{
					string outfeatures = output_pose_locations.at(i);
					write_out_pose_landmarks(outfeatures, clnf_model.GetShape(fx, fy, cx, cy), headPose, gazeDirection0, gazeDirection1);
				}

				// displaying detected stuff
				cv::Mat display_image;

				if (det_parameters.track_gaze)
				{
					cv::Vec6d pose_estimate_to_draw = LandmarkDetector::GetCorrectedPoseWorld(clnf_model, fx, fy, cx, cy);

					// Draw it in reddish if uncertain, blueish if certain
					LandmarkDetector::DrawBox(read_image, pose_estimate_to_draw, cv::Scalar(255.0, 0, 0), 3, fx, fy, cx, cy);
					FaceAnalysis::DrawGaze(read_image, clnf_model, gazeDirection0, gazeDirection1, fx, fy, cx, cy);
				}

				create_display_image(read_image, display_image, clnf_model);

				/*if (visualise)
				{
					imshow("colour", display_image);
					cv::waitKey(1);
				}
				*/

				if (!output_images.empty())
				{
					string outimage = output_images.at(i);
					if (!outimage.empty())
					{
						create_directory_from_file(outimage);
						imwrite(outimage, display_image);
					}
				}
			}

		}


		auto finish2 = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish2 - start2).count() << " ms" << std::endl;
		std::cout << "\n" << std::endl;

		std::string facenumber = std::to_string(face_numbers);
		vector_AU.push_back(facenumber);
		std::cout <<"face_numbers " << facenumber << std::endl;

		return vector_AU;
	}
//}

/*int main(int argc, char **argv)
{
	vector<string> arguments = get_arguments(argc, argv);
	vector<string> vector_AU = Emotion(arguments);
	string s1 = vector_AU[vector_AU.size() - 1];
	string s2 = vector_AU[vector_AU.size() - 2];
	string s3 = vector_AU[vector_AU.size() - 3];
	string s4 = vector_AU[vector_AU.size() - 4];
	cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
	return 0;
}
*/

	std::vector<string> FaceLandmarkImg::PoseHeadFrame(std::vector<string> arguments)
	{
		
		//std::cout << arguments[0] << std::endl;
		//std::cout << arguments[1] << std::endl;
		//std::cout << arguments[2] << std::endl;

		std::vector<string> vector_Pose;
		string st1, st2, st3, st4;
		string p1,p2,p3;
		//Convert arguments to more convenient vector form
		//vector<string> arguments = get_arguments(argc, argv);

		// Some initial parameters that can be overriden from command line
		std::vector<string> files, depth_files, output_images, output_landmark_locations, output_pose_locations;

		// Bounding boxes for a face in each image (optional)
		std::vector<cv::Rect_<double> > bounding_boxes;

		LandmarkDetector::get_image_input_output_params(files, depth_files, output_landmark_locations, output_pose_locations, output_images, bounding_boxes, arguments);
		LandmarkDetector::FaceModelParameters det_parameters(arguments);
		// No need to validate detections, as we're not doing tracking
		det_parameters.validate_detections = false;

		// Grab camera parameters if provided (only used for pose and eye gaze and are quite important for accurate estimates)
		float fx = 0, fy = 0, cx = 0, cy = 0;
		int device = -1;
		LandmarkDetector::get_camera_params(device, fx, fy, cx, cy, arguments);

		// If cx (optical axis centre) is undefined will use the image size/2 as an estimate
		bool cx_undefined = false;
		bool fx_undefined = false;
		if (cx == 0 || cy == 0)
		{
			cx_undefined = true;
		}
		if (fx == 0 || fy == 0)
		{
			fx_undefined = true;
		}

		// The modules that are being used for tracking
		cout << "Loading the model" << endl;
		LandmarkDetector::CLNF clnf_model(det_parameters.model_location);
		cout << "Model loaded" << endl;



		cv::CascadeClassifier classifier(det_parameters.face_detector_location);
		dlib::frontal_face_detector face_detector_hog = dlib::get_frontal_face_detector();

		// Loading the AU prediction models
		string au_loc = "AU_predictors/AU_all_static.txt";

		//cout << au_loc << endl;

/*
		if (!boost::filesystem::exists(boost::filesystem::path(au_loc)))
		{
			boost::filesystem::path loc = boost::filesystem::path(arguments[0]).parent_path() / au_loc;
			//boost::filesystem::path loc = boost::filesystem::path(arguments[0]) / au_loc;
			string au_loc2 = loc.string();
			cout << "number3" << au_loc2 << endl;

			if (boost::filesystem::exists(loc))
			{
				au_loc = loc.string();
				cout << "number4" << au_loc << endl;

				//	cout << au_loc << endl;

			}
			else
			{
				cout << "Can't find AU prediction files, exiting" << endl;
				//return 0;
			}
		}



		// Used for image masking for AUs
		string tri_loc;
		if (boost::filesystem::exists(boost::filesystem::path("model/tris_68_full.txt")))
		{
			std::ifstream triangulation_file("model/tris_68_full.txt");
			tri_loc = "model/tris_68_full.txt";
		}
		else
		{
			boost::filesystem::path loc = boost::filesystem::path(arguments[0]).parent_path() / "model/tris_68_full.txt";
			//boost::filesystem::path loc = boost::filesystem::path(arguments[0]) / "model/tris_68_full.txt";
			tri_loc = loc.string();
			cout << "number5" << tri_loc << endl;

			if (!exists(loc))
			{
				cout << "Can't find triangulation files, exiting" << endl;
				//return 0;
			}
		}

		cout << au_loc << " " << tri_loc << endl;

		*/
		string tri_loc = "model/tris_68_full.txt";
		FaceAnalysis::FaceAnalyser face_analyser(std::vector<cv::Vec3d>(), 0.7, 112, 112, au_loc, tri_loc);

		bool visualise = !det_parameters.quiet_mode;

		auto start3 = std::chrono::high_resolution_clock::now();

		// Do some image loading
		for (size_t i = 0; i < files.size(); i++)
		{
			string file = files.at(i);

			// Loading image
			cv::Mat read_image = cv::imread(file, -1);

			// Loading depth file if exists (optional)
			cv::Mat_<float> depth_image;

			if (depth_files.size() > 0)
			{
				string dFile = depth_files.at(i);
				cv::Mat dTemp = cv::imread(dFile, -1);
				dTemp.convertTo(depth_image, CV_32F);
			}


			// Making sure the image is in uchar grayscale
			cv::Mat_<uchar> grayscale_image;
			convert_to_grayscale(read_image, grayscale_image);


			// If optical centers are not defined just use center of image
			if (cx_undefined)
			{
				cx = grayscale_image.cols / 2.0f;
				cy = grayscale_image.rows / 2.0f;
			}
			// Use a rough guess-timate of focal length
			if (fx_undefined)
			{
				fx = 500 * (grayscale_image.cols / 640.0);
				fy = 500 * (grayscale_image.rows / 480.0);

				fx = (fx + fy) / 2.0;
				fy = fx;
			}


			// if no pose defined we just use a face detector
			if (bounding_boxes.empty())
			{

				// Detect faces in an image
				std::vector<cv::Rect_<double> > face_detections;

				if (det_parameters.curr_face_detector == LandmarkDetector::FaceModelParameters::HOG_SVM_DETECTOR)
				{
					std::vector<double> confidences;
					LandmarkDetector::DetectFacesHOG(face_detections, grayscale_image, face_detector_hog, confidences);
				}
				else
				{
					LandmarkDetector::DetectFaces(face_detections, grayscale_image, classifier);
				}

				// Detect landmarks around detected faces
				int face_det = 0;
				// perform landmark detection for every face detected
				for (size_t face = 0; face < face_detections.size(); ++face)
				{
					// if there are multiple detections go through them
					bool success = LandmarkDetector::DetectLandmarksInImage(grayscale_image, depth_image, face_detections[face], clnf_model, det_parameters);

					// Estimate head pose and eye gaze				
					cv::Vec6d headPose = LandmarkDetector::GetCorrectedPoseWorld(clnf_model, fx, fy, cx, cy);
					p1 = to_string(headPose[3]);
					p2 = to_string(headPose[4]);
					p3 = to_string(headPose[5]);
				}

				vector_Pose.push_back(p1);
				vector_Pose.push_back(p2);
				vector_Pose.push_back(p3);

				/*				// Gaze tracking, absolute gaze direction
								cv::Point3f gazeDirection0(0, 0, -1);
								cv::Point3f gazeDirection1(0, 0, -1);

								if (success && det_parameters.track_gaze)
								{
									FaceAnalysis::EstimateGaze(clnf_model, gazeDirection0, fx, fy, cx, cy, true);
									FaceAnalysis::EstimateGaze(clnf_model, gazeDirection1, fx, fy, cx, cy, false);

								}

								auto ActionUnits = face_analyser.PredictStaticAUs(read_image, clnf_model, false);

								// Writing out the detected landmarks (in an OS independent manner)
								if (!output_landmark_locations.empty())
								{
									char name[100];
									// append detection number (in case multiple faces are detected)
									sprintf(name, "_det_%d", face_det);

									// Construct the output filename
									boost::filesystem::path slash("/");
									std::string preferredSlash = slash.make_preferred().string();

									boost::filesystem::path out_feat_path(output_landmark_locations.at(i));
									boost::filesystem::path dir = out_feat_path.parent_path();
									//boost::filesystem::path dir = out_feat_path;
									std::cout << "number6" << dir.string() << std::endl;
									boost::filesystem::path fname = out_feat_path.filename().replace_extension("");
									boost::filesystem::path ext = out_feat_path.extension();
									string outfeatures = dir.string() + preferredSlash + fname.string() + string(name) + ext.string();
									write_out_landmarks(outfeatures, clnf_model, headPose, gazeDirection0, gazeDirection1, ActionUnits.first, ActionUnits.second, vector_AU);





									st1 = vector_AU[vector_AU.size() - 1];
									st2 = vector_AU[vector_AU.size() - 2];
									st3 = vector_AU[vector_AU.size() - 3];
									st4 = vector_AU[vector_AU.size() - 4];
									cout << st1 << " " << st2 << " " << st3 << " " << st4 << endl;
								}

								if (!output_pose_locations.empty())
								{
									char name[100];
									// append detection number (in case multiple faces are detected)
									sprintf(name, "_det_%d", face_det);

									// Construct the output filename
									boost::filesystem::path slash("/");
									std::string preferredSlash = slash.make_preferred().string();

									boost::filesystem::path out_pose_path(output_pose_locations.at(i));
									boost::filesystem::path dir = out_pose_path.parent_path();
									//boost::filesystem::path dir = out_pose_path;
									std::cout << "number7" << dir.string() << std::endl;
									boost::filesystem::path fname = out_pose_path.filename().replace_extension("");
									boost::filesystem::path ext = out_pose_path.extension();
									string outfeatures = dir.string() + preferredSlash + fname.string() + string(name) + ext.string();
									write_out_pose_landmarks(outfeatures, clnf_model.GetShape(fx, fy, cx, cy), headPose, gazeDirection0, gazeDirection1);

								}

								if (det_parameters.track_gaze)
								{
									cv::Vec6d pose_estimate_to_draw = LandmarkDetector::GetCorrectedPoseWorld(clnf_model, fx, fy, cx, cy);

									// Draw it in reddish if uncertain, blueish if certain
									LandmarkDetector::DrawBox(read_image, pose_estimate_to_draw, cv::Scalar(255.0, 0, 0), 3, fx, fy, cx, cy);
									FaceAnalysis::DrawGaze(read_image, clnf_model, gazeDirection0, gazeDirection1, fx, fy, cx, cy);
								}

								// displaying detected landmarks
								cv::Mat display_image;
								create_display_image(read_image, display_image, clnf_model);

								if (visualise && success)
								{
									imshow("colour", display_image);
									cv::waitKey(1);
								}

								// Saving the display images (in an OS independent manner)
								if (!output_images.empty() && success)
								{
									string outimage = output_images.at(i);
									if (!outimage.empty())
									{
										char name[100];
										sprintf(name, "_det_%d", face_det);

										boost::filesystem::path slash("/");
										std::string preferredSlash = slash.make_preferred().string();

										// append detection number
										boost::filesystem::path out_feat_path(outimage);
										boost::filesystem::path dir = out_feat_path.parent_path();
										//boost::filesystem::path dir = out_feat_path;
										std::cout << "number1" << dir.string() << std::endl;
										boost::filesystem::path fname = out_feat_path.filename().replace_extension("");
										boost::filesystem::path ext = out_feat_path.extension();
										outimage = dir.string() + preferredSlash + fname.string() + string(name) + ext.string();
										create_directory_from_file(outimage);
										imwrite(outimage, display_image);

									}

								}

								if (success)
								{
									face_det++;
								}

							}
						}
						else
						{
							// Have provided bounding boxes
							LandmarkDetector::DetectLandmarksInImage(grayscale_image, bounding_boxes[i], clnf_model, det_parameters);

							// Estimate head pose and eye gaze
							cv::Vec6d headPose = LandmarkDetector::GetCorrectedPoseWorld(clnf_model, fx, fy, cx, cy);

							// Gaze tracking, absolute gaze direction
							cv::Point3f gazeDirection0(0, 0, -1);
							cv::Point3f gazeDirection1(0, 0, -1);

							if (det_parameters.track_gaze)
							{
								FaceAnalysis::EstimateGaze(clnf_model, gazeDirection0, fx, fy, cx, cy, true);
								FaceAnalysis::EstimateGaze(clnf_model, gazeDirection1, fx, fy, cx, cy, false);
							}

							auto ActionUnits = face_analyser.PredictStaticAUs(read_image, clnf_model, false);

							// Writing out the detected landmarks
							if (!output_landmark_locations.empty())
							{
								string outfeatures = output_landmark_locations.at(i);
								write_out_landmarks(outfeatures, clnf_model, headPose, gazeDirection0, gazeDirection1, ActionUnits.first, ActionUnits.second, vector_AU);
								st1 = vector_AU[vector_AU.size() - 1];
								st2 = vector_AU[vector_AU.size() - 2];
								st3 = vector_AU[vector_AU.size() - 3];
								st4 = vector_AU[vector_AU.size() - 4];
								cout << st1 << " " << st2 << " " << st3 << " " << st4 << endl;
							}

							// Writing out the detected landmarks
							if (!output_pose_locations.empty())
							{
								string outfeatures = output_pose_locations.at(i);
								write_out_pose_landmarks(outfeatures, clnf_model.GetShape(fx, fy, cx, cy), headPose, gazeDirection0, gazeDirection1);
							}

							// displaying detected stuff
							cv::Mat display_image;

							if (det_parameters.track_gaze)
							{
								cv::Vec6d pose_estimate_to_draw = LandmarkDetector::GetCorrectedPoseWorld(clnf_model, fx, fy, cx, cy);

								// Draw it in reddish if uncertain, blueish if certain
								LandmarkDetector::DrawBox(read_image, pose_estimate_to_draw, cv::Scalar(255.0, 0, 0), 3, fx, fy, cx, cy);
								FaceAnalysis::DrawGaze(read_image, clnf_model, gazeDirection0, gazeDirection1, fx, fy, cx, cy);
							}

							create_display_image(read_image, display_image, clnf_model);

							if (visualise)
							{
								imshow("colour", display_image);
								cv::waitKey(1);
							}

							if (!output_images.empty())
							{
								string outimage = output_images.at(i);
								if (!outimage.empty())
								{
									create_directory_from_file(outimage);
									imwrite(outimage, display_image);
								}
							}
						}

					}
		*/
			}
		}
		std::cout << "time \n" << std::endl;
		auto finish3 = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish3 - start3).count() << " ms" << std::endl;
		

		return vector_Pose;
	}

	LandmarkDetector::CLNF PoseHeadFrame2(std::vector<string> arguments)
	{
		LandmarkDetector::FaceModelParameters det_parameters(arguments);
		cout << "Loading the model" << endl;
		LandmarkDetector::CLNF clnf_model(det_parameters.model_location);
		cout << "Model loaded" << endl;
		return clnf_model;
	}

	std::vector<string> PoseHeadFrame3(std::vector<string> arguments, LandmarkDetector::CLNF clnf_model, cv::Mat read_image)
	{

		//Convert arguments to more convenient vector form
		//vector<string> arguments = get_arguments(argc, argv);

		cout << "1" << endl;

		// Some initial parameters that can be overriden from command line
		std::vector<string> files, depth_files, output_images, output_landmark_locations, output_pose_locations;

		// Bounding boxes for a face in each image (optional)
		std::vector<cv::Rect_<double> > bounding_boxes;

		LandmarkDetector::get_image_input_output_params(files, depth_files, output_landmark_locations, output_pose_locations, output_images, bounding_boxes, arguments);

		cout << "2" << endl;
		LandmarkDetector::FaceModelParameters det_parameters(arguments);

		cout << "3" << endl;
		// No need to validate detections, as we're not doing tracking
		det_parameters.validate_detections = false;

		// Grab camera parameters if provided (only used for pose and eye gaze and are quite important for accurate estimates)
		float fx = 0, fy = 0, cx = 0, cy = 0;
		int device = -1;
		LandmarkDetector::get_camera_params(device, fx, fy, cx, cy, arguments);

		// If cx (optical axis centre) is undefined will use the image size/2 as an estimate
		bool cx_undefined = false;
		bool fx_undefined = false;
		if (cx == 0 || cy == 0)
		{
			cx_undefined = true;
		}
		if (fx == 0 || fy == 0)
		{
			fx_undefined = true;
		}

		// The modules that are being used for tracking
		/*	cout << "Loading the model" << endl;
		LandmarkDetector::CLNF clnf_model(det_parameters.model_location);
		cout << "Model loaded" << endl;

		*/

		cout << "4" << endl;
		cv::CascadeClassifier classifier(det_parameters.face_detector_location);
		dlib::frontal_face_detector face_detector_hog = dlib::get_frontal_face_detector();

		// Loading the AU prediction models
		string au_loc = "AU_predictors/AU_all_static.txt";


		string tri_loc = "model/tris_68_full.txt";
		FaceAnalysis::FaceAnalyser face_analyser(std::vector<cv::Vec3d>(), 0.7, 112, 112, au_loc, tri_loc);

		bool visualise = !det_parameters.quiet_mode;

		std::vector<string> vector_Pose;

		string p1, p2, p3;

		auto start3 = std::chrono::high_resolution_clock::now();

		// Do some image loading
	//	for (size_t i = 0; i < files.size(); i++)
	//	{
		//	string file = files.at(i);



			// Loading image
			//cv::Mat read_image = cv::imread(file, -1);

			// Loading depth file if exists (optional)
			cv::Mat_<float> depth_image;

			/*if (depth_files.size() > 0)
			{
			string dFile = depth_files.at(i);
			cv::Mat dTemp = cv::imread(dFile, -1);
			dTemp.convertTo(depth_image, CV_32F);
			}
			*/
			cout << "5" << endl;
			// Making sure the image is in uchar grayscale
			cv::Mat_<uchar> grayscale_image;
			convert_to_grayscale(read_image, grayscale_image);


			// If optical centers are not defined just use center of image
			if (cx_undefined)
			{
				cx = grayscale_image.cols / 2.0f;
				cy = grayscale_image.rows / 2.0f;
			}
			// Use a rough guess-timate of focal length
			if (fx_undefined)
			{
				fx = 500 * (grayscale_image.cols / 640.0);
				fy = 500 * (grayscale_image.rows / 480.0);

				fx = (fx + fy) / 2.0;
				fy = fx;
			}
			cout << "6" << endl;

			// if no pose defined we just use a face detector
			if (bounding_boxes.empty())
			{

				// Detect faces in an image
				std::vector<cv::Rect_<double> > face_detections;

				if (det_parameters.curr_face_detector == LandmarkDetector::FaceModelParameters::HOG_SVM_DETECTOR)
				{
					std::vector<double> confidences;
					LandmarkDetector::DetectFacesHOG(face_detections, grayscale_image, face_detector_hog, confidences);
				}
				else
				{
					LandmarkDetector::DetectFaces(face_detections, grayscale_image, classifier);
				}

				// Detect landmarks around detected faces
				int face_det = 0;
				// perform landmark detection for every face detected
				for (size_t face = 0; face < face_detections.size(); ++face)
				{
					// if there are multiple detections go through them
					bool success = LandmarkDetector::DetectLandmarksInImage(grayscale_image, depth_image, face_detections[face], clnf_model, det_parameters);
					cout << "6" << endl;
					// Estimate head pose and eye gaze				
					cv::Vec6d headPose = LandmarkDetector::GetCorrectedPoseWorld(clnf_model, fx, fy, cx, cy);
					p1 = to_string(headPose[3]);
					p2 = to_string(headPose[4]);
					p3 = to_string(headPose[5]);
				}

				vector_Pose.push_back(p1);
				vector_Pose.push_back(p2);
				vector_Pose.push_back(p3);


			}
		//}
		std::cout << "time \n" << std::endl;
		auto finish3 = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish3 - start3).count() << " ms" << std::endl;
		std::cout << "\n" << std::endl;

		return vector_Pose;
	}

	std::vector<string> FaceLandmarkImg::PoseHeadFrame4(std::vector<string> arguments, cv::Mat read_image)
	{
		auto start2 = std::chrono::high_resolution_clock::now();
		//Convert arguments to more convenient vector form
		//vector<string> arguments = get_arguments(argc, argv);

		cout << "1" << endl;

		// Some initial parameters that can be overriden from command line
		std::vector<string> files, depth_files, output_images, output_landmark_locations, output_pose_locations;

		// Bounding boxes for a face in each image (optional)
		std::vector<cv::Rect_<double> > bounding_boxes;

		LandmarkDetector::get_image_input_output_params(files, depth_files, output_landmark_locations, output_pose_locations, output_images, bounding_boxes, arguments);

		auto start21 = std::chrono::high_resolution_clock::now();
		cout << "2" << endl;
		LandmarkDetector::FaceModelParameters det_parameters(arguments);

		cout << "3" << endl;
		// No need to validate detections, as we're not doing tracking
		det_parameters.validate_detections = false;

		auto start22 = std::chrono::high_resolution_clock::now();
		// Grab camera parameters if provided (only used for pose and eye gaze and are quite important for accurate estimates)
		float fx = 0, fy = 0, cx = 0, cy = 0;
		int device = -1;
		LandmarkDetector::get_camera_params(device, fx, fy, cx, cy, arguments);

		// If cx (optical axis centre) is undefined will use the image size/2 as an estimate
		bool cx_undefined = false;
		bool fx_undefined = false;
		if (cx == 0 || cy == 0)
		{
			cx_undefined = true;
		}
		if (fx == 0 || fy == 0)
		{
			fx_undefined = true;
		}

		// The modules that are being used for tracking
		/*	cout << "Loading the model" << endl;
		LandmarkDetector::CLNF clnf_model(det_parameters.model_location);
		cout << "Model loaded" << endl;

		*/

		//static LandmarkDetector::CLNF clnf_model;

		//if (flag)
		//{
			static LandmarkDetector::CLNF clnf_model = PoseHeadFrame2(arguments);
		//}
			auto start23 = std::chrono::high_resolution_clock::now();
		cout << "4" << endl;
		static cv::CascadeClassifier classifier(det_parameters.face_detector_location);
		static dlib::frontal_face_detector face_detector_hog = dlib::get_frontal_face_detector();

		auto start24 = std::chrono::high_resolution_clock::now();
		// Loading the AU prediction models
		string au_loc = "AU_predictors/AU_all_static.txt";


		string tri_loc = "model/tris_68_full.txt";
		FaceAnalysis::FaceAnalyser face_analyser(std::vector<cv::Vec3d>(), 0.7, 112, 112, au_loc, tri_loc);

		bool visualise = !det_parameters.quiet_mode;

		std::vector<string> vector_Pose;

		string p1, p2, p3,p4,p5,p6;

		auto start3 = std::chrono::high_resolution_clock::now();

		// Do some image loading
		//	for (size_t i = 0; i < files.size(); i++)
		//	{
		//	string file = files.at(i);



		// Loading image
		//cv::Mat read_image = cv::imread(file, -1);

		// Loading depth file if exists (optional)
		cv::Mat_<float> depth_image;

		/*if (depth_files.size() > 0)
		{
		string dFile = depth_files.at(i);
		cv::Mat dTemp = cv::imread(dFile, -1);
		dTemp.convertTo(depth_image, CV_32F);
		}
		*/
		cout << "5" << endl;
		// Making sure the image is in uchar grayscale
		cv::Mat_<uchar> grayscale_image;
		convert_to_grayscale(read_image, grayscale_image);


		// If optical centers are not defined just use center of image
		if (cx_undefined)
		{
			cx = grayscale_image.cols / 2.0f;
			cy = grayscale_image.rows / 2.0f;
		}
		// Use a rough guess-timate of focal length
		if (fx_undefined)
		{
			fx = 500 * (grayscale_image.cols / 640.0);
			fy = 500 * (grayscale_image.rows / 480.0);

			fx = (fx + fy) / 2.0;
			fy = fx;
		}
		cout << "6" << endl;

		// if no pose defined we just use a face detector
		if (bounding_boxes.empty())
		{

			// Detect faces in an image
			std::vector<cv::Rect_<double> > face_detections;

			if (det_parameters.curr_face_detector == LandmarkDetector::FaceModelParameters::HOG_SVM_DETECTOR)
			{
				std::vector<double> confidences;
				LandmarkDetector::DetectFacesHOG(face_detections, grayscale_image, face_detector_hog, confidences);
			}
			else
			{
				LandmarkDetector::DetectFaces(face_detections, grayscale_image, classifier);
			}

			// Detect landmarks around detected faces
			int face_det = 0;
			// perform landmark detection for every face detected
			for (size_t face = 0; face < face_detections.size(); ++face)
			{
				// if there are multiple detections go through them
				bool success = LandmarkDetector::DetectLandmarksInImage(grayscale_image, depth_image, face_detections[face], clnf_model, det_parameters);
				cout << "6" << endl;
				// Estimate head pose and eye gaze				
				cv::Vec6d headPose = LandmarkDetector::GetCorrectedPoseWorld(clnf_model, fx, fy, cx, cy);
				p1 = to_string(headPose[3] * 180 / 3.14);
				p2 = to_string(headPose[4] * 180 / 3.14);
				p3 = to_string(headPose[5] * 180 / 3.14);
				p4 = to_string(headPose[0]);
				p5 = to_string(headPose[1]);
				p6 = to_string(headPose[2]);

				double detection_certainty = clnf_model.detection_certainty;
				bool detection_success = clnf_model.detection_success;

				std::cout <<"detection_certainty "<< detection_certainty << std::endl;

				double visualisation_boundary = 0.2;

				// Only draw if the reliability is reasonable, the value is slightly ad-hoc
				if (detection_certainty < visualisation_boundary)
				{
					LandmarkDetector::Draw(read_image, clnf_model);

					double vis_certainty = detection_certainty;
					if (vis_certainty > 1)
						vis_certainty = 1;
					if (vis_certainty < -1)
						vis_certainty = -1;

					vis_certainty = (vis_certainty + 1) / (visualisation_boundary + 1);

					// A rough heuristic for box around the face width
					int thickness = (int)std::ceil(2.0* ((double)read_image.cols) / 640.0);

					std::cout << "thickness " << thickness << std::endl;
					std::cout << "fx " << fx << "fy " << fy << "cx " << cx << "cy " << cy << std::endl;

					cv::Vec6d pose_estimate_to_draw = LandmarkDetector::GetCorrectedPoseWorld(clnf_model, fx, fy, cx, cy);

					// Draw it in reddish if uncertain, blueish if certain
					LandmarkDetector::DrawBox(read_image, pose_estimate_to_draw, cv::Scalar((1 - vis_certainty)*255.0, 0, vis_certainty * 255), thickness, fx, fy, cx, cy);

					cv::imshow("form", read_image);
					cv::waitKey(1);
				}

			}

			vector_Pose.push_back(p1);
			vector_Pose.push_back(p2);
			vector_Pose.push_back(p3);
			vector_Pose.push_back(p4);
			vector_Pose.push_back(p5);
			vector_Pose.push_back(p6);

		}
		//}
		std::cout << "time \n" << std::endl;
		auto finish3 = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish3 - start3).count() << " ms" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish3 - start2).count() << " ms" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish3 - start21).count() << " ms" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish3 - start22).count() << " ms" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish3 - start23).count() << " ms" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish3 - start24).count() << " ms" << std::endl;
		return vector_Pose;
	}