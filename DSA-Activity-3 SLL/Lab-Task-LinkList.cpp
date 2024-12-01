

#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int value) {
		data = value;
		next = nullptr;
	}
};
class LinkedList {
public:
	Node* head;
	LinkedList() {
		head = nullptr;
	}

	void insertAtHead(int value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
		cout << "Element Inserted At Head" << endl;
	}
	void insertAtTail(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* temp;
			temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
			cout << "Inserted at Tail" << endl;

		}	}
	void print() {
		Node* temp = head;
		
		while (temp != nullptr) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "Null" << endl;
		if (head == nullptr) {
			cout << "Empty List" << endl;
		}
	}
	void searchByValue(int key) {
		Node* temp = head;
		bool flag = false;
		while (temp != nullptr) {
			if (temp->data == key) {
				flag = true;
				break; // We can also use return but it will exit the function without printing the following statements
			}
			temp = temp->next;
		}
		if (!flag) {
			cout << "Element Not Found" << endl;
		}
		else if (flag) {
			cout << "Element Has Been Found" << endl;
		}
	}
	void updateValue(int old,int updated) {
		Node* temp = head;
		bool flag = false;
		while (temp != nullptr) {
			if (temp->data == old) {
				temp->data = updated;
				flag = true;
				break; // We can also use return but it will exit the function without printing the following statements
			}
			temp = temp->next;
		}
		if (!flag) {
			cout << "The list Don't Contain  "<<old<<" <- Value " << endl;
		}
		else if (flag) {
			cout << "Element Has Been Updated" << endl;
		}
		// We can use return on this line as it will print the statement
	}
	void countNodes() {
		Node* temp = head;
		int count = 0;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
			
		}
		cout << "The number of nodes are  : " << count << endl;
	}
	void updateValueByIndex(int index, int val) {
		Node* temp = head;
		int count = 1;
		bool flag = false;
		while (temp != nullptr) {
			if (count == index) {
				cout << "The value which is about to be changed is " << temp->data << endl;
				temp->data = val;
				cout << "The value at Index " << index << "  was changed To  " << val << endl;
				flag = true;
				break;
			}
			temp = temp->next;
			count++;
		}
		
		if (!flag) {
			cout << "Out of RAnge index" << endl;

		}
	}

	void deleteNode(int val) {
	
		if (head == nullptr) {
			cout << "nothing to delete " << endl;
			return;
		}
		if (head->data==val) {
			Node* del = head;
			head = head->next;
			delete del;
			return;
		}
		Node* temp = head;
	
		while (temp->next!=nullptr &&temp->next->data != val) {

			temp = temp->next;
		
		}
		if (temp->next == nullptr) {
			cout << "Element Not Found To Delete." << endl;
			return; // Add this line
		}
		Node* toDel = temp->next;
		temp->next = temp->next->next;
		
		delete toDel;
	}
	void insertbefore(int value, int newData) {
		if (head == nullptr) {
			cout << "Empty List Insertion Not possible" << endl;
			return;
		}
		if (head->data == value) {
			Node* newNode = new Node(newData);
			newNode->next = head;
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr && temp->next->data != value) {
			temp = temp->next;
		}
		if (temp->next == nullptr) {
			cout << "The Value You Provided Doesn't Exist" << endl;
			return;
		}
		Node* newNode = new Node(newData);
		newNode->next = temp->next;
		temp->next = newNode;

	}
	void insertAfter(int value, int newData) {
		if (head == nullptr) {
			cout << "Empty List Insertion Not possible" << endl;
			return;
		}
		if (head->data == value) {
			Node* newNode = new Node(newData);
			Node* temp = head;
			newNode->next = temp->next;
			temp->next = newNode;
			
			return;
		}
		Node* temp = head;
		while (temp != nullptr && temp->data != value) {
			temp = temp->next;
		}
		if (temp == nullptr) {
			cout << "The Value You Provided Doesn't Exist" << endl;
			return;
		}
		Node* newNode = new Node(newData);
		
			newNode->next = temp->next;
	
		temp->next = newNode;
	}
	void printMiddle() {
		if (head == nullptr) {
			cout << "Middle doest Exist" << endl;
			return;
		}
		int count = 0;
		int middle = 0;
		Node* temp = head;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		middle = (count-1) / 2; // To print Second middle use count/2
		temp = head;
		for (int i = 0; i < middle; i++) {
			temp = temp->next;
		}
		cout << "The Middle Value Is " << temp->data << endl;
	}
	void printAfter(int value) {
		if (head == nullptr) {
			cout << "Empty List " << endl;
			return;
		}
		Node* temp = head;
		while (temp != nullptr&&temp->data!=value) {
			temp = temp->next;
		}
		if (temp == nullptr) {
			cout << "The data Doest Exist" << endl;
			return;
		}
		cout << "The Value After Data : " << value << "  is  " << temp->next->data << endl;
	}
	void evenOddNodes() {
		if (head == nullptr) {
			cout << "Empty List " << endl;
			return;
		}
		Node* temp = head;
		int count = 1;
		while (temp != nullptr) {
			if (temp->data % 2 == 0) {
				cout << "The Node : " << count << " Is Even  :=: " << temp->data << endl;

			}
			else  {
				cout << "The Node : " << count << " Is Odd  :=: " << temp->data << endl;

			}
			count++;
			temp = temp->next;


		}

	}
	void deleteDuplicate() {
		bool flag = true;
		if (head == nullptr) {
			cout << "nothing to delete " << endl;
			return;
		}
		
		Node* temp = head;

		while (temp->next != nullptr ) {
			if (temp->next->data == temp->data) {
				Node* toDel = temp->next;
				temp->next = temp->next->next;
				flag = false;
				delete toDel;
			
			}
			else {
				temp = temp->next;
			}
		}
		if (flag) {
			cout << "Value Not Found " << endl;
		}
	}
	void deleteMiddle() {
		if (head == nullptr) {
			cout << "Middle doest Exist" << endl;
			return;
		}
		int count = 0;
		int middle = 0;
		Node* temp = head;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		middle = (count - 1) / 2; // To delete Second middle use count/2
		temp = head;
		int count2 = 0;
		while (temp->next != nullptr && count2 < middle-1) {
			count2++;
			temp = temp->next;

		}
		if (temp->next == nullptr) {
			cout << "Middle doest Exist" << endl;
			return;
		}
		Node* del = temp->next;
		temp->next = temp->next->next;
		delete del;


		}
	void deleteAtPosition(int p) {
		if (head == nullptr) {
			cout << "Empty List " << endl;
			return;
		}
		if (p < 1) {
			cout << "Invalid Node" << endl;
			return;
		}
		if (p == 1) {
			
			Node* del=head;
			head = head->next;
			delete del;
			return;
		}
		
		Node* temp = head;
		int count = 1;
		while (temp->next != nullptr && count < p-1) {
			count++;
			temp = temp->next;
		}
		if (temp==nullptr||temp->next == nullptr) {
			cout << "Out Of Range Index " << endl;
			return;
		}
		Node* del = temp->next;
		temp->next = del->next;
		delete del;
	}
	void deleteAfter(int value) {
		if (head == nullptr) {
			cout << "Empty List " << endl;
			return;
		}
		Node* temp = head;
		while (temp != nullptr && temp->data != value) {
			temp = temp->next;
		}
		if (temp == nullptr) {
			cout << "Data Dont Exist " << endl;
			return;

		}
		if (temp->next == nullptr) {

			cout << "There Are no Nodes After This Data " << endl;
			return;
		}
		Node* del = temp->next;
		temp->next = del->next;
		delete del;

	}
	void deletexxBefore(int value) {
		if (head == nullptr) {
			cout << "Empty List " << endl;
			return;
		}
		if (head->data == value) {
			cout << "Cannot delete before head" << endl;
			return;
		}
		if (head->next!=nullptr && head->next->data == value) {
			Node* del = head;
			head = head->next;
			delete del;
			return;
		}
		Node* temp = head;
		Node* prev = nullptr;
		while (temp->next != nullptr && temp->next->data != value) {
			prev = temp;
			temp = temp->next;
		}
		if (temp->next==nullptr) {
			cout << "Value Dont Exist" << endl;
			return;

		}
		if (prev != nullptr) {

			prev->next = temp->next;
			delete temp;
		}
		
		
		


	}
	void Reverse() {
		if (head == nullptr) {
			cout << "Empty List " << endl;
			return;
		}
		Node* prev = nullptr;
		Node* temp = head;
		Node* next = nullptr;
			while (temp != nullptr) {
				next = temp->next;
				temp->next = prev;
				prev = temp;
				temp = next;
			}
			head = prev;
			temp = head;
			while (temp!= nullptr) {
				cout << temp->data << "->";
				temp = temp->next;
			}
			cout << "null";



	}
};
int main()
{
	LinkedList L;
	L.insertAtHead(60);
	L.insertAtHead(70);
	L.insertAtTail(5);
	L.insertAtTail(20);
	L.print();
	L.insertbefore(5, 20);
	L.print();
	L.insertAfter(70, 60);
	L.print();
	L.printMiddle();
	L.printAfter(70);
	L.evenOddNodes();
	L.deleteDuplicate();
	L.print();
	L.deleteMiddle();
	L.print();
	cout << "Enter Node Postition Greater Than Zero To Delete : 1+" << endl;
	int p;
	cin >> p;
	L.deleteAtPosition(p);
	L.print();
	L.deleteAfter(20);
	L.print();
	L.deletexxBefore(20);
	L.print();
	L.Reverse();


	L.updateValue(70, 15); 
	L.searchByValue(15);   
	L.countNodes();       
	L.print();
	L.updateValueByIndex(3, 58);     
	L.print();
	L.deleteNode(15);           
	L.print();




}
