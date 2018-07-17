#TBB library
#include_directories(${TBB_ROOT_DIR}/include)


add_executable(test2 test.cpp)

# Local libraries

include_directories(../../lib/local/FaceLandmarkImg/include)		


target_link_libraries(test2 FaceLandmarkImg)

target_link_libraries(test2 ${OpenCV_LIBS})
