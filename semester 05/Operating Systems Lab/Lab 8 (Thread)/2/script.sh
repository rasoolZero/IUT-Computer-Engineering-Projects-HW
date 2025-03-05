./server &
for((i=0;i<$3;i++))
do
    xterm -e ./client $1 $2 &
done
