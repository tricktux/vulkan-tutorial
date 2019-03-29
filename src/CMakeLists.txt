# All the source files for the bot.
file(GLOB SOURCES "main.cpp")
file(GLOB TRI "triangle.cpp")

include_directories(
		${CMAKE_SOURCE_DIR}/inc
		SYSTEM "${GLOG_INCLUDE_DIRS}"
		SYSTEM "${RAPIDJSON_INCLUDE_DIRS}"
		SYSTEM "${Vulkan_INCLUDE_DIR}"
	)

# Show more warnings at compiletime.
if (MSVC)
    # FIXME: put Windows specific options here.
else ()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ()

add_executable(compiles ${SOURCES})

target_link_libraries(compiles 
		${GLOG_LIBRARIES}
		${Vulkan_LIBRARY}
		glm
		glfw
	)

add_executable(triangle_app ${TRI})

target_link_libraries(triangle_app 
	${GLOG_LIBRARIES}
	${Vulkan_LIBRARY}
	glm
	glfw
	)
