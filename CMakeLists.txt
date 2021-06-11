cmake_minimum_required(VERSION 3.16)
project(k-means-cpp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

###########################################
# Copy input files
###########################################
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input/filelist.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
        )

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test/input/test_file.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
        )

###########################################
# Common Source Files
###########################################
set(COMMON_SRC
        source/algorithm/jaro_winkler.cpp
        source/kmeans/cluster.cpp
        source/kmeans/k_medoids.cpp
        source/kmeans/matrix.cpp
        source/logger/easylogging++.cc
        source/utility/output_writer.cpp
        source/utility/text_parser.cpp
        )

###########################################
# Test Source Files
###########################################
set(TEST_SRC
        test/algorithm/jaro_winkler_test.cpp
        test/utility/text_parser_test.cpp
        test/kmeans/cluster_test.cpp
        test/kmeans/k_medoids_test.cpp
        test/kmeans/matrix_test.cpp
        test/utility/output_writer_test.cpp
        )

###########################################
# Demo Executable
###########################################
add_executable(${PROJECT_NAME}
        ${COMMON_SRC}
        main.cpp
        )

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

install(TARGETS ${PROJECT_NAME}
        RUNTIME
        DESTINATION bin
        )

###########################################
# Tests
###########################################
add_executable(${PROJECT_NAME}_test
        ${COMMON_SRC}
        ${TEST_SRC}
        test/test_main.cpp
        )

target_include_directories(${PROJECT_NAME}_test
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

###########################################
# Coverage
###########################################
if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
        SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
        SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
        SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

        include(CodeCoverage)
        append_coverage_compiler_flags()

        setup_target_for_coverage_gcovr_html(
                NAME coverage
                EXECUTABLE ${PROJECT_NAME}_test
                BASE_DIRECTORY "${PROJECT_SOURCE_DIR}/source"
                EXCLUDE "${PROJECT_SOURCE_DIR}/source/algorithm/jaro_winkler.cpp"
        )
else()
        # Don't generate coverage for Release build
endif()

###########################################
# CPack
###########################################
set (CPACK_NAME ${PROJECT_NAME})
set(CPACK_GENERATE "DEB")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_PACKAGE_VENDOR "Thomas Li")
set(CPACK_PACKAGE_CONTACT "Thomas Li")
set(CPACK_DEBIAN_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_DEBIAN_FILE_NAME "${PROJECT_NAME}.deb")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")
set(CPACK_DEBIAN_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Thomas Li")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
set(CPACK_DEBIAN_COMPRESSION_TYPE "gzip")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")

include(CPack)
