# ----------------------------
# 変数
#   スコープは、このdirectoryと、ここから呼び出すadd_subdirectory.
# ----------------------------
set(TARGET ${PROJECT_LIB_NAME_SRC}) 
# ----------------------------
# ターゲット名
#   libの名前に使用される
#   VC上のプロジェクト名に使用される
# ----------------------------
project(${TARGET} LANGUAGES C CXX)

# ----------------------------
# コンパイル対象のソース一覧を作成
# ----------------------------
file(GLOB TARGET_SOURCES #GLOG_RECURSEを使うと指定したフォルダ以下は再帰的にプロジェクトに含まれる.
 ./*.[ch]  ./*.cpp
 )
 
 # ----------------------------
# libにする.
# ----------------------------
add_library(${TARGET} STATIC ${TARGET_SOURCES})
# CMAKE_SOURCE_DIR : this is the directory which contains the top-level CMakeLists.txt, i.e. the top level source directory
target_include_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/include)

clang_format(${TARGET})
clang_tidy(${TARGET})

