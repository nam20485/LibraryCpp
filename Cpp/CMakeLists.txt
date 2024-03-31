add_library(Cpp SHARED   "Cpp.cpp" "cpp_export.h" "Containers/LinkedList.h" "Containers/LinkedListIterator.h" "Containers/IStlContainer.h" "sqrt/bssqrt.cpp" "sqrt/sqrt.cpp" "sqrt/sqrt.h")

# state that anybody linking to us needs to include the current source dir, while we don't.
target_include_directories(Cpp
                           INTERFACE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:include>)
