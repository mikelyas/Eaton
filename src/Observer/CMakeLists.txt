set(OBSERVER_LIBRARY_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Observer.cc")
set(OBSERVER_LIBRARY_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/Observer.h")

add_library(${OBSERVER_LIBRARY_NAME} STATIC
    ${OBSERVER_LIBRARY_SOURCES}
    ${OBSERVER_LIBRARY_HEADERS})
target_link_libraries(
    ${OBSERVER_LIBRARY_NAME}
    PUBLIC ${THREAD_SAFE_LIBRARY_NAME}
)
target_include_directories(${OBSERVER_LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})