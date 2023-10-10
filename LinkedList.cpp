#include <iostream>
#include <string>
#include <variant>
#include "Sci_Calcu.h"

doublyLinkedList::doublyLinkedList(): head(nullptr) {}

void doublyLinkedList::insertValue(variant<string,float> val){
    Node* tmpNode = new Node;
        tmpNode->value = val;
        tmpNode->next = nullptr;
        tmpNode->previous = nullptr;

         if(head == nullptr){
            head = tmpNode;
        } else{
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = tmpNode;
            tmpNode->previous = temp;
        }
}

void doublyLinkedList::deleteNode(int val){
     Node* currentNode = head;
        int currentPosition = 0;

        while (currentNode != nullptr && currentPosition < val) {
            currentNode = currentNode->next;
            currentPosition++;
        }

        if (currentNode == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        if (currentNode->previous != nullptr) {
            currentNode->previous->next = currentNode->next;
        }

        if (currentNode->next != nullptr) {
            currentNode->next->previous = currentNode->previous;
        }

        if (currentNode == head) {
            head = currentNode->next;
        }

        delete currentNode;
}

void doublyLinkedList::replaceValue(int position, variant<string, float> val){
     Node* currentNode = head;
        int currentPosition = 0;

        while (currentNode != nullptr && currentPosition < position) {
            currentNode = currentNode->next;
            currentPosition++;
        }
        if (currentNode == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        currentNode->value = val;
}

void doublyLinkedList::print(float val){
    Node* go = head;
        for (float i = 0; i < val; i++){go = go->next;}
        if (go->value.index() == 0) {
                cout << get<string>(go->value) << endl;
            } else {
                cout << get<float>(go->value) << endl;
            }
}

void doublyLinkedList::printAll(){
    Node* go = head;
        cout << "The elements are: " << endl;
        while (go != nullptr) {
            cout <<"Index is: "<< go->value.index() << endl;
            if (go->value.index() == 0) {
                cout << get<string>(go->value) << endl;
            } else {
                cout << get<float>(go->value) << endl;
            }
            go = go->next;
        }
        cout << endl;
}

int doublyLinkedList::checkSize(){
    Node* go = head;
        int i=0;
        while (go != nullptr) {
            i++;
            go = go->next;
        }
        return i;
}

int doublyLinkedList::checkValue(int val){
     Node* go = head;
        for (int i = 0; i < val; i++){go = go->next;}
            return go->value.index();
}

string doublyLinkedList::getString(int val){
     Node* go = head;
        for (int i = 0; i < val; i++) {
            if (go == nullptr) {
                return "";
            }
            go = go->next;
        }
        if (go != nullptr) {
            return get<string>(go->value);
        }
        return "";
}

float doublyLinkedList::getFloat(int val){
    Node* go = head;
        for (int i = 0; i < val; i++) {
            if (go == nullptr) {
                return NAN;
            }
            go = go->next;
        }
        if (go != nullptr) {
            return get<float>(go->value);
        }
        return NAN;
}

