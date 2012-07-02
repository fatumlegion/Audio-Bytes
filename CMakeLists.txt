cmake_minimum_required(VERSION 2.8)

project (audiobytes)

set (audiobytes_SRCS
	main.cpp
	helper.cpp
	PlatformHelper.cpp
	ThemeLoader.cpp
	LibraryWorld.cpp
)

add_executable(a ${audiobytes_SRCS})
target_link_libraries(a sfml-graphics sfml-window sfml-system libticppd.a libfmodex.so)