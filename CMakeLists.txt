cmake_minimum_required(VERSION 3.22.1)

project("ccstorderSystem")


file(GLOB all_soure_code 
${PROJECT_SOURCE_DIR}/src/othercpp/*.cpp
)

file(COPY ${CMAKE_SOURCE_DIR}/Data/. DESTINATION ${CMAKE_BINARY_DIR})



add_library(ccstorderSystem_lib 
STATIC 
${all_soure_code}
)


target_include_directories(ccstorderSystem_lib 
PUBLIC
${PROJECT_SOURCE_DIR}/header
)



add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} 
PUBLIC
ccstorderSystem_lib

)