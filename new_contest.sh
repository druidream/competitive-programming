read -p "Please enter a contest name: " contest_name
mkdir ${contest_name}
cd ${contest_name}

source_file="/Users/jun/Developer/competitive-programming/cpp/cpp/main.cpp"

for letter in a b c d e; do
	subfolder_name="$contest_name$letter"
	mkdir "$subfolder_name"
	destination_file="$subfolder_name/main.cpp"
	cp "$source_file" "$destination_file"
	sed -i '' 's/placeholder/'${subfolder_name}'/g' "$destination_file"
	touch "$subfolder_name/$subfolder_name.in"
	touch "$subfolder_name/$subfolder_name.out"
done
echo "\xE2\x9C\x93\xE2\x9C\x93\xE2\x9C\x93 New contest $contest_name created successfully."