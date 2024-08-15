TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11
LIBS += -L"C:\Users\maylk\Desktop\SFML-2.5.1\lib"
LIBS += -L"C:\Users\maylk\Desktop\SFML-2.5.1\bin"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += "C:\Users\maylk\Desktop\SFML-2.5.1\include"
DEPENDPATH += "C:\Users\maylk\Desktop\SFML-2.5.1\include"

SOURCES += \
        ../../!includes/Graphing_Calculator/animate.cpp \
        ../../!includes/Graphing_Calculator/coor_translator.cpp \
        ../../!includes/Graphing_Calculator/graph.cpp \
        ../../!includes/Graphing_Calculator/graph_info.cpp \
        ../../!includes/Graphing_Calculator/plot.cpp \
        ../../!includes/Graphing_Calculator/rpn.cpp \
        ../../!includes/Graphing_Calculator/sidebar.cpp \
        ../../!includes/Graphing_Calculator/sidebar_button.cpp \
        ../../!includes/Graphing_Calculator/system.cpp \
        ../../!includes/Graphing_Calculator/tokenizer.cpp \
        ../../!includes/RPN_Shunting_Yard/function.cpp \
        ../../!includes/RPN_Shunting_Yard/l_paren.cpp \
        ../../!includes/RPN_Shunting_Yard/number.cpp \
        ../../!includes/RPN_Shunting_Yard/operator.cpp \
        ../../!includes/RPN_Shunting_Yard/r_paren.cpp \
        ../../!includes/RPN_Shunting_Yard/shunting_yard.cpp \
        ../../!includes/RPN_Shunting_Yard/token.cpp \
        ../../!includes/RPN_Shunting_Yard/variable.cpp \
        main.cpp

HEADERS += \
    ../../!includes/AddEntry/Add_Remove_Entry.h \
    ../../!includes/Graphing_Calculator/animate.h \
    ../../!includes/Graphing_Calculator/coor_translator.h \
    ../../!includes/Graphing_Calculator/graph.h \
    ../../!includes/Graphing_Calculator/graph_info.h \
    ../../!includes/Graphing_Calculator/plot.h \
    ../../!includes/Graphing_Calculator/rpn.h \
    ../../!includes/Graphing_Calculator/sidebar.h \
    ../../!includes/Graphing_Calculator/sidebar_button.h \
    ../../!includes/Graphing_Calculator/system.h \
    ../../!includes/Graphing_Calculator/tokenizer.h \
    ../../!includes/List_Functions/iterator_list.h \
    ../../!includes/List_Functions/node.h \
    ../../!includes/List_Functions/queue.h \
    ../../!includes/List_Functions/stack.h \
    ../../!includes/RPN_Shunting_Yard/function.h \
    ../../!includes/RPN_Shunting_Yard/l_paren.h \
    ../../!includes/RPN_Shunting_Yard/number.h \
    ../../!includes/RPN_Shunting_Yard/operator.h \
    ../../!includes/RPN_Shunting_Yard/r_paren.h \
    ../../!includes/RPN_Shunting_Yard/shunting_yard.h \
    ../../!includes/RPN_Shunting_Yard/token.h \
    ../../!includes/RPN_Shunting_Yard/variable.h \
    ../../!includes/Vector_class/vector.h \
    ../../!includes/pointerFunctions/one_d_functions.h \
    WorkReport.h
