echo -n "Please enter a filename: "
read filename
mkdir ${filename}
cd ${filename}
# touch main.cpp
cp ~/Developer/competitive-programming/cpp/cpp/main.cpp .
touch input.txt
touch output.txt
# cd ..