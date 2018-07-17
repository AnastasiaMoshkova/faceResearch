

set(TARGET_H

  MyForm.h
  )


set(TARGET_SRC

  MyForm.cpp


  )
  
  set(TARGET_RESX

  MyForm.resx

  )
  
  
set_source_files_properties(${TARGET_SRC} PROPERTIES COMPILE_FLAGS "/clr")

#SET (SYSLIBS "C:/Program Files (x86)/Reference Assemblies/Microsoft/Framework/.NETFramework/v4.5.2")
#SET (SYSLIBS "include/mscorlib.dll;include/System.dll;include/System.Data.dll;include/System.Drawing.dll;include/System.Windows.Forms.dll;include/System.Xml.dll")
#SET (PROJECT_NAME "E:/openface2/OpenFace-OpenFace_v0.2/exe/ProjectCLR")
#set(TARGET_LIBRARIES ${SYSLIBS})
MESSAGE("SYSLIBS: ${SYSLIBS}") 

add_executable(PrCLR ${TARGET_SRC} ${TARGET_H} ${TARGET_RESX})
MESSAGE("PROJECT_NAME: ${PROJECT_NAME}") 


# Note: The property VS_GLOBAL_KEYWORD must be set.

set_property(TARGET PrCLR PROPERTY VS_GLOBAL_KEYWORD "ManagedCProj")



# Note: The property VS_DOTNET_REFERENCES must be set.

set_property(TARGET PrCLR PROPERTY VS_DOTNET_REFERENCES "mscorlib" "System" "System.Data" "System.Drawing" "System.Windows.Forms" "System.Xml")


include_directories(../../lib/local/FaceLandmarkImg/include)

target_link_libraries(PrCLR FaceLandmarkImg)
target_link_libraries(PrCLR ${OpenCV_LIBS})

# Note: Modification of compiler flags is required for CLR compatibility now that we are using .resx files.

string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

string(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")

