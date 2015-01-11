#-------------------------------------------------
#
# Project created by QtCreator 2014-12-09T02:12:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Logo
TEMPLATE = app

INCLUDEPATH += $$PWD/../LogoEngine/src/
INCLUDEPATH += $$PWD


SOURCES += main.cpp\
        mainwindow.cpp \
    ../LogoEngine/src/Statements/Command.cpp \
    ../LogoEngine/src/Statements/Condition.cpp \
    ../LogoEngine/src/Statements/Factor.cpp \
    ../LogoEngine/src/Statements/FunctionCall.cpp \
    ../LogoEngine/src/Statements/FunctionDeclaration.cpp \
    ../LogoEngine/src/Statements/Order.cpp \
    ../LogoEngine/src/Statements/Program.cpp \
    ../LogoEngine/src/Statements/Repeat.cpp \
    ../LogoEngine/src/Statements/SimpExpr.cpp \
    ../LogoEngine/src/Statements/Statement.cpp \
    ../LogoEngine/src/Statements/Term.cpp \
    ../LogoEngine/src/Statements/VariableAssignment.cpp \
    ../LogoEngine/src/Statements/VariableDeclaration.cpp \
    ../LogoEngine/src/Parser.cpp \
    ../LogoEngine/src/Scan.cpp \
    ../LogoEngine/src/Stack.cpp \
    ../LogoEngine/src/Turtle.cpp

HEADERS  += mainwindow.h \
    ../LogoEngine/src/Statements/AllStatements.h \
    ../LogoEngine/src/Statements/Command.h \
    ../LogoEngine/src/Statements/Condition.h \
    ../LogoEngine/src/Statements/Factor.h \
    ../LogoEngine/src/Statements/FunctionCall.h \
    ../LogoEngine/src/Statements/FunctionDeclaration.h \
    ../LogoEngine/src/Statements/Order.h \
    ../LogoEngine/src/Statements/Program.h \
    ../LogoEngine/src/Statements/Repeat.h \
    ../LogoEngine/src/Statements/SimpExpr.h \
    ../LogoEngine/src/Statements/Statement.h \
    ../LogoEngine/src/Statements/Term.h \
    ../LogoEngine/src/Statements/VariableAssignment.h \
    ../LogoEngine/src/Statements/VariableDeclaration.h \
    ../LogoEngine/src/Parser.h \
    ../LogoEngine/src/Scan.h \
    ../LogoEngine/src/Stack.h \
    ../LogoEngine/src/SysType.h \
    ../LogoEngine/src/Turtle.h

FORMS    += mainwindow.ui
