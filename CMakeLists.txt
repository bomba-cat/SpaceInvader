cmake_minimum_required(VERSION 3.13)
project(SpaceInvader C)

add_executable(spaceinvader
	src/main.c
	src/player.c
	src/framelimiter.c
)

message(${CMAKE_SOURCE_DIR})

target_include_directories(spaceinvader PUBLIC
	${CMAKE_SOURCE_DIR}/headers/
	${CMAKE_SOURCE_DIR}/src/
)

target_link_libraries(spaceinvader PRIVATE
	${CMAKE_SOURCE_DIR}/lib/libZFB.a
	gdi32
)
