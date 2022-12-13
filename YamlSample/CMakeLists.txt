cmake_minimum_required(VERSION 3.5)

project(YamlSample LANGUAGES C)

add_executable(YamlSample main.c)

include(FetchContent)

FetchContent_Declare(
    yaml SOURCE_DIR ${PROJECT_SOURCE_DIR}/ext/libyaml
)

FetchContent_GetProperties(yaml)

if(NOT libyaml_POPULATED)
    FetchContent_Populate(yaml)
    # win: 下边这行是将yaml添加到解决方案中
    add_subdirectory(${yaml_SOURCE_DIR} ${yaml_BINARY_DIR})
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC yaml)

install(TARGETS YamlSample
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
