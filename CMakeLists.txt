cmake_minimum_required(VERSION 3.0.0)
project(noddy VERSION 1.0.0)

set(protect_src protect.cpp protect.def)
add_library(protect SHARED ${protect_src})