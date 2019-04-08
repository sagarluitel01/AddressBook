output: main.o BSTree.o ContactInfo.o NameInfo.o Address.o Affiliates.o AddressBook.o
	g++ -std=c++11 main.o BSTree.o ContactInfo.o NameInfo.o Address.o Affiliates.o AddressBook.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

BSTree.o: BSTree.h Node.h Entry.h
	g++ -std=c++11 -c BSTree.cpp

ContactInfo.o: ContactInfo.h
	g++ -std=c++11 -c ContactInfo.cpp

NameInfo.o: NameInfo.h
	g++ -std=c++11 -c NameInfo.cpp

Address.o: Address.h
	g++ -std=c++11 -c Address.cpp

Affiliates.o: Affiliates.h
	g++ -std=c++11 -c Affiliates.cpp

AddressBook.o: AddressBook.h
	g++ -std=c++11 -c AddressBook.cpp

clean:
	rm *.o output
