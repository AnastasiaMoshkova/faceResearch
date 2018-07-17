#TBB library
#include_directories(${TBB_ROOT_DIR}/include)
include_directories(${TBB_INCLUDE_DIR})
include_directories(${TBB_INCLUDE_DIR}/tbb)
include_directories(lib/3rdParty/dlib)
# Local libraries
include_directories(${LandmarkDetector_SOURCE_DIR}/include)
	
include_directories(../LandmarkDetector/include)
include_directories(../FaceAnalyser/include)	
			
#add_executable(FaceLandmarkImg FaceLandmarkImg.cpp)
SET(SOURCE
    FaceLandmarkImg.cpp
)

SET(HEADERS
    FaceLandmarkImg.h
)

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

add_library( FaceLandmarkImg SHARED ${SOURCE} ${HEADERS})
target_link_libraries(FaceLandmarkImg LandmarkDetector)
target_link_libraries(FaceLandmarkImg FaceAnalyser)
target_link_libraries(FaceLandmarkImg dlib)

target_link_libraries(FaceLandmarkImg ${OpenCV_LIBS} ${Boost_LIBRARIES} ${TBB_LIBRARY})

#install (TARGETS FaceLandmarkImg DESTINATION ${CMAKE_BINARY_DIR}/bin)
