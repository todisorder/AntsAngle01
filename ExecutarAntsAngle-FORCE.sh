make -B&&
touch ./U_SoPaNaoChatearComErrosDoRM.txt
rm U_*;

echo "Results folder name:"
read Folder
Version="01"
[ -d "$Folder" ] && rm -r "$Folder"
mkdir "$Folder"
cp antsangle"$Version"  "$Folder"
cp AntsAngle"$Version".cpp  "$Folder"/CPPAntsAngleUsado.cpp
cp plot-png.sh  "$Folder"
#cp plots-Mass.plt  "$Folder"
cd "$Folder"

./antsangle"$Version" &&
mkdir Plots
sh plot-png.sh &&
#gnuplot plots-Mass.plt
#cp ../LogsLast.txt .

[ ! -d ../LastResult ] && mkdir ../LastResult
touch ../LastResult/Paranaochatearcomerrosdorm.txt
rm -r ../LastResult/*
cp -r * ../LastResult/

echo "Done!"

#osascript -e 'tell app "System Events" to display dialog "Calculo terminado." with icon 1 with title "Calculo terminado." '
