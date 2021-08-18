// This is a special object that converts the interface of one object so that another object can understand it.
// An adapter wraps one of the objects to hide the complexity of conversion happening behind the scenes.
// The wrapped object isn’t even aware of the adapter.

#include <iostream>
#include <memory>
using namespace std;

class IndianSocket {
	public:
	virtual void indianCharge(int) = 0;
};

class USASocket {
	public:
	void usaCharge() {
		cout << "USA plug is charging" << endl;
	}
};

class GermanySocket {
	public:
	void germanyCharge() {
		cout << "Germany plug is charging" << endl;
	}
};

class SocketAdapter : public IndianSocket, public USASocket, public GermanySocket {
	public:
	void indianCharge(int type) {
		switch(type) {
			case 1:
				usaCharge();
				break;
			case 2:
				germanyCharge();
				break;
		}
	}
};

int main() {
	unique_ptr<IndianSocket> socket = make_unique<SocketAdapter>();
	socket->indianCharge(1);
	socket->indianCharge(2);
	return 0;
}

o/p:
USA plug is charging
Germany plug is charging
