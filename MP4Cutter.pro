QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    streamreader.cpp \
    atoms/atom.cpp \
    atoms/dinf.cpp \
    atoms/hdlr.cpp \
    atoms/mdhd.cpp \
    atoms/mdia.cpp \
    atoms/minf.cpp \
    atoms/moov.cpp \
    atoms/mvhd.cpp \
    atoms/smhd.cpp \
    atoms/stbl.cpp \
    atoms/stco.cpp \
    atoms/stsc.cpp \
    atoms/stsd.cpp \
    atoms/stss.cpp \
    atoms/stsz.cpp \
    atoms/stts.cpp \
    atoms/tkhd.cpp \
    atoms/trak.cpp \
    atoms/vmhd.cpp \
    mp4parser.cpp \
    atoms/ftyp.cpp \
    streamwriter.cpp

HEADERS += \
    endians.h \
    streamreader.h \
    atoms/atom.h \
    atoms/dinf.h \
    atoms/hdlr.h \
    atoms/mdhd.h \
    atoms/mdia.h \
    atoms/minf.h \
    atoms/moov.h \
    atoms/mvhd.h \
    atoms/smhd.h \
    atoms/stbl.h \
    atoms/stco.h \
    atoms/stsc.h \
    atoms/stsd.h \
    atoms/stss.h \
    atoms/stsz.h \
    atoms/stts.h \
    atoms/tkhd.h \
    atoms/trak.h \
    atoms/vmhd.h \
    interfaces/callbackinterface.h \
    interfaces/parserinterface.h \
    mp4parser.h \
    atoms/ftyp.h \
    streamwriter.h
