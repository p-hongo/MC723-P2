#!/bin/bash

echo -e ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>dijkstra small\n" >> resultados.txt
{ ./mips1.x --load=dijkstra/bin/dijkstra_small dijkstra/input/input.dat > /dev/null; } 2>> resultados.txt
echo -e "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>dijkstra large\n" >> resultados.txt
{ ./mips1.x --load=dijkstra/bin/dijkstra_large dijkstra/input/input.dat > /dev/null; } 2>> resultados.txt

echo -e "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>qsort small\n" >> resultados.txt
{ ./mips1.x --load=qsort/bin/qsort_small qsort/input/input_small.dat > /dev/null; } 2>> resultados.txt
echo -e "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>qsort large\n" >> resultados.txt
{ ./mips1.x --load=qsort/bin/qsort_large qsort/input/input_large.dat > /dev/null; } 2>> resultados.txt

echo -e "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>patricia small\n" >> resultados.txt
{ ./mips1.x --load=patricia/bin/patricia patricia/input/small.udp > /dev/null; } 2>> resultados.txt
echo -e "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>patricia large\n" >> resultados.txt
{ ./mips1.x --load=patricia/bin/patricia patricia/input/large.udp > /dev/null; } 2>> resultados.txt
