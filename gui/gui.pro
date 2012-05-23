TEMPLATE = app
TARGET = NetDNK
QT += core \
    gui \
    sql
HEADERS += typedefs.h \
    MainWindow.h \
    GraphicNode.h \
    GraphWidget.h \
    GraphicEdge.h \
    ../core/model/node_status.h \
    ../core/model/position.h \
    ../core/service/network_service.h \
    ../core/service/network_status_service.h \
    ../core/service/user_service.h \
    ../core/model/enums.h \
    ../core/model/graph.h \
    ../core/model/node.h \
    ../core/model/user.h
SOURCES += MainWindow.cpp \
    ../core/model/graph.cpp \
    ../core/model/node.cpp \
    ../core/model/node_status.cpp \
    ../core/model/position.cpp \
    ../core/model/user.cpp \
    ../core/service/network_service.cpp \
    ../core/service/network_status_service.cpp \
    ../core/service/user_service.cpp \
    ../core/test/network_service_test.cpp \
    ../core/test/user_service_test.cpp \
    GraphicEdge.cpp \
    GraphicNode.cpp \
    GraphWidget.cpp \
    main.cpp
RESOURCES += 
FORMS = 
