 lcovファイルの作り方
 lcov -c -d ./build -o coverage.info
 lcov -r coverage.info */googletest/* test/* */c++/* -o coverageFiltered.info
 ls -al
 mv coverageFiltered.info ./coverage
 ls -al
 mv coverage/coverageFiltered.info coverage/lcov.info
 history