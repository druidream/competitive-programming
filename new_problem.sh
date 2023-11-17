# problem name should be like: cf1900a, abc321a
read -p "Please enter a problem name: " problem_name
mkdir $problem_name
home_dir=$(eval echo ~)
source_file="$home_dir/Developer/competitive-programming/cpp/cpp/main.cpp"
destination_file="$problem_name/_main.cpp"
cp "$source_file" "$destination_file"
sed -i '' 's/placeholder/'${problem_name}'/g' "$destination_file"
touch "$problem_name/$problem_name.in"
touch "$problem_name/$problem_name.out"
echo "\xE2\x9C\x93 New problem $problem_name created successfully."
# https://stackoverflow.com/questions/525592/find-and-replace-inside-a-text-file-from-a-bash-command