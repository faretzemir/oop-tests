#include <iostream>
#include <string>
using namespace std;

class Counter {

private:
	int m_count; // counter value
	int m_stepSize;
	
public:
	Counter() { m_count = 0; m_stepSize = 1; }
	Counter(int count, int stepSize); // 1 mark (DONE)
	int getCount(); // 1 mark (DONE)
	void setCounter(int count, int step); // 1 mark (DONE)
	void getData(int& count, int& stepSize); //1 mark (DONE)
	void incrementCount(); // increment by 1 // 1 mark (DONE)
	void incrementCount(int step); // 1 mark (DONE)
	int getMaxCountValue(int threshold, int step); // 2 marks (DONE)
	static int getTotalCount(Counter* ptr, int numCounter); // 2 marks (DONE)
};

Counter::Counter(int count, int stepSize){
    m_count = count;
    m_stepSize = stepSize;
}

int Counter::getCount(){
    return m_count;
}

void Counter::setCounter(int count, int step){
    count = m_count;
    step = m_stepSize;
}

void Counter::getData(int& count, int& stepSize){
    count = getCount();
    stepSize = m_stepSize;
}

void Counter::incrementCount(){
    m_count += m_stepSize;
    cout << "Increment count by " << m_stepSize;
}

void Counter::incrementCount(int step){
    m_count += step;
}

int Counter::getMaxCountValue(int threshold, int step){
    int k = 1;


    do{

		//incrementCount(step);
		m_count += k*step;
		cout << "Incremented count by " << step << endl;
		k++;
        
        
	}while(m_count<threshold);
        
	cout << "Incremented count by " << step << endl;
    cout << "Constraint satisfied at k = " << k << endl;
	return (m_count - 5);
}

int Counter::getTotalCount(Counter* ptr, int numCounter){
    int sum = 0;

    for (int i = 0; i < numCounter; i++){
        sum = sum + ptr[i].getCount();
    }

    return sum;

}

int main() {
	Counter c1(1, 2);
	int ctr, ss;
	c1.getData(ctr, ss);
	cout << "\nThe c1 counter value = " << ctr;
	cout << "\nThe c1 counter step size : " << ss;
	cout << endl;
	c1.incrementCount();
	cout << "\nUpdated c1 count value = " << c1.getCount() << endl;
	c1.incrementCount(10);
	cout << "\nUpdated c1 count value = " << c1.getCount();

	cout << endl << endl;

	cout << "  f(k)= 10 + k*5 , find maximum value of f(k) such that f(k) < 49 " << endl;
	Counter c2;
	c2.setCounter(10, 5);
	int maxV = 49;
	cout << "\n Maximum c2 count value f(k) below " << maxV << " = " << c2.getMaxCountValue(49, 5) << endl;

	Counter cArray[3];
	cArray[0] = Counter(1, 1);
	cArray[1] = Counter(5, 5);
	cArray[2] = Counter(10, 1);
	cout << "\n\nTotal count in cArray = " << Counter::getTotalCount(cArray, 3) << endl;

	cout << "Enter any key to escape." << endl;
	getchar();
	return 0;
}
