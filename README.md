# Stratum-MTP
Yiimp Stratum dedicated to MTP implementation of ZCoin

!!! DEV First version !!!

# Done and untested

01 - mtp algo in stratum (mtp_hash)
02 - include bos-jansson lib 

# To be implemented

01 - mining.subscribe - After connecting the client will send the mining.subscribe message.
02 - mining.authorize - The client should authorize itself using the mining.authorize message.
03 - mining.set_target - The server will set the miners share target using the mining.set_target message.
04 - mining.notify - The server will send the client mining.notify messages containing new and updated jobs.
05 - mining.submit - The client submits shares using the mining.submit message.

# Dev paused until

01 - Own a Graphic board with minimum 8GB ram to be able to test end to end implementation.

# Documentation references:
https://github.com/zcoinofficial/mtp-stratum-mining-protocol
