TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        func-tubos.c \
        main.c

HEADERS += \
    funcoes.h

DISTFILES += \
    LICENSE \
    README.md \
    opt/data/dim-ac/c180longo.csv \
    opt/data/dim-ac/c45.csv \
    opt/data/dim-ac/c90curto.csv \
    opt/data/dim-ac/c90longo.csv \
    opt/data/dim-ac/tamtubo.csv \
    opt/data/dim-ac/teLinha.csv \
    opt/data/dim-ac/teRamal.csv \
    opt/data/dim-ac/uniaoFiltroY.csv \
    opt/data/dim-ac/valAng.csv \
    opt/data/dim-ac/valGav.csv \
    opt/data/dim-ac/valGlob.csv \
    opt/data/dim-ac/valPort.csv

