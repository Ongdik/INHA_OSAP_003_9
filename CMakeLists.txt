# 최신 CMake 버전 기준으로 프로젝트 초기화
cmake_minimum_required(VERSION 3.20)
project(my_project)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 커버리지 설정 옵션
option(ENABLE_COVERAGE "Enable coverage" ON)

# 커버리지 빌드 플래그 설정
if(ENABLE_COVERAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g -O0 -Wall -fprofile-arcs -ftest-coverage -fno-inline")
endif()

# GoogleTest 다운로드 및 설정
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# Windows에서의 CRT 설정 방지 (필요한 경우에만 적용)
if (WIN32)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(googletest)

# 테스트 활성화
enable_testing()

# 테스트 파일과 소스 파일을 포함하여 unit_tests 실행 파일 생성
add_executable(
  unit_tests
  test/set_test.cc
  #test/bst_tree_test.cc
  source/set.cc
  #source/bst_tree.cc
)

# GoogleTest 라이브러리 링크
target_link_libraries(
	unit_tests
	GTest::gtest_main
)

# 메인 프로그램 실행 파일 생성 (필요할 경우에만 사용)
#add_executable(
#	main.out
#  source/main.cc
#  source/avl_tree.cc
#  source/bst_tree.cc
#)

# Google Test의 자동 테스트 디스커버리
include(GoogleTest)
gtest_discover_tests(unit_tests)
