cmake_minimum_required(VERSION 3.8)
project(Gra)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_NAME "Gra")

set(SOURCE_FILES main.cpp Tile.cpp Tile.h Object.cpp Object.h GameManager.cpp GameManager.h DrawingManager.cpp DrawingManager.h Map.cpp Map.h MapLoader.cpp MapLoader.h ObjectManager.cpp ObjectManager.h UIManager.cpp UIManager.h DrawableObject.cpp DrawableObject.h UIElement.cpp UIElement.h UILabel.cpp UILabel.h ObjectLoader.cpp ObjectLoader.h UIElement.cpp UIElement.h ObjectFirestation.cpp ObjectFirestation.h ObjectFiretruck.cpp ObjectFiretruck.h ObjectHelicopter.cpp ObjectHelicopter.h)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)