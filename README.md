# faceResearch
библиотки:
opencv 3.2
dlib 19.7
boost 1.59
tbb 2018_20171205oss

openface v.2.1

Изменения в config tbb, в cmake dlib

сборка cmakelist CMake 3.9.6

собрать через Cmake 3.9.6 в папку build в той же директории, в проекте CLR добавить параметр "с поддержкой CLR среды" в общие, поставить точку входа Main в точка входа в компоновщике, убрать директроию выхода /Release в местоположения листинга ASM в C/C++, добавть параметр Windows(/SUBSYSTEM:WINDOWS) в подсистема в компоновщике

для сборки dlib в debag комментировать строчки #define DLIB_USE_BLAS #define DLIB_USE_LAPACK, добавить в препороцессор dlib при сборке в debug ENABLE_ASSERTS

убрать лишние .lib из компановщиков exe проектов

собирать с библиотекой Intel MKL

для приложения эмоции нужны картинки,файл с дескрипоторами и папка с фото