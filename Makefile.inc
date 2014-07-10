BASE_DIR	= /home/rapid/Desktop/repository/rp-mdedit
BUILD_DIR	= $(BASE_DIR)/build

CXX 		= g++
FLAGS 		= -O3
INCLUDE_DIRS= -I/home/rapid/Desktop/repository/rp-mdedit/src -I/usr/local/Qt-5.3.1/include
LIB_DIRS 	= -L/usr/local/Qt-5.3.1/lib
LIBS 		= -lQt5Core -lQt5Gui

# .SILENT: