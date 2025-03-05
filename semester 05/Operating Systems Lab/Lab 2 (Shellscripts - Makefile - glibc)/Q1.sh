mkdir "$1"
for ((i="$3";i<="$4";i++));
do
	name="$1/$i"."$2"
	echo $name
	touch $name
done
