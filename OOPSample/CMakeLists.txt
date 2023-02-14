cmake_minimum_required(VERSION 3.5)

project(OOPSample LANGUAGES C)

add_executable(OOPSample 
	main.c
	shape.h
	shape.c
	rectangle.h
	rectangle.c
	circle.h
	circle.c
)

install(TARGETS OOPSample LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})