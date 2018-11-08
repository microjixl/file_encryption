file(GLOB SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/blowfish/*.c
        )

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(FILE_TEST ${CMAKE_CURRENT_SOURCE_DIR}/test/file_test.cpp ${SOURCE_FILES})

add_library(mj-file-encryption STATIC ${SOURCE_FILES})