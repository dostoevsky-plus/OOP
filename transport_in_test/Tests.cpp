#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Program/pch.h"
#include "../Program/pch.cpp"
#include <fstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{	
	TEST_CLASS(Test_Out)
	{
	public:
		TEST_METHOD(OutCommon_test)
		{
			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			transport *test = transport::In(ifst);
			ofstream ofst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\fileout.txt");

			test->OutCommon(ofst);
			string test_string;
			ifstream iffst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\fileout.txt");
			
			getline(iffst, test_string);
			string expected_string = ", ���������� ����� �������� = 150, �������� = 25";
			Assert::AreEqual(expected_string, test_string);
			
		};
		TEST_METHOD(Outplane_test)
		{
			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			transport *test = transport::In(ifst);
			ofstream ofst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\fileout.txt");
			test->Out(ofst);
			string test_string;
			ifstream iffst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\fileout.txt");

			getline(iffst, test_string);
			string expected_string = "It is Plane: ���������������� = 1000, ��������� ������ = 1, ���� � ������ ������ = 187, ���������� ����� �������� = 150, �������� = 25";
			Assert::AreEqual(expected_string, test_string);

		};
		TEST_METHOD(Outtraine_test)
		{
			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			transport *test = transport::In(ifst);
			test = transport::In(ifst);
			ofstream ofst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\fileout.txt");
			test->Out(ofst);
			string test_string;
			ifstream iffst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\fileout.txt");

			getline(iffst, test_string);
			string expected_string = "It is Traine: count = 30, ���������� ����� �������� = 8000, �������� = 80";
			Assert::AreEqual(expected_string, test_string);

		};
		TEST_METHOD(Outship_test)
		{
			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			transport *test = transport::In(ifst);
			test = transport::In(ifst);
			test = transport::In(ifst);
			test = transport::In(ifst);
			ofstream ofst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\fileout.txt");
			test->Out(ofst);
			string test_string;
			ifstream iffst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\fileout.txt");

			getline(iffst, test_string);
			string expected_string = "It is Ship: ������������� = 3, ��� ����� = TANKER, ���������� ����� �������� = 700, �������� = 700";
			Assert::AreEqual(expected_string, test_string);

		};
		TEST_METHOD(Container_out_test)
		{
			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			container test;
			test.In(ifst);
			ofstream ofst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\fileout.txt");
			test.Out(ofst);

			string expected_string = " Container contains 4 elements.";
			//expected_string=expected_string+'\n';
			string test_string;
			ifstream iffst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\fileout.txt");
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			
			expected_string ="0: It is Plane: ���������������� = 1000, ��������� ������ = 1, ���� � ������ ������ = 187, ���������� ����� �������� = 150, �������� = 25";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "��������� ����� ���� = 6";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "1: It is Traine: count = 30, ���������� ����� �������� = 8000, �������� = 80";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "��������� ����� ���� = 100";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "2: It is Plane: ���������������� = 1000, ��������� ������ = 15000, ���� � ������ ������ = 900, ���������� ����� �������� = 1500, �������� = 2500";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "��������� ����� ���� = 0.6";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "3: It is Ship: ������������� = 3, ��� ����� = TANKER, ���������� ����� �������� = 700, �������� = 700";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "��������� ����� ���� = 1";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			//test_string = test_string + '\n' +"��������� ����� ���� = 6"
				/*1 : It is Traine : count = 30, ���������� ����� �������� = 8000, �������� = 80
				��������� ����� ���� = 100
				2 : It is Plane : ���������������� = 1000, ��������� ������ = 15000, ���� � ������ ������ = 900, ���������� ����� �������� = 1500, �������� = 2500
				��������� ����� ���� = 0.6
				3 : It is Ship : ������������� = 3, ��� ����� = TANKER, ���������� ����� �������� = 700, �������� = 700
				��������� ����� ���� = 1"*/
		};
		TEST_METHOD(Out__only_plane_test)
		{
			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			container test;
			test.In(ifst);
			ofstream ofst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\fileout.txt");
			test.Out_only_plane(ofst);

			string expected_string = "Only planes";
			string test_string;
			ifstream iffst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\fileout.txt");
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);


			expected_string = "0: It is Plane: ���������������� = 1000, ��������� ������ = 1, ���� � ������ ������ = 187, ���������� ����� �������� = 150, �������� = 25";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "��������� ����� ���� = 6";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "1: ";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);
			
			expected_string = "2: It is Plane: ���������������� = 1000, ��������� ������ = 15000, ���� � ������ ������ = 900, ���������� ����� �������� = 1500, �������� = 2500";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "��������� ����� ���� = 0.6";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

			expected_string = "3: ";
			getline(iffst, test_string);
			Assert::AreEqual(expected_string, test_string);

		}

	};
	TEST_CLASS(Test_container_function)
	{
	public:
		TEST_METHOD(Castl_test)
		{
			container test;
			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			test.In(ifst); 
			test.get_Top()->castl();//������ �������
			float test_time = 100;
			Assert::AreEqual(test_time, test.get_Top()->data->Travel_time());
		};
		TEST_METHOD(Sort_test)
		{
			container test;
			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			test.In(ifst);
			test.Sort();
			//Node* test_Node = test.get_Top;
			//test.get_Top()->Processsort(test_Node);
			float test_time = 100;
			Assert::AreEqual(test_time, test.get_Top()->data->Travel_time());
			test_time = 6;
			Assert::AreEqual(test_time, test.get_Top()->Next->data->Travel_time());
			test_time = 1;
			Assert::AreEqual(test_time, test.get_Top()->Next->Next->data->Travel_time());
			test_time = 0.6;
			Assert::AreEqual(test_time, test.get_Top()->Next->Next->Next->data->Travel_time());
		}

	};
	TEST_CLASS(Test_transport_function)
	{
	public:

		TEST_METHOD(Travel_test)
		{
			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			transport *test = transport::In(ifst);
			test->set_distance(1000);
			test->set_spead(80);
			float time_test=12.5;
			Assert::AreEqual(time_test, test->Travel_time());
		};
		TEST_METHOD(Compare_test)
		{
			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			transport *test_1 = transport::In(ifst);
			transport *test_2 = transport::In(ifst);
			test_1->set_distance(1000);
			test_1->set_spead(8);
			test_2->set_distance(1000);
			test_2->set_spead(10);
			bool compare_test = 0;
			Assert::AreEqual(compare_test, test_1->Compare(*test_2));
		}
	};

	TEST_CLASS(Tests_In)
	{
	public:
		
		TEST_METHOD(transport_in)
		{
			int distance_test = 150;
			int spead_test = 25;
			int c_test = 1000;
			int range_test = 1;
			int cargo_test = 187;


			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			transport *test = transport::In(ifst);
			Assert::AreEqual(distance_test, test->get_distance());
			Assert::AreEqual(spead_test, test->get_spead());
			Assert::AreEqual(to_string(c_test) + to_string(range_test) + to_string(cargo_test), test->getall());
			// TODO: ���������� ����� ��� ������ �����
		};

		TEST_METHOD(plane_in)
		{
			int c_test = 1000;
			int range_test = 1;
			int cargo_test = 187;
			int key;

			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			ifst >> key;
			plane test;
			test.InData(ifst);
			Assert::AreEqual(to_string(c_test) + to_string(range_test) + to_string(cargo_test), test.getall());

		};
		TEST_METHOD(traine_in)
		{
			int count_test = 1000;
			int key;

			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			ifst >> key;
			traine test;
			test.InData(ifst);
			Assert::AreEqual(to_string(count_test), test.getall());

		};
		TEST_METHOD(ship_in)
		{
			int water_displacement_test = 1000;
			int type_test = LINER;
			int key;

			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			ifst >> key;
			ship test;
			test.InData(ifst);
			Assert::AreEqual(to_string(water_displacement_test)+to_string(type_test), test.getall());
		};
		TEST_METHOD(container_in)
		{
			int count_test = 4;
			ifstream ifst("C:\\Users\\���������\\Desktop\\Github\\��� ����������\\1�������\\Program\\transport_in_test\\filein.txt");
			container test;
			test.In(ifst);
			Assert::AreEqual(count_test, test.get_count());
		}


	};
}