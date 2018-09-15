start_client_server(){
	echo "============== STARTING SERVER: $1 ============"
	# Here the & makes the script not to wait for
	#completion of the server script
	time ./server &
	echo "============== STARTING CLIENT: $1 ============"
	time ./client

}

#Script
start_client_server
