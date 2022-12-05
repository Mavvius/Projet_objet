#!/usr/bin/env bash


if (($# >= 2)); then
	maincpp=$1
	fichierC=${@:2}
	nom_executable="labo"

		
	g++ -std=c++17 -c $fichierC 
	g++ $maincpp -o $nom_executable *.o 
	./$nom_executable
	 
else
	echo ${@:2}
	echo "Pour que le run.sh fonctionne il faut le lancer de la sorte"
	echo "    ./run.sh main.cpp <tous les autres .cpp>"
fi
