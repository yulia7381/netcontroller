TEMPLATE = app
TARGET = NetDNK
QT += core \
    gui \
    sql
HEADERS += GraphicNode.h \
    GraphWidget.h \
    GraphicEdge.h \
    ../core/model/node_status.h \
    ../core/model/position.h \
    ../core/service/network_service.h \
    ../core/service/network_status_service.h \
    ../core/service/user_service.h \
    ../core/model/enums.h \
    ../core/model/graph.h \
    ../core/model/link.h \
    ../core/model/node.h \
    ../core/model/user.h
SOURCES += GraphicNode.cpp \
    GraphWidget.cpp \
    GraphicEdge.cpp \
    ../core/model/node_status.cpp \
    ../core/model/position.cpp \
    ../core/service/network_service.cpp \
    ../core/service/network_status_service.cpp \
    ../core/service/user_service.cpp \
    ../core/model/graph.cpp \
    ../core/model/link.cpp \
    ../core/model/node.cpp \
    ../core/model/user.cpp \
    main.cpp
RESOURCES +=
FORMS = 
