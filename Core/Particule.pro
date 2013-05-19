#-------------------------------------------------
#
# Project created by QtCreator 2013-05-14T13:18:23
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = Core
TEMPLATE = app


SOURCES += ../Common/RandomNumberGenerator.cpp \
    ../Common/Object.cpp \
    ../Common/LF_String.cpp \
    ../Common/GlWindow.cpp \
    ../Common/GlFramework.cpp \
    src/Particule.cpp \
	src/Main.cpp \
	src/App.cpp \
    src/ParticuleGenerateur.cpp \
    src/utils.cpp

HEADERS  += ../Common/Vectors.h \
    ../Common/Types.h \
    ../Common/RandomNumberGenerator.h \
    ../Common/Object.h \
    ../Common/MemDefns.h \
    ../Common/LF_String.h \
    ../Common/GlWindow.h \
    ../Common/GlFramework.h \
    ../Common/AbstractFramework.h \
    include/Particule.h \
	include/App.h \
    include/ParticuleGenerateur.h \
    include/utils.h


INCLUDEPATH = ../Common/ src ../glew-mingw/include include

win32 {
    LIBS += -L../glew-mingw/lib -lglew32
}

OTHER_FILES += \
    ../Shaders/color.vs \
    ../Shaders/color.fs
