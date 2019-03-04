CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(link-nodes)
 
# Locate GTest
FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})


INCLUDE_DIRECTORIES(${link-nodes_SOURCE_DIR}/include/})
INCLUDE_DIRECTORIES(${link-nodes_SOURCE_DIR}/src/})

ADD_EXECUTABLE(output
                includes/Node.h
                includes/Tree.h
                includes/NodeWithList.h
                src/Node.cpp
                src/Tree.cpp
                src/NodeWithList.cpp
                src/main.cpp
                )
TARGET_LINK_LIBRARIES(output ${GTEST_LIBRARIES} pthread)


OPTION(TS "Compilation for Testing" ON)

IF(TS)
  add_definitions(-DTEST_SW=1)
ENDIF(TS)