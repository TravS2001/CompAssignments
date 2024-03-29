QT -= gui

TEMPLATE = lib
DEFINES += FRACTION_LIBRARY

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fraction.cpp

HEADERS += \
    Fraction_global.h \
    fraction.h

TRANSLATIONS += \
    Fraction_en_CA.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
