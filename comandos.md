sudo su
echo 12 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio12/direction

while true; do
  echo 1 > /sys/class/gpio/gpio12/value
  sleep 1
  echo 0 > /sys/class/gpio/gpio12/value
  sleep 1
done