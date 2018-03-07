/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input = "";
	string dart_number[3] = { "" };
	string dart_string[3] = { "" };
	int dart_number_result[3] = { 0 };
	int dart_number_index = 0;
	int dart_string_index = 0;
	int result = 0;

	cin >> input;

	input += "0";

	for (int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]))
		{
			if (isdigit(input[i + 1]))
			{
				dart_number[dart_number_index] += input[i];
				dart_number[dart_number_index] += input[i + 1];
				dart_number_index++;
				i++;
			}
			else
			{
				dart_number[dart_number_index] += input[i];
				dart_number_index++;
			}
		}

		else
		{
			if (isdigit(input[i + 1]))
			{
				dart_string[dart_string_index] += input[i];
				dart_string_index++;

				if (i+2 == input.length())
					break;
			}
			else
			{
				dart_string[dart_string_index] += input[i];
				dart_string[dart_string_index] += input[i + 1];
				dart_string_index++;
				i++;

				if (i + 2 == input.length())
					break;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < dart_string[i].length(); j++)
		{
			switch (dart_string[i][j])
			{
			case 'S':
				dart_number_result[i] = pow(stoi(dart_number[i]), 1);
				break;
			case 'D':
				dart_number_result[i] = pow(stoi(dart_number[i]), 2);
				break;
			case 'T':
				dart_number_result[i] = pow(stoi(dart_number[i]), 3);
				break;
			case '*':
				if (i == 0)
					dart_number_result[i] *= 2;
				else
				{
					dart_number_result[i] *= 2;
					dart_number_result[i - 1] *= 2;
				}
				break;
			case '#':
				dart_number_result[i] *= -1;
				break;
			}
		}
	}

	for (int i = 0; i < 3; i++)
		result += dart_number_result[i];

	for (int i = 0; i < 3; i++)
		cout << dart_number[i]  << dart_string[i] << endl;

	cout << result << endl;

	return 0;
}