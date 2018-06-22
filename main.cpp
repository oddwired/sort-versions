#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> versions = {
			"1.1.2",
			"1.0",
			"1.3.3",
			"1.0.12",
			"1.0.2",
			"2.0",
			"15.45",
			"15.09",
			"0.0",
			"1",
			"0",
			"0.0",
			"2.0.1",
			"2.1.2",
			"0.1.2",
			"0.1"
		};

int getPart(string value,int part){
    vector<int> parts;
    string part_value;
    istringstream val(value);
    while(getline(val, part_value, '.')){
        if(!part_value.empty()){
            parts.push_back(stoi(part_value));
        }
    }

    if(parts.size() - 1 < part){
        return 0;
    }else{
        return parts[part];
    }
}

bool isGreater(string value1, string value2){
    int value1_1 = getPart(value1, 0),
        value1_2 = getPart(value1, 1),
        value1_3 = getPart(value1, 2);

    int value2_1 = getPart(value2, 0),
        value2_2 = getPart(value2, 1),
        value2_3 = getPart(value2, 2);

    if(value1_1 > value2_1){
        return true;
    }else if(value1_1 == value2_1
             && value1_2 > value2_2){
        return true;
    }else if(value1_1 == value2_1
             && value1_2 == value2_2
             && value1_3 > value2_3){
        return true;
    }else if(value1_1 == value2_1
             && value1_2 == value2_2
             && value1_3 == value2_3
             && value1.length() > value2.length()){
        return true;
    }else{
        return false;
    }
}

vector<string> sort(vector<string> unsorted){
    string current_value;
    int j;
    //int total_size = sizeof(unsorted);
    //cout << total_size << endl;
    for(int i = 0; i < unsorted.size(); i++){
        current_value = unsorted[i];
        j = i - 1;

        while(j >= 0 && isGreater(unsorted[j], current_value)){
            unsorted[j + 1] = unsorted[j];
            j--;
        }

        unsorted[j + 1] = current_value;
    }

    return unsorted;
}

int main()
{
    vector<string> sorted = sort(versions);

    for(int i = 0; i < sorted.size(); i++){
        cout << sorted[i] << endl;
    }
    return 0;
}
