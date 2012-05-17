#!/bin/bash

g++  core/model/*.cpp core/service/*.cpp util/add_user.cpp -o ncr_add_user
g++  core/model/*.cpp core/service/*.cpp util/change_password.cpp -o ncr_ch_pswd
g++  core/model/*.cpp core/service/*.cpp util/delete_user.cpp -o ncr_delete_user
g++  core/model/*.cpp core/service/*.cpp util/add_point.cpp -o ncr_add_point
g++  core/model/*.cpp core/service/*.cpp util/view_point.cpp -o ncr_view_point

