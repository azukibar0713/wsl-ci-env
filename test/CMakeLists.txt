if(MSVC)
  link_directories(${PROJECT_SOURCE_DIR}/lib/win)
else()
  link_directories(${PROJECT_SOURCE_DIR}/lib/ubuntu)
endif()
# -------------
# pkg-config
# -------------
if(MSVC)
else()
  find_package(PkgConfig)
  pkg_search_module(GTEST gtest REQUIRED) # REQUIREDオプションは、エラーがあった時、メッセージを出力して処理を停止させる。
endif()

# ----------------------------
# GoogleTest libを使ったときのruntime library不一致対策.
# ----------------------------
if(MSVC)
    string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
    string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_MINSIZEREL ${CMAKE_C_FLAGS_MINSIZEREL})
    string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})
    string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_RELWITHDEBINFO ${CMAKE_C_FLAGS_RELWITHDEBINFO})
    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_MINSIZEREL ${CMAKE_CXX_FLAGS_MINSIZEREL})
    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})
    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELWITHDEBINFO ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
endif()

# ----------------------------
# コンパイル対象のソース一覧を作成
# ----------------------------
file(GLOB TARGET_SOURCES #GLOG_RECURSEを使うと指定したフォルダ以下は再帰的にプロジェクトに含まれる.
  ./*.cpp
  ./atcoder/*.cpp
)
#message(STATUS "TARGET_SOURCES: ${TARGET_SOURCES}")
# -------------
# 
# -------------
add_executable(TestSample1 ${TARGET_SOURCES})
target_include_directories(TestSample1 PRIVATE ${CMAKE_SOURCE_DIR}/include)

if(MSVC)
  target_link_libraries(TestSample1 debug gtestd gmockd ${PROJECT_LIB_NAME_SRC})
else()
  target_link_libraries(TestSample1 gtest ${GTEST_LDFLAGS} gcov ${PROJECT_LIB_NAME_SRC})
endif()

# -------------
# CTest
# 今一つメリット分からないのでコメントアウト
# -------------
#include(GoogleTest)
# Google Testの各テストケースごとにCTestのテストを作成する
#gtest_add_tests(TARGET TestSample1)
# CTestのテストをひとつだけ作成する
#add_test(NAME AllTests COMMAND TestSample1)


