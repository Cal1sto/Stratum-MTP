
#!/bin/bash
ulimit -n 10240
ulimit -u 10240
cd /var/stratum
while true; do
        ./stratum-mtp /var/stratum/config/$1
        sleep 2
done
exec bash

