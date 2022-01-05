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

# set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
# ビルドオプションに「--coverage」を追加.
# gcov用のファイルを出力するオプションで、build/test/CMakeFiles/UnitTestExecutor.dir配下に.gcnoというファイルが生成されます
# コンパイル時には「-fprofile-arcs -ftest-coverage」、リンク時には「-lgcov」に付けてくれる便利なものです。
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_EXE_LINKER_FLAGS: ${CMAKE_EXE_LINKER_FLAGS}")

# ----------------------------
# プロジェクト名, 言語を指定.
# ----------------------------
# project, libの名前に使われる. sub directoryでも有効.
set(PROJECT_LIB_NAME_SRC src)
add_subdirectory(src)
add_subdirectory(test)


