if [ ! -d "$3" ]; then
	echo "$3 doesn't exist, running mkdir"
	mkdir "$3"
fi

cp -r $1/* $3
echo "All $1 files copied to $3"
cp -r $2/* $3
echo "All $2 files copied to $3"
ls "$3"

