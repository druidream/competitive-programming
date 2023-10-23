echo -n "Please enter a filename: "
read filename
mkdir ${filename}
cd ${filename}
# touch main.cpp
sed -i '' 's/solve/'${filename}'/g' ~/Developer/competitive-programming/cpp/cpp/main.cpp
cp ~/Developer/competitive-programming/cpp/cpp/main.cpp .
sed -i '' 's/'${filename}'/solve/g' ~/Developer/competitive-programming/cpp/cpp/main.cpp
touch input.txt
touch output.txt
# cd ..