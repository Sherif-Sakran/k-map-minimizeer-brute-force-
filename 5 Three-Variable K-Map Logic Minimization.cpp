#include <iostream>
using namespace std;
#include <vector>
int main() {

	int x, arr[8] = { 0 },count=0;
	cout << "Enter the minterms of the funciton\n";
	cout << "*enter -1 when you finish\n";
	cout << "For example, the input 0 1 2 3 5 -1 represents the function m(0,1,2,3,5)\n";

	vector <string> farr;
	string f="";

	do
	{
		cin >> x;
		while (x < -1 || x>7)
		{
			cout << "Invalid input\n";
			cout << "re-enter the minterm\n";
			cin >> x;
		}	
		if (x == -1)
			break;
		arr[x] = 1;
		count++;
	} while (x != -1||count<9);
	
	cout << endl << endl;
	cout << "K-map=\n";

	cout << arr[0] << "\t\t" << arr[1] << "\t\t" << arr[3] << "\t\t" << arr[2] << "\t\t" << endl;
	cout << arr[4] << "\t\t" << arr[5] << "\t\t" << arr[7] << "\t\t" << arr[6] << "\t\t" << endl;



	if (arr[0] && arr[1] && arr[2] && arr[3] && arr[4] && arr[5] && arr[6] && arr[7])
	{
		f = "Tautology\n";
		return 0;
	}
	
	//rows
	if (arr[0] && arr[1] && arr[3] && arr[2])
	{
		farr.push_back("A'");
	}
	if (arr[4] && arr[5] && arr[7] && arr[6])
	{
		farr.push_back( "A");
	}
	//squares
	if (arr[0] && arr[3] && arr[4] && arr[7])
	{
		farr.push_back("C'");
	}

	if (arr[0] && arr[1] && arr[4] && arr[5])
	{
		farr.push_back("B'");
	}

	if (arr[1] && arr[3] && arr[4] && arr[7])
	{
		farr.push_back("C");
	}

	if (arr[2] && arr[3] && arr[7] && arr[6])
	{
		farr.push_back("B");
	}

	//Horizontal twos

	if (arr[0] && arr[2])
		farr.push_back("A'C'");


	if (arr[0] && arr[1])
		farr.push_back("A'B'");

	if (arr[1] && arr[3])
		farr.push_back("A'C");

	if (arr[3] && arr[2])
		farr.push_back("A'B");

	
	if (arr[4] && arr[6])
		farr.push_back("AC'");
	if (arr[4] && arr[5])
		farr.push_back("AB'");

	if (arr[5] && arr[7])
		farr.push_back("AC");

	if (arr[6] && arr[7])
		farr.push_back("AB");
	
	//Vertical twos
	if (arr[0]&&arr[4])
		farr.push_back("B'C'");
	if (arr[1] && arr[5])
		farr.push_back("B'C");
	if (arr[3] && arr[7])
		farr.push_back("BC");
	if (arr[2] && arr[6])
		farr.push_back("BC'");
	//ones
	if(arr[0])
		farr.push_back("A'B'C'");
	if (arr[1])
		farr.push_back("A'B'C");
	if (arr[2])
		farr.push_back("A'BC'");
	if (arr[3])
		farr.push_back("A'BC");
	if (arr[4])
		farr.push_back("AB'C'");
	if (arr[5])
		farr.push_back("AB'C");
	if (arr[6])
		farr.push_back("ABC'");
	if (arr[7])
		farr.push_back("ABC");
	vector <string>::iterator it = farr.begin();
	//for (int i = 0; i < farr.size(); i++)
	//	cout << farr.at(i) << "\t";
	//cout << endl << endl;

	for (int i = 0; i < farr.size()-1; i++)
	{
		//cout << "minterm: "<<farr[i] << endl;
		for (int j = i+1; j < farr.size(); j++)
		{
			//cout << "size: "<<farr.size()<<endl;
			if (farr[j].find(farr[i]) < 10 && farr[j].find(farr[i]) >= 0)
			{
				//cout << "deleted: "<<farr.at(j)<<endl;
				farr.erase(it + j);
				j--;
				//cout << "new_size: " << farr.size() << endl;
			}

		}
	}
	cout << "F = ";
	for (int i = 0; i < farr.size() - 1; i++)
		cout << farr.at(i)<<" + ";
	cout <<farr.at(farr.size()-1);

	return 0;
}