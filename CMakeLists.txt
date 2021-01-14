cmake_minimum_required(VERSION 3.17)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ft_printf
        ft_checkers.c
        ft_print_ptr.c
        ft_print_upx.c
        ft_printchar.c
        ft_printf.c
        ft_printf.h
        ft_printhex.c
        ft_printnum.c
        ft_printpercent.c
        ft_printstr.c
        ft_printunsigned.c
        libsfunc.c
        libsfuncs.c
        main.c
        utils.c)
