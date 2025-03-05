if [ $1 == "-r" ]; then
	cat "$2"
fi
if [ $1 == "-m" ]; then
	for((i="$5";i<="$6";i++));
	do
		name="$2$3"_"$i"."$4"
		echo $name
		touch "$name"
	done
fi
