all: main

main: main.cpp Entity.cpp Wallet.cpp Client.cpp Transact.cpp TransactNode.cpp TransactList.cpp ClientBTS.cpp
	g++ main.cpp Entity.cpp Wallet.cpp Client.cpp Transact.cpp TransactNode.cpp TransactList.cpp ClientBTS.cpp -o main 

run: main
	main.exe

clean:
	rm -f main.exe	
