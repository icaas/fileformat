
add_subdirectory(elfio)
if(FILEFORMAT_TESTS)
	add_subdirectory(googletest)
endif()

set(LIBDWARF_INSTALL_TO_UNITTESTS ${FILEFORMAT_TESTS} CACHE BOOL "enable libdwarf installation to unit tests directory" FORCE)
add_subdirectory(libdwarf)

add_subdirectory(llvm)
add_subdirectory(openssl)
add_subdirectory(pelib)
add_subdirectory(rapidjson)
add_subdirectory(retdec-config)
add_subdirectory(tinyxml2)
add_subdirectory(tl-cpputils)
add_subdirectory(yaracpp)
