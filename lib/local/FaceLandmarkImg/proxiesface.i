/* File : example.i */
%module FaceLandmarkImg

%include "windows.i"
%include "std_vector.i"
%include "std_string.i"
%{
#include "FaceLandmarkImg.h"
%}

%include "FaceLandmarkImg.h"

namespace std {
	%template(ListString) vector<string>;
}

