cmake_minimum_required(VERSION 3.21)
project(LW_5e C)

set(CMAKE_C_STANDARD 11)

add_executable(LW_5e main.c string/string_.c string/string_.h)

add_library (str string/string_.h string/string_.c
        # string / tasks / digitToStartTransform .h
        # string / tasks / reverseWords .h
        # string / tasks / replaceDigitsBySpaces .h
        # ...
        # < файл с решением задачи >
        # ...
        # string / tasks / hasPairOfWordsWithEqualLetterSet .h
        # string / tasks / printWordsNonEqualLastWord .h
        )

target_link_libraries (LW_5e str)