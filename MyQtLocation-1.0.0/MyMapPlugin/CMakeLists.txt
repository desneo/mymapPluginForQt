cmake_minimum_required(VERSION 3.15)
project(qtgeoservices_mymap)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

if (WIN32)
    # 解决msvc下编译包文件格式的问题
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif ()

# 设置Qt的安装路径
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/msvc2019_64")
find_package(Qt5 COMPONENTS Core Location Network REQUIRED)
set(CMAKE_CXX_STANDARD 11)

include_directories(C:/Qt/5.15.2/msvc2019_64/include/QtLocation/5.15.2)
include_directories(C:/Qt/5.15.2/msvc2019_64/include/QtPositioning/5.15.2)
include_directories(C:/Qt/5.15.2/msvc2019_64/include/QtCore/5.15.2)

add_library(qtgeoservices_mymap SHARED
    GeoServiceProviderFactoryMyMap.h
    GeoServiceProviderFactoryMyMap.cpp
    GeoTileFetcherMyMap.h
    GeoTileFetcherMyMap.cpp
    GeoTiledMapReplyMyMap.h
    GeoTiledMapReplyMyMap.cpp
    GeoTiledMappingManagerEngineMyMap.h
    GeoTiledMappingManagerEngineMyMap.cpp
    mymap_plugin.json
)

target_link_libraries(qtgeoservices_mymap PRIVATE
    Qt5::Core
    Qt5::Location
    Qt5::Network
)

set_target_properties(qtgeoservices_mymap PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${QT_INSTALL_PLUGINS}/geoservices"
)

#install(TARGETS qtgeoservices_mymap
#    LIBRARY DESTINATION ${QT_INSTALL_PLUGINS}/geoservices
#)

#install(FILES mymap_plugin.json
#    DESTINATION ${QT_INSTALL_PLUGINS}/geoservices
#)
