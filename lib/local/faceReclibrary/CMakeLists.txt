
SET(SOURCE
	FaceRecDLib.cpp
)

SET(HEADERS
    basictypes.h
	include/FaceRecDLib.h
)

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
include_directories(lib/3rdParty/dlib)
add_library( faceReclibrary SHARED ${SOURCE} ${HEADERS})
target_link_libraries(faceReclibrary dlib)

target_link_libraries(faceReclibrary ${OpenCV_LIBS})

#install (TARGETS FaceLandmarkImg DESTINATION ${CMAKE_BINARY_DIR}/bin)
