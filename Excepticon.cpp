#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

void Func(int val)
{
	cout << val;
}

int main()
{

	try {
		//Implement your code
		Func(2.35l);
	}
	catch(bad_exception be)
	{
		cout << be.what();
	}
	catch(underflow_error ue)
	{
		cout << ue.what();
	}
	catch(overflow_error oe)
	{
		cout << oe.what();
	}
	catch(invalid_argument ia) {
		cout << ia.what();
	}
	catch (length_error le) {
		cout << le.what();
	}
	catch (out_of_range oor) {
		cout << oor.what();
	}
	catch (runtime_error re) {
		cout << re.what();
	}
	catch (logic_error lo) {
		cout << lo.what();
	}
	catch (exception ex) {
		cout << ex.what();
	}
	return 0;
}
