// pch.cpp: исходный файл, соответствующий предкомпилированному заголовку; нужен для компиляции

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;
	void plane::InData(ifstream &ifst) {
		ifst >> c  >> range ;
	}
	void traine::InData(ifstream &ifst) {
		ifst >> count ;
	}
	void plane::Out(ofstream &ofst) {
		ofst << "It is Plane: грузоподъемность = " << c
			<< ", дальность полета = " << range;
		OutCommon(ofst);

	}
	void plane::MultiMethod(transport * other, ofstream & ofst)
	{
		other->MMplane(ofst);
	}
	void plane::MMplane(ofstream & ofst)
	{
		ofst << "Plane and Plane" << endl;
	}
	void plane::MMtraine(ofstream & ofst)
	{
		ofst << "Traine and Plane" << endl;
	}
	void traine::MultiMethod(transport*other, ofstream & ofst)
	{
		other->MMtraine(ofst);
	}
	void traine::MMplane(ofstream & ofst)
	{
		ofst << "Plane and Traine" << endl;
	}
	void traine::MMtraine(ofstream & ofst)
	{
		ofst << "Traine and Traine" << endl;
	}
	void traine::Out(ofstream &ofst) {
		ofst << "It is Traine: count = " << count ;
		OutCommon(ofst);
	}
	transport* transport::In(ifstream &ifst)
	{
		transport *s;
		int key;
		ifst >> key;
		if (key == 1) {
			s = new plane;
		}
		else if (key == 2)
		{
			s = new traine;
		}
		else
		return 0;
		s->InData(ifst);
		ifst >> s->distance >> s->spead;
		return s;
	}
	void transport::OutCommon(ofstream & ofst)
	{
		ofst << ", расстояние между пунктами = " << distance << ", скорость = " << spead << endl;
	}
	container::Node::Node()
	{
		this->Next = nullptr;
		this->Prev = nullptr;
		this->data = nullptr;
	}
	
	container::container()
	{
		Top = nullptr;
		count = 0;
	}
	void container::Clear()
	{
		Node* current = Top;
		for (int i = 1; i < count; i++)
		{
			current = current->Next;
			delete current->Prev;
		}
		delete current;
		count = 0;
	}
	void container::MultiMethod(ofstream & ofst)
	{
		ofst << "Multimethod." << endl;
		Node* current_i = Top;
		for (int i = 0; i < count - 1; i++) {
			Node* current_j = current_i->Next;
			for (int j = i + 1; j < count; j++) {
				current_i->data->MultiMethod(current_j->data, ofst);
				current_i->data->Out(ofst);
				current_j->data->Out(ofst);
				current_j = current_j->Next;
			}
			current_i = current_i->Next;
		}
	}
	void container::In(ifstream & ifst)
	{
		int flag;
		while (!ifst.eof()) {
			if (count == 0)
			{
				Top = new Node;
				Top->Next = Top;
				Top->Prev = Top;
				if ((Top->data= transport::In(ifst)) != 0)
					flag = 1;
				else
					flag = 0;
				
			}
			else
			{
				Node *current = Top;
				for (int j = 1; j < count; j++)
				{
					current = current->Next;
				}
				current->Next = new Node;
				if ((current->Next->data = transport::In(ifst)) != 0)
				{
					Top->Prev = current->Next;
					current->Next->Prev = current;
					current->Next->Next = Top;
					flag = 1;
				}
				else
				{
					flag = 0;
				}
			}
			if (flag  != 0)
				count++;
		}
	}

	void container::Out(ofstream & ofst)
	{
		Node* current = Top;
		ofst << " Container contains " << count
			<< " elements." << endl;
		for (int j = 0; j < count; j++) {
			ofst << j << ": ";
			current->data->Out(ofst);
			current = current->Next;
		}
	}

// В целом этот файл можно пропустить, но не удаляйте его, если вы используете предкомпилированные заголовки.
	