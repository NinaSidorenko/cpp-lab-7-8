
/*prog: main.o bankaccount.o checkingaccount.o customer.o savingsaccount.o transaction.o
		g++ main.o bankaccount.o checkingaccount.o customer.o savingsaccount.o transaction.o -o prog

main.o: main.cpp
		g++ -c main.cpp -o main.o

bankaccount.o: bankaccount.cpp
		g++ -c bankaccount.cpp -o bankaccount.o

checkingaccount.o: checkingaccount.cpp
		g++ -c checkingaccount.cpp -o checkingaccount.o

customer.o: customer.cpp
		g++ -c customer.cpp -o customer.o

savingsaccount.o: savingsaccount.cpp
		g++ -c savingsaccount.cpp -o savingsaccount.o

transaction.o: transaction.cpp
		g++ -c transaction.cpp -o transaction.o

clean:
		rm main.o bankaccount.o checkingaccount.o customer.o savingsaccount.o transaction.o
