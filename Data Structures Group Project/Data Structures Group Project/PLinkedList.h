#include "PNode.h"
using namespace std;

class PLinkedList {
private:
	PNode* head;
public:
	PLinkedList() {
		head = NULL;
	}
	void append(int playerNum, string playerName, float grandTotal) {
		if (head == NULL) {
			head = new PNode(playerNum, playerName, grandTotal);
			return;
		}
		PNode* current = head;
		while (current->getNext() != NULL) {
			current = current->getNext();
		}
		current->setNext(new PNode(playerNum, playerName, grandTotal));
	}
    void deleteNode(int position)
    {
        if (head == NULL)
            return;
        PNode* temp = head;
        if (position == 0)
        {
            head = temp->getNext();
            return;
        }
        for (int i = 0; temp != NULL && i < position - 1; i++)
            temp = temp->getNext();
        if (temp == NULL || temp->getNext() == NULL)
            return;
        PNode* next = temp->getNext()->getNext();
        temp->setNext(next);
    }
    void insertNth(int playerNum, string playerName, float grandTotal, int position) {
        //create new node.
        PNode* node = new PNode(playerNum,playerName,grandTotal);
        node->setNext(NULL);

        if (head == NULL) {
            //if head is null and position is zero then exit.
            if (position != 0) {
                return;
            }
            else { //node set to the head.
                head = node;
            }
        }
        if (head != NULL && position == 0) {
            node->setNext(head);
            head = node;
            return;
        }

        PNode* current = head;
        PNode* previous = NULL;

        int i = 0;

        while (i < position) {
            previous = current;
            current = current->getNext();

            if (current == NULL) {
                break;
            }

            i++;
        }

        node->setNext(current);
        previous->setNext(node);
    }
	void display() {
		PNode* temp = new PNode;
		temp = head;
		while (temp != NULL) {
			temp->getdata();
			temp = temp->getNext();
		}
	}

};