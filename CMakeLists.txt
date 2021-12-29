# ----------------------------
# 必要な最小バージョンを指定.
# ----------------------------
cmake_minimum_required(VERSION 3.1)

# ----------------------------
# プロジェクト名, 言語を指定.
# ----------------------------
project(codec_pctest_project C CXX)

message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/pkgconfig/ubuntu")
set(ENV{PKG_CONFIG_PATH} "${CMAKE_SOURCE_DIR}/pkgconfig/ubuntu")


# ----------------------------
# 共通設定
# ----------------------------
#enable_testing()
set(CMAKE_BUILD_TYPE Debug)
include(./DoClangTidy.cmake)
include(./FormatFilesWithClangFormat.cmake)

# ----------------------------
# プロジェクト名, 言語を指定.
# ----------------------------
# project, libの名前に使われる. sub directoryでも有効.
set(PROJECT_LIB_NAME_SRC src)
add_subdirectory(src)
add_subdirectory(test)


